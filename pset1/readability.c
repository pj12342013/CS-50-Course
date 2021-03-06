#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)

{   // Prompt for user input string
    string text = get_string("Text:\n");

    //find out number of words, sentences, letters in a text
    int letters = 0;

    int sentences = 0;

    int words = 0;

    // Letters count, accurate
    for (int i = 0; text[i]!='\0'; i++ )

            if (isalpha( (unsigned char) text [i] ) )
            {
                letters++;
             }

    // Sentences Count,accurate
    for (int j = 0; j < strlen (text); j++ )

            if (text[j] == '!' || text[j] == '?' || text[j] == '.')
            {
                sentences++;
            }

    // words count. Accuracy = Less 1 than actual. Fixed in next line
   for (int k = 0; text[k]!='\0'; k++ )

            if (isblank( (unsigned char) text [k] ) )
            {
                words++;
            }

    //fixing word count to account for last full stop.
    words = words + 1;

    float a = letters * 100.00 / words;

    float b = sentences * 100.00 / words;

    float index = 0.0588 * a - 0.296 * b - 15.8;

    int clindex = round(index);

    if (clindex >= 16 )
    {
        printf("Grade 16+\n");
    }
    else if (clindex < 1 )
    {
        printf("Before Grade 1\n");
    }
    else  
    {  
        printf("Grade %i\n", clindex);
    }

}
