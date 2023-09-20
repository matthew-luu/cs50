// Matthew Luu
// 09-14-2023

#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    // If we are working with an empty string, then we are done. This is the base case.
    if (*input == '\0')
    {
        return 0;
    }
    // Start with last character, change it to an integer
    int x = input[strlen(input) - 1] - 48;

    // Shorten the string
    input[strlen(input) - 1] = '\0';

    // Recursively call the shortened string
    return x + 10 * convert(input);
}