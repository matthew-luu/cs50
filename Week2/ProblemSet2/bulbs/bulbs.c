// Matthew Luu
// 09-12-2023

#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // TODO
    string message = get_string("Message: ");

    // Convert each char in the string into an integer
    for (int i = 0; i < strlen(message); i++)
    {
        int value = message[i];

        // Convert the integer value to an 8 bit number;
        int bits[8] = {0, 0, 0, 0, 0, 0, 0, 0};
        for (int j = 0; j < 8; j++)
        {
            bits[7 - j] = value % 2;
            value = value / 2;
            if (value == 0)
            {
                break;
            }
        }

        // Print the bulbs
        for (int j = 0; j < 8; j++)
        {
            print_bulb(bits[j]);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
