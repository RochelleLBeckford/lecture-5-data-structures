<!-- & This creates a banner for the ReadMe -->
<div align="center">
    <img
        src="img/apple-green-empress-gazing-playfully-upon-her-subjects.png"
        alt="Apple Green Empress Gazing Playfully Upon Her Subjects"
        width="100%"
        height="500"
    >
</div>

<h1 align="center">🌸 Data Structures: The Architecture of Linked Lists 🌸</h1>

<h2 align="center">Practice: Building dynamic data structures with pointers, nodes, and memory management in C</h2>

<h3 align="center">Learning Data Structures: Discovering how to organize, connect, and traverse data beyond simple arrays</h3>

<hr>

<h2 align="center">💫 Overview</h2>

- [ ] <b>Data Structures</b> are the containers that hold my data and define how I can interact with it. In this lecture, I finally moved beyond simple arrays and discovered the power of <i>linked lists</i>. Before this, arrays felt rigid, I had to know their size upfront or waste memory. Now, I understand how to build flexible structures where each piece of data (<i>node</i>) points to the next, creating a chain that can grow and shrink as needed. I learned how to dynamically allocate memory for each node using `malloc`, how to stitch nodes together with pointers, and crucially, how to properly free that memory to avoid leaks. Building linked lists is not just about syntax, it is about thinking in pointers and understanding the trade-offs between different ways to organize data.

<hr>

<h2 align="center">👩🏾‍🎨 Key Design Features</h2>

- [ ] <b>Nodes and Linked Lists</b>
    - [ ] A `node` is a structure that contains data (like an `int number`) and a pointer to the next node (`struct node *next`).
    - [ ] A linked list is simply a pointer to the first node (`node *list = NULL`), and each node points to the next until the last node points to NULL.

- [ ] <b>Dynamic Array Growth</b>
    - [ ] Using `malloc( )` to allocate an initial array, then `malloc( )` again for a larger array and copying data over manually/
    - [ ] Using `realloc( )` to intelligently resize an existing chunk of memory, it tries to grow in place or moves and copies for me.

- [ ] <b>Building Linked Lists</b>
    - [ ] <b>Prepending:</b> Inserting at the beginning -> set the new node's `next` to the current list, then update `list` to point to the new node.
    - [ ] <b>Appending:</b> Inserting at the end -> traverse to the last node (where `next == NULL`) and point its `next` to the new node.
    - [ ] <b>Sorted Insert:</b> Inserting in order -> traverse until finding the right spot, then stitch the new node between two existing nodes.
- [ ] <b>Traversal and Pointer Arithmetic</b>
    - [ ] Using a temporary pointer (`node *ptr = list`) to walk through the list without losing the original `list` pointer.
    - [ ] Following the chain: `ptr = ptr->next` moves to the next node until `ptr == NULL`.
- [ ] <b>Memory Cleanup</b>
    - [ ] Freeing a linked list requires traversing it and freeing each node one by one.
    - [ ] Saving `ptr->next` before calling `free(ptr)` so I do not lose my place in the list.

<hr>

<h2 align="center">✍🏾 Simple Practice: Real-World Thinking in C</h2>

- [ ] Arrays felt like a row of lockers bolted to the wall, fixed, immovable, and if I needed more lockers, I had to build a whole new row and move everything over. Linked lists feel like a treasure hunt where each clue tells you where the next one is hidden.
- [ ] The `node` structure was a lightbulb moment. It is just a box that holds a number AND a map to the next box. That is it. Once I saw nodes as "data + directions", the whole concept clicked.
- [ ] Prepending to a linked list is like adding a new first chapter to a book, you just point the new chapter to the old first chapter and update the table of contents. Appending is like walking to the end of the book and taping on a new page.
- [ ] The first time I built a linked list and printed it out, I felt like a magician. I had created a chain of boxes scattered across memory, connected only by addresses and I could walk through them one by one. I felt like I had unlocked a new level of programming.
- [ ] `realloc( )` is lifesaver compared to manual copying. It is like calling a moving company that tries to expand your house in place, and if it cannot it builds a new one and moves everything for you, you just need to update your address.
- [ ] Freeing a linked list taught me to be careful. If I just `free(list)`, I lose the rest of the chain forever. I have to save the next pointer, free the current node, then move on. It is like cleaning up a trail of dominoes, you have to remember where the next one is before you knock it down.

