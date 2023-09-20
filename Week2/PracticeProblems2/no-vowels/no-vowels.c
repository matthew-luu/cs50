// Matthew Luu
// 09-12-2023

// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Function prototype
string replace(string word);

int main(int argc, string argv[])
{

    // check if program is executed with correct commnd-line arguments
    if (argc != 2)
    {
        printf("Usage: ./no-vowels word");
        return 1;
    }

    printf("%s\n", replace(argv[1]));
}

string replace(string word)
{
    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] == 'a')
        {
            word[i] = '6';
        }

        if (word[i] == 'e')
        {
            word[i] = '3';
        }

        if (word[i] == 'i')
        {
            word[i] = '1';
        }

        if (word[i] == 'o')
        {
            word[i] = '0';
        }
    }
    return word;
}