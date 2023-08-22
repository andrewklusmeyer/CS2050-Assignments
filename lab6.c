#include "lab6.h"


int makeList(Node** list) 
{
    if (list == NULL) //Checks for valid passed pointer
	{
		#ifdef DEBUG //Checks for debug "setting"
		{
			printf("DEBUG: Invalid pointer passed to makeList...\n");
		}
		#endif //Ends debugging exclusive code
		
        return 1; //Returns error code
    }
	
    *list = (Node*)malloc(sizeof(Node)); //Allocates memory for dummy node
    if (*list == NULL) //Checks for malloc failure
	{
		#ifdef DEBUG //Checks for debug "setting"
		{
			printf("DEBUG: Malloc failed in makeList...\n");
		}
		#endif //Ends debugging exclusive code
		
        return 1; //Returns error code
    }
	
    (*list) -> next = NULL; //Initializes dummy node
    (*list)-> data = NULL; //Initializes dummy node
	
    return 0; //Returns successful error code
}

int getSize(Node* list) 
{
    if (list == NULL) //Checks for valid pointer
	{
		#ifdef DEBUG //Checks for debug "setting"
		{
			printf("DEBUG: Invalid pointer passed to getSize...\n");
		}
		#endif //Ends debugging exclusive code
			
        return 0; //Returns 0 as size
    }
	
	if(list -> next == NULL) //Checks for NULL at node past the dummy node
	{
		#ifdef DEBUG //Checks for debug "setting"
		{
			printf("DEBUG: Empty list detected in getSize...\n");
		}
		#endif //Ends debugging exclusive code
		
		
		return 0; //Returns 0 as size
	}
	
    int count = 0; //Initializes temporary counting variable
	
    Node* current = list -> next; //Intializes a temporary pointer to traverse the list
    while (current != NULL) //Checks if the current pointer is pointing to NULL
	{
        count++; //Increments the counter
        current = current->next; //Moves the current pointer to the next node in the list
    }
    return count; //Returns the value held in the counter variable
}

void* getAtIndex(Node* list, int index) 
{
    if (list == NULL || index < 0 || index >= getSize(list)) //Checks for valid parameters
	{
		#ifdef DEBUG //Checks for debug "setting"
		{
			printf("DEBUG: Invalid pointer or index value passed to getAtIndex...\n");
		}
		#endif //Ends debugging exclusive code
		
        return NULL; //Returns NULL error code
    }
	
    Node* current = list->next; //Creates temporary current pointer
	
    int i = 0; //Creates loop variable for finding the node
    while (i < index) 
	{
        current = current -> next; //Moves the current pointer
        i++; //Increases the loop variable
    }
    return current->data; //Returns data held in node
}

int insertAtTail(Node* list, void* data) 
{
    if (list == NULL) //Checks for valid pointer
	{
		#ifdef DEBUG //Checks for debug "setting"
		{
			printf("DEBUG: Invalid pointer passed to insertAtTail...\n");
		}
		#endif //Ends debugging exclusive code
		
        return 1; //Returns error code of 1
    }
    
	Node* newNode = (Node*)malloc(sizeof(Node)); //Allocates memory for the new node
    if (newNode == NULL) //Checks for malloc failure 
	{
		#ifdef DEBUG //Checks for debug "setting"
		{
			printf("DEBUG: Malloc failed in insertAtTail...\n");
		}
		#endif //Ends debugging exclusive code
		
        return 1; //Returns error code of 1
    }
    
	newNode -> next = NULL; //Intializes new node
    newNode -> data = data; //Intializes new node

    Node* current = list; //Creates a current pointer to traverse the list
	while (current -> next != NULL) //Loop to traverse the list
	{
        current = current->next; //Moves current pointer
    }
    current->next = newNode; //Assigns the next pointer of the last node to point to the new node

    return 0; //Returns successful error code
}

void* removeFromHead(Node* list) 
{
    if (list == NULL) //Checks for valid pointer
	{
		#ifdef DEBUG //Checks for debug "setting"
		{
			printf("DEBUG: Invalid pointer passed to removeFromHead...\n");
		}
		#endif //Ends debugging exclusive code
		
        return NULL; //Returns NULL error code
    }
	
    Node* head = list -> next; //Creates a head pointer that points to the first node in the list
    list -> next = head -> next; //Updates next pointer to remove first node
    void* data = head -> data; //Saves data held in node
    free(head); //Frees the node
    return data; //Returns the data
}

void freeList(Node** list) 
{
    if (list == NULL || *list == NULL) //Checks for valid pointer
	{
		#ifdef DEBUG //Checks for debug "setting"
		{
			printf("DEBUG: Invalid pointer passed to freeList...\n");
		}
		#endif //Ends debugging exclusive code
		
        return; 
    }
	
    Node* current = (*list) -> next; //Creates a pointer to traverse the list
    while (current != NULL) //Loop to traverse the list
	{
        Node* temp = current; //Updates temporary pointer
        current = current -> next; //Updates current pointer
        free(temp); //Frees the node behind the current pointer
    }
    free(*list); //Frees the allocated memory for list
    *list = NULL; //Sets the pointer to NULL
}


