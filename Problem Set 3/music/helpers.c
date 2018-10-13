// Helper functions for music
// Nikhil Raghavendra
// 13 October 2018
// Problem Set 3
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    // Convert numerator and denominator into a double. Divide
    // them and then multiply by 8. Cast to an integer.
    return (int)((atof(&fraction[0]) / atof(&fraction[2])) * 8);
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    // Octave the note belongs to
    int octave = note[strlen(note) - 1];
    // Adjust ASCII value to int value
    octave -= 48;

    // Initialize the frequency of the note
    double freq = 0.00;

    // Compute base frequency based on letter of the note
    switch (note[0])
    {
        case 'C' :
            freq = 440.0 / (pow(2.0, (9.0 / 12.0)));
            break;
        case 'D' :
            freq = 440.0 / (pow(2.0, (7.0 / 12.0)));
            break;
        case 'E' :
            freq = 440.0 / (pow(2.0, (5.0 / 12.0)));
            break;
        case 'F' :
            freq = 440.0 / (pow(2.0, (4.0 / 12.0)));
            break;
        case 'G' :
            freq = 440.0 / (pow(2.0, (2.0 / 12.0)));
            break;
        case 'A' :
            freq = 440.0;
            break;
        case 'B' :
            freq = 440.0 * (pow(2.0, (2.0 / 12.0)));
            break;
        default :
            return 0;
    }

    // Adjust frequency based on the octave
    if (octave > 4)
    {
        for (int i = 0; i < octave - 4; i++)
        {
            freq *= 2.0;
        }
    }
    else if (octave < 4)
    {
        for (int i = 0; i < 4 - octave; i++)
        {
            freq /= 2.0;
        }
    }

    // Adjust frequency based on sharp or flat notation
    if (note[1] == 'b')
    {
        freq /= (pow(2.0, (1.0 / 12.0)));
    }
    else if (note[1] == '#')
    {
        freq *= (pow(2.0, (1.0 / 12.0)));
    }

    // Return frequency value as an integer
    return (int) round(freq);
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    // Blank lines represent rests in our machine-readable format.
    // This means it's a line ending that returns "".
    if (!strcmp(s, ""))
    {
        return true;

    }
    else
    {
        return false;

    }
}