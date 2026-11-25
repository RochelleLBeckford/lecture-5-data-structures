#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

// & Store things in memory -> Implement a sorted linked list of numbers

// ~ Create a structure called node
typedef struct node
{
    // ~ Giver every node a number and every such node a pointer to the next such node
    int number;
    struct node *next;
} node;

// ~ Prototype ~ tell the compiler that this function will exist later on in the file -> teach the compiler what the function I am calling is going to look like
void unload(node *list);

int main(void)
{
    // ~ Memory for the numbers
    // ~ The beginning of the list -> a single pointer initialize to node
    node *list = NULL;

    // ~ Build the list -> Insert 3 values
    for (int i = 0; i < 3; i++)
    {
        // ~ Allocate a space in memory for the node for number setting the address = n -> it will be pointing to an actual node
        node *n = malloc(sizeof(node));

        // ~ Check that n ~= NULL -> if it is the program will quit
        // ~ This could be a minor error because not removing memory previous iteration
        if (n == NULL)
        {
            // ~ Call the function that will remove memory and free up space
            unload(list);
            // ~ Return 1 means that something went wrong -> quit the program
            return 1;
        }
        // ~ Use the arrow notation to go to the node then go inside it to get the int from the user and put it in that field
        n->number = get_int("Number: ");
        // ~ Initialize pointers to NULL before assigning values to them is a good practice
        n->next = NULL;

        // ~ If the list is I am inserting into this new node is empty
        if (list == NULL)
        {
            // ~ Set the list = to the address of that new node
            list = n;
        }

        // ~ If the number belongs at the beginning of this list -> if the in the new node n < the number in the current list (presumed to be the 1st node)
        else if (n->number < list->number)
        {
            // ~ Update the new node next field to point at the existing list
            n->next = list;
            // ~ Update the list to point at this new node -> update the list pointer to point to that new node
            list = n;
        }

        // ~ If the number belongs somewhere later in the list ->
        else
        {
            // ~ Iterate over the nodes in list
            for (node *ptr = list; ptr != NULL; ptr = ptr->next)
            {
                // ~ If it belongs at the end of the list -> if get all the way to the end of the list
                if (ptr->next == NULL)
                {
                    // ~ Append the node
                    ptr->next = n;
                    // ~ Then want to break out of the code
                    break;
                }

                // ~ If in somewhere in the middle of list -> not at the beginning nor at the end
                // ~ If the one that I am inserting is less than the one that I am looking at
                if (n->number < ptr->next->number)
                {
                    // ~ This will stitch the lines together
                    n->next = ptr->next;
                    ptr->next = n;
                    // ~ Then want to break out of the code
                    break;
                }
            }
        }
    }

    // ~ Print the numbers -> create a new pointer -> ptr = to the list itself
    // ~ for node *ptr = the start of the list; keep doing something so long as ptr does != NULL; on each iteration of the list set ptr = whatever the ptr next field is
    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        // ~ Print out the current pointers number field
        printf("%i\n", ptr->number);

    }

    // ~ Free memory
    // ~ Call the function that will remove memory and free up space
    unload(list);
    // ~ If the code gets to this point in the program all is well -> return = 0 means the program was successful
    return 0;
}

// ~ This function will remove memory and free up space -> deleting a linked list in its own function so can call it any number of times
void unload(node *list)
{
    node *ptr = list;
    while (ptr != NULL)
     {
        // ~
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
}
 