// Nikhil Raghavendra
// 17 September 2018
// Problem Set 1
#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    // Initialize the change
    int cents;
    
    // Initialize the number of coins
    int coins = 0;

    // Prompt the user input, reprompt if input is invalid
    do {
        // Convert dollars to cents, round off and cast to int
        cents = (int) round(get_float("Change owed: ") * 100);
    } while (cents <= 0);

    // Calculate the minimum number of coins to be returned
    // Number of quarters (25¢)
    coins += (cents - (cents % 25)) / 25;
    cents -= ((cents - (cents % 25)) / 25) * 25;

    // Number of dimes (10¢)
    coins += (cents - (cents % 10)) / 10;
    cents -= ((cents - (cents % 10)) / 10) * 10;

    // Number of nickels (5¢)
    coins += (cents - (cents % 5)) / 5;
    cents -= ((cents - (cents % 5)) / 5) * 5;

    // Number of pennies (1¢)
    coins += (cents - (cents % 1)) / 1;
    cents -= ((cents - (cents % 1)) / 1) * 1;

    // Print the minimum number of coins needed
    printf("%d\n", coins);
}