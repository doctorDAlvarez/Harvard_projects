// Check what grade it needs to understand a text.

#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    float letterCount = 0;
    float wordCount = 1;
    float phraseCount = 0;

    string text = get_string("Text: ");

    int textLength = strlen(text);
    for (int i = 0; i < textLength; i++)
    {
        if (isalpha(text[i]))
        {
            letterCount += 1;
        }
        else if (isspace(text[i]))
        {
            wordCount += 1;
        }
        else if (text[i] == 63 || text[i] == 33 || text[i] == 46)
        {
            phraseCount += 1;
        }
    }

    float L = (100 * letterCount) / wordCount;
    float S = (100 * phraseCount) / wordCount;

    float index = (0.0588 * L) - (0.296 * S) - 15.8;

    int rounded = round(index);

    if (rounded >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (rounded < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", rounded);
    }
}

