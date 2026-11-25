#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

// & Store things in memory -> implement 1st linked list -> prepend node to list 

// ~ Create stucture called node
typedef struct node
{
    // ~ Give every node a number and every such node a pointer to the next such node
    int number;
    struct node *next;
} node;

int main(void)
{   // ~ Gives a picture with no other node and just gives a single pointer initialized to node
    node *list = NULL;

    // ~ Just do something 3 times
    for (int i = 0; i < 3; i++)
    {
        // ~ Allocate a space in memory for a node to store the address of this chunk of memory inside a temporary variable - n - for a node
            // ~ That is why it is called node * b/c it is going to be pointing to an actual node
        node *n = malloc(sizeof(node));

        // ~ Run a check to see if a NULL value is returned -> program will quit if value is NULL
        if (n == NULL)
        {
            // ~ Return 1 means that something went wrong -> quit the program
            return 1;
        }

        // ~ Use the arrow notation to go to the node then go inside it to get the number -> go to n then point at the # field
        n->number = get_int("Number: ");
        n->next = NULL;

        // ~ Prepend node to list
        // ~ Go to the node then go inside it to get next -> go to n then point at the next field
        n->next = list;
        list = n;
    }

    // ~ Want to print the numbers
    // ~ Create a new pointer -> ptr = to the list itself
    // ~ Like having another foam finger temporarily pointing at the first element in the list
    node *ptr = list;
    // ~ While that temp variable is not NULL the go ahead and traverse the list
    while (ptr != NULL)
    {
        // ~ Print out the current element in the list -> whatever the pointer is pointing at, specifically the number field
        // ~ Follow the arrow and print out the number
        printf("%i\n", ptr->number);
        // ~ Update my temporary variable (ptr) will = prt->next
        ptr = ptr->next;
    }

    // ~ Can do the same thing using a for loop -> can use pointers in a for loop
    // ~ for node *ptr = the start of the list; keep doing something so long as ptr does not = NULL; on each iteration of the list set ptr to = whatever the ptr next field is
    // for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    // {
        // ~ Print out the current pointers number field
        // printf("%i\n", ptr->number);
    // }

    // ~ If get to this point in the program all is well -> return = 0 means the program was successful
    return 0;
}

