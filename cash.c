//Minimum number of coins possible
#include <cs50.h>
#include <math.h>
#include <stdio.h>

const int dollars_to_cents = 100;
const int quarter = 25;
const int dime = 10;
const int nickel = 5;
const int penny = 1;

void conversion(float dollars);
void no_of_coins(int cents);

int main(void)
{
    float dollars;
    
    do
    {  
        //Prompt user to enter the amount of change owed
        dollars = get_float("Change owed: $");
    }
    while (dollars < 0);
    
    //Calling function conversion
    conversion(dollars);
}

void conversion(float dollars)
{
    //Converting dollars into cents
    int cents = round(dollars * dollars_to_cents);
    
    //Calling function no_of_coins
    no_of_coins(cents);
}

void no_of_coins(int cents)
{
    //Inital number of coins = 0
    int coins = 0;
    
    do
    {
        //Calulating number of quarters
        if (cents >= quarter)
        {
            coins++;
            cents = cents - quarter;
        }
        
        //Calculating number of dimes
        else if (cents >= dime)
        { 
            coins++;
            cents = cents - dime;
        }
        
        //Calculating number of nickels
        else if (cents >= nickel)
        {
            coins++;
            cents = cents - nickel;
        }
        
        //Calculating number of pennies
        else
        {
            coins++;
            cents = cents - penny;
        }
    }
    while (cents > 0);
   
    //Printing the final result of minimum number of coins possible
    printf("Minimum number of coins: %i\n", coins);
}
