// Nikhil Raghavendra
// 17 September 2018
// Problem Set 1
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Initialize the height variable
    int height;

    // Prompt the user for input, reprompt if input is invalid
    do
    {
        // Get integer as input
        height = get_int("Height: ");
    }
    while (height < 0 || height > 23);

    // Draw the half-pyramid
    for (int i = 0; i < height; i++)
    {
        // Print spaces repeatedly
        for (int j = height - i - 1; j > 0; j--)
        {
            printf(" ");
        }

        // Print hashes repeatedly
        for (int n = i + 1; n > 0; n--)
        {
            printf("#");
        }

        // Print separating spaces
        printf("  ");

        // Print hashes repeatedly
        for (int x = i + 1; x > 0; x--)
        {
            printf("#");
        }

        // New line for each row
        printf("\n");
    }
}