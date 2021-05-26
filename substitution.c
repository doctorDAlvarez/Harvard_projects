// substitution cipher algorithm. 
// run ./substitution KEY and cipher a text.

#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>

//helper function
bool hasUniqueLetters(string key)
{
    //string key = "abcdefghijklmnopqrstuvwxyz";
    int strlength = strlen(key);
    int sum = 0;

    for (int i = 0; i < strlength; i++)
    {
        char k = toupper(key[i]);
        sum += (int) k;
    }
    if (sum == 2015)
    {
        return true;
    }
    else
    {
        return false;
    }

}

int main(int argc, string argv[])
{
    if (!argv[1] || argv[2])
    {
        printf("Usage: ./subsitution <key>\n");
        return 1;
    }
    else if (hasUniqueLetters(argv[1]) == false)
    {
        printf("Key must contain 26 unique characters\n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");
    string key = argv[1];
    int plainLen = strlen(plaintext);
    string cipher = plaintext;

    for (int i = 0; i < plainLen; i++)
    {
        if (isalpha(plaintext[i]) == 0)
        {
            cipher[i] = plaintext[i];
        }
        else if (isupper(plaintext[i]) == 0)
        {
            int index = plaintext[i] - 97;
            cipher[i] = key[index];
            cipher[i] = tolower(cipher[i]);
        }
        else if (islower(plaintext[i]) == 0)
        {
            int index = plaintext[i] - 65;
            cipher[i] = key[index];
            cipher[i] = toupper(cipher[i]);
        }
    }


    printf("ciphertext: %s\n", cipher);
    return 0;

}
