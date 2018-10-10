// Nikhil Raghavendra
// 10 October 2018
// Problem Set 2
#define _XOPEN_SOURCE
#include <unistd.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[]) {
    // Only allow one command-line argument
    if (argc != 2) {
        // Error message
        printf("Usage: ./crack hash\n");
        // Return one to signify an error
        return 1;
    } else {
        // Number of possible characters
        const int lettersCount = 53;
        // Array to store all the possible characters
        char letters[53] = "\0abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        // Array to store unhashed password
        char unhashedPassword[6] = "\0\0\0\0\0\0";;
        // Array to store encryption salt
        char salt[3];
        // Get encryption salt from the hashed password
        strncpy(salt, argv[1], 2);
        // Null terminate the encryption salt array
        salt[2] = '\0';
        // Generate and check all possible permuatations
        for (int fifth = 0; fifth < lettersCount; fifth++) {
            for (int fourth = 0; fourth < lettersCount; fourth++) {
                for (int third = 0; third < lettersCount; third++) {
                    for (int second = 0; second < lettersCount; second++) {
                        for (int first = 1; first < lettersCount; first++) {
                            // Permutation of possible characters
                            unhashedPassword[0] = letters[first];
                            unhashedPassword[1] = letters[second];
                            unhashedPassword[2] = letters[third];
                            unhashedPassword[3] = letters[fourth];
                            unhashedPassword[4] = letters[fifth];

                            // Check if the hashed passwords match
                            if (strcmp(crypt(unhashedPassword, salt), argv[1]) == 0) {
                                printf("Password: %s\n", unhashedPassword);
                                return 0;
                            }
                        }
                    }
                }
            }
        }
        // Hashed passwords don't match, password uncrackable
        printf("Password is uncrackable...\n");
        // Return zero and terminate program
        return 0;
    }
}