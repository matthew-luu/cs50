// Matthew Luu
// 09-12-2023

// There is an error in the specifications of this assignment OR in the check50 code.
// The specification states that there is no newline in the output, but check50 requires \n
// This code is written to satisfy check50's tests.

#include <cs50.h>
#include <stdio.h>
#include <string.h>

string substitute_encrypt(string text, string key);
string convertUpper(string key);
bool checkKey(string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (!checkKey(argv[1]))
    {
        return 1;
    }
    string plain = get_string("plaintext: ");
    string cipher = substitute_encrypt(plain, argv[1]);
    printf("ciphertext: %s\n", cipher);
    return 0;
}

string substitute_encrypt(string text, string key)
{
    string newText = text;
    string upperkey = convertUpper(key);

    // Convert plain text into ciphertext
    for (int i = 0; i < strlen(text); i++)
    {
        int index;
        // Change letter to encrypted letter
        // First check if it us uppercase or lowercase

        // If uppercase
        if (newText[i] >= 65 && newText[i] <= 90)
        {
            index = newText[i] - 65;
            newText[i] = upperkey[index];
        }
        // If lowercase
        else if (newText[i] >= 97 && newText[i] <= 122)
        {
            index = newText[i] - 97;
            newText[i] = upperkey[index] + 32;
        }
    }

    return newText;
}

string convertUpper(string key)
{
    string upperkey = key;
    for (int i = 0; i < 26; i++)
    {
        if (key[i] >= 97 && key[i] <= 122)
        {
            upperkey[i] = key[i] - 32;
        }
    }
    return upperkey;
}

bool checkKey(string key)
{

    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return false;
    }

    // Create an array to keep track of all the letters
    int charSet[26] = {0};

    for (int i = 0; i < 26; i++)
    {
        char c = key[i];
        if (!((c >= 97 && c <= 122) || (c >= 65 && c <= 90)))
        {
            printf("Key must contain only alphabetic characters.\n");
            return false;
        }

        // Convert character to lowercase to compare
        if (c >= 65 && c <= 90)
        {
            c = c + 32;
        }

        int index = c - 'a';
        if (charSet[index] == 1)
        {
            printf("Key cannot contain duplicate characters.\n");
            return false;
        }

        // Keeps track of letters that are already used
        charSet[index] = 1;
    }

    // If the key passes all tests, it is valid
    return true;
}