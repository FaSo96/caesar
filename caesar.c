#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int key = 0;

int decipher(string text);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (isdigit(argv[1][i]) == false)
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        key = atoi(argv[1]);

        if (key > 0)
        {
            string plaintext = get_string("plaintext:  ");

            decipher(plaintext);

            printf("ciphertext: %s\n", plaintext);
            return 0;
        }
        else
        {
            printf("Only positive integers possible!\n");
            return 1;
        }
    }
    else
    {
        printf("Only one positive integer possible!\n");
        return 1;
    }
}

int decipher(string text)
{
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            if (isupper(text[i]))
            {
                text[i] += (key % 26);

                if (text[i] > 90)
                {
                    text[i] -= 26;
                }
            }
            else if (islower(text[i]))
            {
                text[i] -= 26;
                text[i] += (key % 26);

                if (text[i] > 96)
                {
                    text[i] -= 26;
                }

                text[i] += 26;
            }
            else
            {
                return 1;
            }
        }
    }
    return 0;
}
