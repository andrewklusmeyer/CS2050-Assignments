#include "lab5.h"

int makeList(Node** list) 
{
	if(list != NULL)
	{
		*list = NULL; //Intializes head pointer to NULL
		return 0;
	}
	
	else
	{
		#ifdef DEBUG //Checks for debug "setting"
		{
			printf("DEBUG: NULL pointer passed to makeList...\n");
		}
		#endif //Ends debug exclusive code
		
		return -1; //Returns error code of -1
	}
	
}

int getSize(Node* list) 
{
	if(list != NULL) //Checks for empty list
	{
		int count = 0; //Intializes temporary count variable
		Node* current = list; //Creates a copy of the head pointer
	
		while (current != NULL) //Traverses the list
		{
			count++; //Increases count variable
			current = current->next; //Moves current pointer
		}
		return count;
	}
	
	else
	{
		#ifdef DEBUG //Checks for debug "setting"
		{
			printf("DEBUG: Empty list detected in getSize...\n");
		}
		#endif //Ends debug exclusive code
		
		return 0;
	}		
}

int insertAtHead(Node** list, void* data) 
{
	if(list != NULL && data != NULL)
	{
		Node* newNode = (Node*)malloc(sizeof(Node)); //Allocates memory for new node
    
		if (newNode == NULL) //Checks for malloc failure
		{
			#ifdef DEBUG //Checks for debug "setting"
			{
				printf("DEBUG: Malloc failed in insertAtHead...\n");
			}
			#endif //Ends debug exclusive code
			
			return 1; //Returns error code of 1
		}
    
		newNode->data = data; //Assigns data into new node
		newNode->next = *list; //Assigns next pointer to old head of list
		*list = newNode; //Assigns new node to head of list
    
		return 0; // Returns 0 as successful code
	}
	
	else
	{
		#ifdef DEBUG //Checks for debug "setting"
		{
			printf("DEBUG: Invalid pointer passed to insertAtHead...\n");
		}
		#endif //Ends debug exclusive code
		
		return 1; //Returns error code of 1
	}
}



void* removeFromTail(Node** list) 
{
	if(list != NULL) //Checks for valid pointer
	{
		if (*list == NULL) //Checks for empty list
		{
			return NULL; //Returns NULL error code
		}
    
		if ((*list)->next == NULL) //Checks for special case of only 1 node in list
		{
			void* data = (*list)->data; //Holds data in node that will soon be removed
			free(*list); //Frees the memory allocated to the only node in the list
			*list = NULL; //Sets the list pointer to NULL since the list is now empty
			return data; //Returns the data of the removed node
		}
    
		Node* previous = NULL; //Intializes pointer to track the previous node
		Node* current = *list; //Initializes pointer to track the current node
    
		while (current->next != NULL) 
		{
			previous = current; //Moves the previous pointer to the current node
			current = current->next; //Moves the current pointer to the next node
		}
    
		void* data = current->data; //Saves the data of the last node
    
		free(current); //Frees the memory allocated to the last node
    
		previous->next = NULL; //Sets the next pointer of the previous node to NULL, making it the new tail of the list
    
		return data; //Returns the data of the removed last node
	}
	
	else
	{
		#ifdef DEBUG //Checks for debug "setting"
		{
			printf("DEBUG: Invalid pointer passed to removeFromTail...\n");
		}
		#endif //Ends debug exclusive code
		
		return NULL;
	}
}



void freeList(Node** list) 
{
	if(list != NULL) //Checks for valid pointer
	{
		Node* current = *list; //Creates copy of head pointer
	
		while (current != NULL) 
		{
			Node* next = current->next; //Maintains a pointer to the next node in the list
			free(current); //Frees current node
			current = next; //Moves current pointer to next node
		}
	
		*list = NULL; //Frees list pointer
	}
}
