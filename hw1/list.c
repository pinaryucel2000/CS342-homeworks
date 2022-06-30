#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

typedef struct node
{
    int data;
    struct node *next;
} node, *np, **npp;

// Creates a dummy head and returns it
np createList()
{
    // Allocate memory for the head node
    np hp = (struct node *)malloc(sizeof(struct node));

    // Assign data -1 as a flag to indicate root
    hp->data = -1;

    hp->next = NULL;
    return hp;
}

void push(np head, int newElement)
{
    // Allocate memory for the new node
    np nnp = (struct node *)malloc(sizeof(struct node));

    nnp->data = newElement;
    nnp->next = NULL;

    // Get the tail node pointer
    while (head->next != NULL)
    {
        head = head->next;
    }

    // New node becomes the tail
    head->next = nnp;
}

// Returns the current time in microseconds
unsigned long getCurrentTime()
{
    struct timeval timeValue;
    gettimeofday(&timeValue, NULL);
    unsigned long currentTime = timeValue.tv_usec;
    currentTime = currentTime + timeValue.tv_sec * 1e6;
    return currentTime;
}

// Pushes indicated number of elements to the linked list and prints the time taken for pushing in micro seconds
void initializeListRandomly(np head, int size)
{
    // Safeguard
    if (head == NULL)
    {
        return;
    }

    unsigned long start;
    unsigned long end;
    int i = 0;
    srand(time(NULL));

    start = getCurrentTime();

    for (i = 0; i < size; i++)
    {
        push(head, rand());
    }

    end = getCurrentTime();

    printf("Time taken to push %d random elements to the linked list is %ld micro seconds\n", size, end - start);
}

// Deletes all of the nodes of a linked list
void deleteList(npp hpp)
{
    np current = *hpp;
    np next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    *hpp = NULL;
}

// Returns the size of a linked list excluding the dummy head
int listSize(np head)
{
    if (head == NULL)
    {
        return 0;
    }

    int size = 0;

    for (int i = 1; head->next != NULL; i++)
    {
        head = head->next;
        size = i;
    }

    return size;
}

// Prints the elements of a linked list excluding the dummy head
void printList(np head)
{
    if (head != NULL)
    {
        if (head->data != -1)
        {
            printf("%d\n", head->data);
        }

        printList(head->next);
    }
}

int main()
{
    // Create the dummy head
    np hp = createList();

    printf("List size: %d\n", listSize(hp));
    initializeListRandomly(hp, 10000);
    printf("List size: %d\n", listSize(hp));

    // Deallocate memory
    deleteList(&hp);
}
