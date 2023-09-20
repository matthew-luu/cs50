// Matthew Luu
// 09-11-2023

#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    float index, L, S;

    char *text = get_string("Text: ");

    L = (float) count_letters(text) / count_words(text) * 100;
    // Use this to debug L
    // printf("L: %f\n", L);

    S = (float) count_sentences(text) / count_words(text) * 100;
    // Use this to debug S
    // printf("S: %f\n", S);

    index = 0.0588 * L - 0.296 * S - 15.8;
    // Use this to debug index
    // printf("index: %f\n", index);

    int ret = round(index);

    if (index < 0)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", ret);
    }
}

int count_letters(string text)
{
    int count = 0;
    int i;
    for (i = 0; i < strlen(text); i++)
    {
        if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
        {
            count++;
        }
    }

    // Use this to debug count_letters
    // printf("Letters: %d\n",count);

    return count;
}

int count_words(string text)
{
    int count = 1;
    int i;
    for (i = 0; i < strlen(text); i++)
    {
        if (text[i] == 32)
        {
            count++;
        }
    }

    // Use this to debug count_words
    // printf("Words: %d\n",count);

    return count;
}

int count_sentences(string text)
{
    int count = 0;
    int i;
    for (i = 0; i < strlen(text); i++)
    {
        if (text[i] == 46 || text[i] == 33 || text[i] == 63)
        {
            count++;
        }
    }

    // Use this to debug count_sentences
    // printf("Sentences: %d\n",count);

    return count;
}