// Nikhil Raghavendra
// 17 September 2018
// Problem Set 1
#include <cs50.h>
#include <stdio.h>
#include <math.h>

// Function prototypes
int iter_sum(int num);

int main(void)
{
    // Initialize the credit card variable
    long long credit, temp_credit;

    // Initialize iterator, second-to-last num sum and remaining sums
    int iter = 1, second_to_last = 0, last_sum = 0;

    // Prompt the user for input, reprompt if input is invalid
    do
    {
        // Get long long as input
        credit = get_long_long("Number: ");
        // Copy the value to temp_credit
        temp_credit = credit;
    }
    while (credit < 0);

    // Luhn's algorithm
    while (credit != 0)
    {
        // Get the last digit of number
        int last_num = credit % 10;
        credit = floor(credit / 10);

        // Sum of second-to-last digits
        if (iter % 2 == 0)
        {
            int product = last_num * 2;
            second_to_last += iter_sum(product);
        }
        else
        {
            // Sum of last digits
            last_sum += last_num;
        }

        // Increment iterator
        iter++;
    }

    // Calculate and check if checksum is valid
    if ((second_to_last + last_sum) % 10 == 0)
    {
        // Length of credit card number
        int length = iter - 1;

        // Check if credit card number length is valid
        if (length == 13 || length == 15 || length == 16)
        {
            // Get the first two digits of the credit card number
            int first_digits = floor(temp_credit / pow(10, iter - 3));

            // Check card type
            if (first_digits == 34 || first_digits == 37)
            {
                // American Express
                printf("AMEX\n");
            }
            else if (first_digits >= 51 && first_digits <= 55)
            {
                // Mastercard
                printf("MASTERCARD\n");
            }
            else if (floor(first_digits / 10) == 4)
            {
                // Visa
                printf("VISA\n");
            }
            else
            {
                // Invalid credit card number
                printf("INVALID\n");
            }
        }
        else
        {
            // Invalid credit card length
            printf("INVALID\n");
        }
    }
    else
    {
        // Invalid checksum
        printf("INVALID\n");
    }
}

int iter_sum(int num)
{
    // Initialize the sum
    int sum = 0;

    // Calculate the checksum of the credit card number
    while (num != 0)
    {
        sum += num % 10;
        num = floor(num / 10);
    }
    return sum;
}