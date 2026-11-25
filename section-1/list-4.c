// ~ easier to use for to get ints, strings, and other things
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

// & Store things in memory -> implement 1st linked list

// ~ Invent this structure called node
typedef struct node
{
    // ~ Give every node a number and every such node a pointer to the next such node
    int number;
    struct node *next;
} node;

int main(void)
{
    // ~ Represent an empty linked list
    // ~ List is of type node * -> since need linked list is the address of the 1st node in the list
    // ~ Gives a picture with no other node and just gives a single pointer initialized to node
    node *list = NULL;

    // ~ Just do something 3 times
    for (int i = 0; i < 3; i++)
    {
        // ~ Allocate a new node & store the address of this node somewhere
        // ~ Trying to build up this list in memory so that I 1st have a pointer that is NULL pointing no where no list yet
        // ~ Then want to create 1 new node, store a value in it, then point my list at that node, again & again 3 times
        // ~ Do this by allocating space for a node store the address of this chunk of memory inside a temp variable n for node
            // ~ That is why it is called node * b/c it is going to be pointing to an actual node
        node *n = malloc(sizeof(node));
        // ~ Do check for NULL - if NULL cannot proceed further -> anytime using malloc should run this check
        if (n == NULL)
        {
            // ~ Return 1 means that something went wrong -> quit the program
            return 1;
        }
        // ~ Now to stitch everything together -> string these nodes together
        // ~ Ask the user for a number to put inside of it
        // ~ Go to the address in n then go inside that node and change its number to be whatever the user wants it to be -> prompt user for their favorite number
        // ~ Need to dereference it then go into it
        // (*n).number = get_int("Number: ");
        // ~ Then go to that same node & update the next field to equal for now NULL -> b/c all I want to do is allocate one new node with that new number
        // ~ Need to dereference n then go into it
        // (*n).next = NULL;

        // ~ In C there is a simpler way to do this -> arrow notation ~ Same thing as using the de-reference operator (*) parenthesize it () then the dot operator (.)
        // ~ Go to the node then go inside it to get the number -> go to the n then point at the # field
        n->number = get_int("Number: ");
        // ~ Go to the node then go inside it to get next -> go to n then point at the next field
        n->next = NULL;

        // ~ Prepend node to list -> meaning to insert it into the beginning, insert it into the beginning again & again
        n->next = list;
        list = n;
    }

    // ~ If get to this point in the program all is well -> return = 0 means the program was successful
    return 0;
}
