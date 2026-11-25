#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

// & Store things in memory -> Append to the list

// ~ Create structure called node
typedef struct node
{
    // ~ Give every node a number and every such node a pointer to the next such node
    int number;
    struct node *next;
} node;

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

        // ~ Check that n != NULL -> if it is the program will quit
        if (n == NULL)
        {
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

        // ~ If the list I am inserting into already has numbers in it
        else
        {
            // ~ Iterate over the nodes in the list and append it to the end of the list
            for (node *ptr = list; ptr != NULL; ptr = ptr->next)
            {
                // ~ If following the current nodes next field leads to NULL (aka the end of the list)
                if (ptr->next == NULL)
                {
                    // ~ Append the node -> go ahead and update the end of the list = the new node
                    ptr->next = n;
                    // ~ Then want to break out of the code
                    break;
                }
            }
        }
    }

    // ~ Print the numbers -> using a for loop
    // ~ Create a new pointer -> ptr = to the list itself
    // ~ for node *ptr = the start of the list; keep doing something so long as ptr does != NULL; on each iteration of the list set ptr = whatever the ptr next field is
    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        // ~ Print out the current pointers number field
        printf("%i\n", ptr->number);
    }

    // ~ To Free up memory -> free up everyone of the nodes afterward
    node *ptr = list;
    while (ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }

    // ~ If the code gets to this point in the program all is well -> return = 0 means the program was successful
    return 0;
}

