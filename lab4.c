#include "lab4.h"

void *makeArray(int arraySize, int elementSize) 
{
	if(arraySize > 0 && elementSize > 0) //Checks for valid sizes
	{
	    void *array = malloc(elementSize * arraySize + sizeof(int)); //Allocate memory for the array plus the size of an int
		if (array != NULL) 
		{        
			*(int *)array = arraySize; //Store the array size before the start of the array
        
			return (int *)array + 1; //Return a pointer to the array, adjusted by 1 int size
		}
	
		else 
		{
			#ifdef DEBUG //Checks for debug "setting"
			{
				printf("DEBUG: Malloc failed in makeArray...\n");
			}
			#endif //Ends debugging exclusive code
			
			return NULL; //Returns NULL as an error code
		}
	}
	
	else
	{
		#ifdef DEBUG //Checks for debug "setting"
		{
			printf("DEBUG: Invalid sizes passed to makeArray...\n");
		}
		#endif //Ends debugging exclusive code
		
		return NULL; //Returns NULL as an error code
	}
}
	

int getSize(void *array) 
{
	if(array != NULL) //Checks for valid pointer
	{
		return *((int *)array - 1); // Retrieve the size stored before the array by subtracting 1 int size from the pointer
	}
	
	else
	{
		#ifdef DEBUG //Checks for debug "setting"
		{
			printf("DEBUG: Invalid pointer passed to getSize...\n");
		}
		#endif //Ends debugging exclusive code
		
		return -1; //Returns error code of -1
	}
}

int countWithColors(InventoryItem *items, short colorCount);
{
    if(items != NULL && colorCount >= 0)
	{		
		int arraySize = getSize(items); //Get the size of the array using getSize function
		int tempCount = 0; //Intializes temporary counting variable
	
		for (int i = 0; i < arraySize; i++) 
		{
			if (items[i].colors == colorCount) //Checks if the color in the array is equal to the query
			{
				count++; //Increases value in counting variable
			}
		}
		return count; //Returns number in counting variable
	}
}

void freeArray(void *array) 
{
	if(array != NULL)
	{
		free((int *)array - 1); //Free the memory allocated to the array by subtracting 1 int size from the pointer
	}
	
	else
	{
		#ifdef DEBUG
		{
			printf("DEBUG: Invalid pointer passed to freeArray...\n");
		}
		#endif
	}
}
