#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long cardNumber = get_long("Card Number to validate: ");
    //initialization of variables
    int cardLength = 0;
    long cardClone = cardNumber;
    int sum1 = 0;
    int sum2 = 0;
    int firstDigit;
    int secondDigit;
    bool isValidate = false;

    //calculation of card length
    while (cardClone != 0)
    {
        cardClone /= 10;
        cardLength++;
    }
    printf("card length: %i\n", cardLength);

    //reestablish the clone for future processing.
    cardClone = cardNumber;

    //logic to get first two digits
    for (int i = 0; i < cardLength; i++)
    {

        if (i == cardLength - 1)
        {
            firstDigit = cardClone % 10;
        }
        else if (i == cardLength - 2)
        {
            secondDigit = cardClone % 10;
        }
        cardClone /= 10;
    }

    //logic to Luhn's
    for (int i = 0; i < cardLength; i++)
    {
        if (i % 2 != 0)
        {
            int digit = cardNumber % 10 * 2;
            cardNumber /= 10;
            printf("%i\n", digit);
            if (digit < 10)
            {
                sum1 += digit;
            }
            else
            {
                for (int j = 0; j < 2; j++)
                {
                    sum1 += (digit % 10);
                    digit /= 10;

                }
            }
        }
        else
        {
            sum2 += cardNumber % 10;
            cardNumber /= 10;
        }
    }
    //calculate the total sum of Luhn's algorythm
    int totalSum = sum1 + sum2;
    printf("%i\n", firstDigit);
    printf("%i, %i\n", sum1, sum2);


    // validations
    if (totalSum % 10 == 0 && firstDigit == 5 && (secondDigit == 1 || secondDigit == 5) && cardLength == 16)
    {
        isValidate = true;
        printf("MASTERCARD\n");
    }
    else if (totalSum % 10 == 0 && firstDigit == 3 && (secondDigit == 4 || secondDigit == 7) && cardLength == 15)
    {
        isValidate = true;
        printf("AMEX\n");
    }
    else if (totalSum % 10 == 0 && firstDigit == 4 && (cardLength == 13 || cardLength == 16))
    {
        isValidate = true;
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

