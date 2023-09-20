#include <cs50.h>
#include <math.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{
    // TODO
    // We are going to use sieve theory to try and optimize this algorithm
    // Specifically the "Seive of Eratostenes"
    // How it works:
    // we are trying to find the smallest factor of the number if it exists
    // to speed up the algorithm, we should check the least amount of numbers
    // So we should only check numbers up to the prime of the square root of n
    // (This can be further optimized by only checking prime numbers)

    if (number <= 1)
        return false;

    int x = sqrt(number) + 1;
    int i;
    for (i = 2; i < x; i++)
    {
        if (number % i == 0)
        {
            return false;
        }
    }
    return true;
}
