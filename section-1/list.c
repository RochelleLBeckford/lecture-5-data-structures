#include <stdio.h>

// & How you can use arrays to store things in memory
int main(void)
{
    // ~ Declare an array of integers of size 3
    int list[3];

    // ~ Hardcode some values -> locations/index on the left and the value at that location on the right
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // ~ Prove stored correctly in memory
    for (int i = 0; i < 3; i++)
    {
        // ~ Print out the value at list location of i -> should see 1, 2, 3
        printf("%i\n", list[i]);
    }
}
