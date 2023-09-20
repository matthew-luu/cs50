// Matthew Luu
// 09-06-2023

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get height from user
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Print pyramid
    int i, j;
    for (i = 0; i < height; i++)
    {
        // Print left side
        // Loops for spaces
        for (j = 0; j < height - i - 1; j++)
        {
            printf(" ");
        }

        // Loops for blocks
        for (j = 0; j < i + 1; j++)
        {
            printf("#");
        }

        // Print gap in pyramid
        printf("  ");

        // Print right side
        for (j = 0; j < i + 1; j++)
        {
            printf("#");
        }

        printf("\n");
    }
}