#include "lab8.h"

typedef struct Node Node;

struct Node 
{
    int priority;
    void* data;
    Node* next;
};

struct Info 
{
    int size;
    int error;
    Node* head;
};

Node* makeNode(void* data, Node* next, int priority) 
{
	Node* n = malloc(sizeof(Node));

    if(n) 
	{
        n -> data = data; //Assigns the data to the node
        n -> next = next; //Assigns the next pointer to the node
        n -> priority = priority; //Assigns the priority to the node
    }

    return n; //Returns the created node
}

void* freeNode(Node* n) 
{
    if(n) 
	{
        void* data = n -> data; //Retrieves the data from the node
        free(n); //Frees the memory allocated for the node
        return data; //Returns the data
    }

    return NULL;
}

int pqGetErrorCode(PQueue q) 
{
    return q.info -> error; //Returns the error code from the PQueue
}

int pqGetSize(PQueue q) 
{
    return q.info -> size; //Returns the size of the PQueue
}

PQueue pqInit() 
{
    PQueue q;
    q.info = malloc(sizeof(Info)); //Allocates memory for the Info struct of the PQueue

    if (q.info) 
	{
        q.info -> error = 0; //Sets the error code to 0
        q.info -> size = 0; //Sets the size to 0
        q.info -> head = NULL; //Sets the head pointer to NULL
    }

    return q; //Returns the initialized PQueue
}

int pqInsert(void *data, int priority, PQueue q) 
{
    Node *n = makeNode(data, NULL, priority); //Creates a new node with the given data and priority

    if (!n) 
	{
        q.info -> error = 1; //Sets the error code to 1 if node creation failed
        return 1; //Returns 1 to indicate failure
    } 
	else if (!q.info -> head || q.info -> head -> priority < priority) 
	{
        n -> next = q.info -> head; //Inserts the node at the beginning if the PQueue is empty or the new node has the highest priority
        q.info -> head = n;
    } 
	else 
	{
        Node *current = q.info -> head;

        while (current -> next && current -> next -> priority >= priority) 
		{
            current = current -> next; //Traverses the PQueue until finding the position to insert the new node
        }

        n -> next = current -> next; //Inserts the new node at the correct position
        current -> next = n;
    }

    q.info -> size++; //Increases the size of the PQueue
    q.info -> error = 0; //Sets the error code to 0
    return 0; //Returns 0 to indicate success
}

void* pqRemoveMax(PQueue q) 
{
    if (!q.info -> head) 
    {
        q.info -> error = 2; //Sets the error code to 2 if the PQueue is empty
        return NULL; //Returns NULL since the PQueue is empty
    }

    Node* n = q.info -> head; //Gets the node at the front of the PQueue
    q.info -> head = n -> next; //Updates the head pointer to the next node
    q.info -> size--; //Decreases the size of the PQueue

    q.info -> error = 0; //Sets the error code to 0
    void* data = n -> data; //Gets the data from the node
    freeNode(n); //Frees the memory allocated for the node
    return data; //Returns the data
}


void* pqPeek(PQueue q) 
{
    if (!q.info -> head) 
	{
        q.info -> error = 2; //Set the error code to 2 if the PQueue is empty
        return NULL;
    }

    q.info -> error = 0; //Set the error code to 0
    return q.info -> head -> data; //Return the data at the front of the PQueue
}

void pqFree(PQueue q) 
{
    while (q.info -> head != NULL) 
    {
        Node* current = q.info -> head; //Get the node at the front of the PQueue
        q.info -> head = current -> next; //Update the head pointer to the next node
        freeNode(current); //Free the memory allocated for the current node
    }

    free(q.info); //Free the memory allocated for the Info struct of the PQueue
}


