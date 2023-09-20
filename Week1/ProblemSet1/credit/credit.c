// Matthew Luu
// 09-11-2023

#include <cs50.h>
#include <stdio.h>

void check_card(long n);
bool luhn_algo(long n);
int countDigits(long num);

int main(void)
{
    long number;

    do
    {
        number = get_long("Number: ");
    }
    while (!number);

    check_card(number);

    return 0;
}

void check_card(long n)
{
    bool valid = luhn_algo(n);

    if (valid)
    {
        // Find the first two digits
        long digits = n;
        int count = countDigits(n);

        while (digits >= 100)
        {
            digits = digits / 10;
        }

        // Find out which type of card
        if ((digits == 34 || digits == 37) && count == 15)
        {
            printf("AMEX\n");
            return;
        }

        if ((digits >= 51 && digits <= 55) && count == 16)
        {
            printf("MASTERCARD\n");
            return;
        }

        if ((digits >= 40 && digits <= 49) && (count == 13 || count == 16))
        {
            printf("VISA\n");
            return;
        }
    }

    // If it does not meet the conditions for AMEX, MASTERCARD, or VISA then it is invalid
    printf("INVALID\n");
    return;
}

bool luhn_algo(long n)
{
    long x = n;
    int total = 0;
    int digit_count = 0;

    while (x > 0)
    {
        int digit = x % 10;
        if (digit_count % 2 == 1)
        {
            digit = digit * 2;
            if (digit >= 10)
            {
                digit = digit % 10 + digit / 10;
            }
        }
        total = total + digit;
        x = x / 10;
        digit_count++;
    }

    if (total % 10 == 0)
    {
        return true;
    }

    return false;
}

int countDigits(long num)
{
    int count = 0;

    while (num != 0)
    {
        num /= 10;
        count++;
    }

    return count;
}