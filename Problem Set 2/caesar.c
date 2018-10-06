// Nikhil Raghavendra
// 25 September 2018
// Problem Set 2
#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[]) {
    // Check if the number of command-line arguments
    // is greater than one. Return one if true.
    if (argc != 2) {
        // Error message
        printf("Error: invalid number of command-line arguments.\n");
        // Return one to signify an error
        return 1;
    } else {
        // Encryption key from the command-line argument
        int key = atoi(argv[1]);
        // Check if command-line argument is non-negative
        if (key > 0) {
            // Prompt and get plaintext
            string plaintext = get_string("plaintext: ");
            // Iterate over each character in plaintext
            for (int i = 0, n = strlen(plaintext); i < n; i++) {
                // Check if character in an alphabet
                if (isalpha(plaintext[i])) {
                    if (isupper(plaintext[i])) {
                        plaintext[i] = (int) plaintext[i] - 'A';
                        plaintext[i] = 'A' + (plaintext[i] + key) % 26;
                    } else if (islower(plaintext[i])) {
                        plaintext[i] = (int) plaintext[i] - 'a';
                        plaintext[i] = 'a' + (plaintext[i] + key) % 26;
                    }
                }
            }
            // Print ciphertext
            printf("ciphertext: %s\n", plaintext);
            // Return zero and terminate program
            return 0;
        }
    }
}