<hr>

<h2 align="center">👩🏾‍💻 C Code Outline</h2>

- [ ] <b>Arrays -> The Static Beginning:</b>
    - [ ] Declaring a fixed-size array and strong values at specific indices.
    ```c
    #include <stdio.h>

    int main(void)
    {
        // ~ Declare an array of integers of size 3
        int list[3];

        // ~ Store values at each index
        list[0] = 1;
        list[1] = 2;
        list[2] = 3;

        // ~ Print each value
        for (int i = 0; i < 3; i++)
        {
            printf("%i\n", list[i]);
        }
    }
    ```

- [ ] <b>Dynamic Arrays with malloc:</b>
    - [ ] Allocating memory at runtime and resizing by creating a new array and copying.
    ```c
    #include <stdio.h>
    #include <stdlib.h>

    int main(void)
    {
        // ~ Allocate memory for 3 integers
        int *list = malloc(3 * sizeof(int));
        if (list == NULL)
        {
            // ~ Return 1 means that something went wrong -> quit the program
            return 1;
        }

        // ~ Treat the chunk of memory as an array
        list[0] = 1;
        list[1] = 2;
        list[2] = 3;

        // ~ Need more space -> allocate a new, larger chunk
        int *tmp = malloc(4 * sizeof(int));
        if (tmp == NULL)
        {
            free(list);
            // ~ Return 1 means that something went wrong -> quit program
            return 1;
        }

        // ~ Copy old values to new memory
        for (int i = 0; i < 3; i++)
        {
            tmp[i] = list[i];
        }
        //~ This will add the 4tg value
        tmp[3] = 4;

        // ~ Free the old list and update the pointer
        free(list);
        list = tmp;

        for (int i - 0; i < 4; i++)
        {
            printf("%i\n", list[i]);
        }

        free(list);
        // ~ Return 0 means the program was successful
        return 0;
    }
    ```

- [ ] <b>Using realloc for Smarter Resizing:</b>
    - [ ] Letting `realloc( )` handle the resizing and copying automatically.
    ```c
    #include <stdio.h>
    #include <stdlib.h>

    int main(void)
    {
        int *list = malloc(3 * sizeof(int));
        if (list == NULL)
        {
            // ~ Return 1 means that something went wrong -> the program will quit
            return 1;
        }

        list[0] = 1;
        list[1] = 2;
        list[2] = 3;

        // ~ Realloc tries to grow in place or moves and copies for me
        int *tmp = realloc(list, 4 * sizeof(int));
        if (tmp == NULL)
        {
            free(list);
            // ~ Return 1 means that something went wrong -> the program will quit
            return 1;
        }

        tmp[3] = 4;
        free(list);
        list = tmp;

        for (int i - 0; i < 4; i++)
        {
            printf("%i\n", list[i]);
        }

        free(list);
        // ~ Return 0 means that the program was successful
        return 0;
    }
    ```

