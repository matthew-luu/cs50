// Matthew Luu
// 09-12-2023

// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool uppercase = false;
    bool lowercase = false;
    bool number = false;
    bool symbol = false;

    for (int i = 0; i < strlen(password); i++)
    {
        if (password[i] >= 65 && password[i] <= 90)
        {
            uppercase = true;
        }

        if (password[i] >= 97 && password[i] <= 122)
        {
            lowercase = true;
        }

        if (password[i] >= 48 && password[i] <= 57)
        {
            number = true;
        }

        if (password[i] >= 33 && password[i] <= 47)
        {
            symbol = true;
        }
    }

    if (uppercase && lowercase && number && symbol)
    {
        return true;
    }

    return false;
}
