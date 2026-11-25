#include <stdio.h>
#include <stdlib.h>

// & How you can use arrays to store things in memory -> using realloc()
int main(void)
{
    // ~ List variable will be the address of an int and set malloc return value to that
    int *list = malloc(3 * sizeof(int));
    // ~ Check for NULL value
    if (list == NULL)
    {
        // ~ return 1 means that something went wrong -> quit program
        return 1;
    }

    // ~ Treat the chunk of memory as an array
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // ~ Time passes in the program and want to let the user add into memory and realize that i need more than 3 integers -> like 4 integers
    // ~ Don't need to redeclare list again
    // ~ Use realloc() -> it reallocates memory but smarter b/c it will try to grow existing chunk of memory if it can
    // ~ It could just add the another value at the end or if no room in memory. it will do all the copying for me so I do not have to do so
    // ~ Have to tell realloc() what the address of the chunk of memory that you want to reallocate
    int *tmp = realloc(list, 4 * sizeof(int));

    // ~ Check for NULL value
    if (tmp == NULL)
    {
        // ~ After we have done the copy want to free up the original list and give back the memory to the computer
        free(list);
        // ~ return 1 means that something went wrong -> quit the program
        return 1;
    }

    // ~ Go to the 4th location and set that value to int 4 -> adds the 4th value
    tmp[3] = 4;

    // ~ After we have done the copy want to free up the original list and give back the memory to the computer
    free(list);

    // ~ Updating list to store the new chunk of memory in the list variable
    list = tmp;

    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    // ~ Free the list again because it is now pointing to the new address of the chunk of memory
    free(list);

    // ~ If get to this point in the program all is -> return 0 = successful
    return 0;
}

