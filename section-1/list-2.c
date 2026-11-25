#include <stdio.h>
// ~ Forgot to include the library to access malloc
#include <stdlib.h>

// & How you can use arrays to store things in memory -> make arrays more dynamic instead of static/hardcoding it
int main(void)
{
    // ~ Dynamically allocate a guess at how much memory I will need
    // ~ list variable will be the address of an int and set malloc return value to that
    int *list = malloc(3 * sizeof(int));
    // ~ If the list pointer I get back returns NULL there is no point in running the program
    if (list == NULL)
    {
        // ~ 1 means that something went wrong
        return 1;
    }

    // ~ Can add this syntax but better to go to the address in list
    // list[0] = 1;
    // list[1] = 2;
    // list[2] = 3;
    // ~ Instead say go to that address in list and put the value there but this looks ridiculous and an experienced programmer would not do this
    // *list = 1;
    // *(list + 1) = 2;
    // *(list + 2) = 3;
    // ~ Use fewer keystrokes and more readable code -> like before treat the chunk of memory as an array and let the computer do pointer arithmetic to figure out where to put 1, 2, 3
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // ~ Time passes in the program and want to let the user add into memory and realize that i need more than 3 integers -> like 4 integers
    // ~ Don't need to redeclare list again
    // list = malloc(4 * sizeof(int));
    // ~ This is bad -> poor decision
    // ~ Waisting memory I got from line 8, line 25 is telling me to point the pointer elsewhere losing track of the memory i acquired on line 8 -> memory leak
    // ~ Better to use temporary variable -> need to remember something in addition to something I already have in mind
    int *tmp = malloc(4 * sizeof(int));
    // ~ If the temporary pointer returns NULL something went wrong and exit the program
    if (tmp == NULL)
    {
        // ~ Need to free the original list & say to the operating system here is your memory back
        // ~ Even though when the program quits the memory is eventually returned back to the computer but not right away, best practice to squash memory related leaks
        free(list);
        // ~ 1 means that something went wrong
        return 1;
    }

    // ~ Copy old list into new list
    for (int i = 0; i < 3; i++)
    {
        // ~ Treat new chunk of memory as an array, set the ith location = to the ith location on list
        tmp[i] = list[i];
    }
    // ~ Go to the 4th location and set that value to int 4 -> adds the 4th value
    tmp[3] = 4;

    // ~ After we have done the copy want to free up the original list and give back the memory to the computer
    free(list);
    // ~ Remember that the new list is what we allocated the 2nd time around
    // ~ Store the in list variable the new chunk of memory
    list = tmp;

    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    // ~ Free the list again because it is now pointing to the new address of the chunk of memory
    free(list);

    // ~ If get to this point in the program all is well -> return 0 = successful
    return 0;
}
