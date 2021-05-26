// Calculate how many years to reach certain size of a population based on nat and passed data.

#include <cs50.h>
#include <stdio.h>


int main(void)
{
    // TODO: Prompt for start size
    int startSize;
    do
    {
        startSize = get_int("Select Starting population size: ");
    } 
    while (startSize < 9);
    // TODO: Prompt for end size
    int endSize;
    do
    {
        endSize = get_int("Select ending population size: ");
    } 
    while (startSize > endSize);

    // TODO: Calculate number of years until we reach threshold
    int counter = 0;
    while (startSize < endSize)
    {
        int born = startSize / 3;
        int passed = startSize / 4;
        startSize += born - passed;
        counter ++;
    }
    // TODO: Print number of years
    printf("Years: %i\n", counter);
}