- [ ] <b>Building a Linked List -> Prepending Nodes:</b>
    - [ ] Defining a `node` structure and inserting new nodes at the beginning.
    ```c
    #include <cs50.h>
    #include <stdio.h>
    #include <stdlib.h>

    // ~ Define a node structure
    typedef struct node
    {
        int number;
        struct node *next;
    } node;

    int main(void)
    {
        // ~ Start with an empty list
        node *list = NULL;

        // ~ Build the list by prepending 3 nodes
        for (int i = 0; i < 3; i++)
        {
            // ~ Allocate memory for a new node
            node *n = malloc(sizeof(node));
            if (n == NULL)
            {
                // ~ Return 1 means that something went wrong -> quit the program
                return 1;
            }

            // ~ Use arrow notation to access fields
            n->number = get_int("Number: ");
            n->next = NULL;

            // ~ Prepend: point new node to current list, then update list
            n->next = list;
            list = n;
        }

        // ~ Print the list using a temporary pointer
        node *ptr = list;
        while (ptr != NULL)
        {
            printf("%i\n", ptr->number);
            ptr = ptr->next;
        }

        // ~ Return 0 means the program was successful
        return 0;
    }
    ```

- [ ] <b>Appending Nodes to the End:</b>
    - [ ] Traversing to the last node and linking the new node there.
    ```c
    // ~ Inside the for loop, after creating node n:
    if (list == NULL)
    {
        //~ List is empty -> this is the first node
        lits = n;
    }
    else
    {
        // ~ Traverse to the end of the list
        for (node *ptr = list; ptr != NULL; ptr = ptr->next)
        {
            if (ptr->next == NULL)
            {
                // ~ Append: point the last node to the new node
                ptr->next = n;
                break;
            }
        }
    }
    ```

- [ ] <b>Sorted Insertion:</b>
    - [ ] Inserting a node in the correct sorted position by comparing values.
    ```c
    // ~ Inside the for loop, after creating node n:
    if (list == NULL)
    {
        list = n;
    }

    // ~ If the new number belongs at the very beginning
    else if (n->number < list->number)
    {
        n->next = list;
        list = n;
    }
    else
    {
        // ~ Traverse to find the right spot
        for (node *ptr = list; ptr != NULL; ptr = ptr->next)
        {
            // ~ If at the end, append
            if (ptr->next == NULL)
            {
                ptr->next = n;
                break;
            }

            // ~ If it belongs in the middle
            if (n->number < ptr->next->number)
            {
                n->next = ptr->next;
                ptr-> next = n;
                break;
            }
        }
    }
    ```

- [ ] <b>Freeing a Linked List:</b>
    - [ ] Traversing the list and freeing each node one by one.
    ```c
    // ~ Free the entire list
    node *ptr = list;
    while (ptr != NULL)
    {
        // ~ Save the next pointer before freeing the current node
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
    ```

<hr>

<h2 align="center">✨ Encompassed Technologies</h2>

- [ ] <b>C Programming Language:</b>
    - [ ] The foundation for building custom data structures. C gives me direct control over memory, which is essential for creating linked lists where each node is dynamically allocated and connected through pointers.
- [ ] <b>Standard Libraries:</b>
    - [ ] `<stdlib.h>` for dynamic memory allocation with `malloc( )`, `realloc( )`, and `free( )`.
    - [ ] `<stdio.h>` for printing and debugging -> `printf( )` is my window into what is happening in memory.
    - [ ] `<cs50.h>` for helpful functions like `get_int( )` and `get_string( )` that make user input easier during development.
- [ ] <b>Pointers and Arrow Notation:</b>
    - [ ] The `->` operator is syntactic sugar for `(*n).field` -> it lets me access struct members through pointers cleanly and readably.
    - [] Understanding that `n->number` means "go to the address in `n`, then access the `number` field" is the key to working with nodes.
- [ ] <b>GCC Compiler:</b>
    - [ ] Translates my C code into machine instructions, managing the stack and heap allocations I dictate with `malloc( )` and `free( )`.
- [ ] <b>Terminal/Command Line:</b>
    - [ ] Where I compile my programs with `make`, execute them with `./program-name`, and pass command-line arguments directly to my programs turning my code into action. It is where my code comes to life.
- [ ] <b>VS Code:</b>
    - [ ] This is my coding sanctuary. a lightweight but powerful source code editor that provides an integrated terminal, syntax highlighting, extensions for writing and extensions for writing and testing code efficiently.
