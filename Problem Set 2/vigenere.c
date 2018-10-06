// Nikhil Raghavendra
// 4 October 2018
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
    }
    else {
        // Check if a non-alphabetical character exists in key
        for (int i = 0, n = strlen(argv[1]); i < n; i++) {
            if (!isalpha(argv[1][i])) {
                printf("Key contains non-alphabetical character!\n");
                return 1;
            }
        }
        // Prompt and get plaintext
        string plaintext = get_string("plaintext: ");
        // Iterate over each character in plaintext
        for (int i = 0, j = 0, n = strlen(plaintext); i < n; i++) {
            // Initialize and set key
            int key = 0;
            if (isupper(argv[1][j])) {
                key = (int) argv[1][j] - 'A';
            } else if (islower(argv[1][j])) {
                key = (int) argv[1][j] - 'a';
            }
            // Check if character in an alphabet
            if (isalpha(plaintext[i])) {
                if (isupper(plaintext[i])) {
                    plaintext[i] = (int) plaintext[i] - 'A';
                    plaintext[i] = 'A' + (plaintext[i] + key) % 26;
                } else if (islower(plaintext[i])) {
                    plaintext[i] = (int) plaintext[i] - 'a';
                    plaintext[i] = 'a' + (plaintext[i] + key) % 26;
                }
                
                // Check for variable reset
                if (j < strlen(argv[1]) - 1) {
                    j++;
                } else {
                    j = 0;
                }
            }
        }
        // Print ciphertext
        printf("ciphertext: %s\n", plaintext);
        // Return zero and terminate program
        return 0;
    }
}