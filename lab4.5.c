#include "lab4.5.h"
#include <stdio.h>
#include <stdlib.h>

void **AllocateJagged2DArray(int elementSize, int rows, int lengths[]) 
{
    void **arrayJagged = (void **)malloc(rows * sizeof(void *)); //Allocate memory for the row pointers
   
   if (arrayJagged == NULL) //Checks for malloc failure
    {
		#ifdef DEBUG //Checks for debug "setting"
		{
			printf("DEBUG: Failed to allocate memory for the jagged array in AllocateJagged2DArray...\n");
		}
		#endif //Ends debugging exclusive code
		
        return NULL; //Returns error code of NULL
    }

    
    for (int i = 0; i < rows; i++) 
	{
        arrayJagged[i] = malloc(lengths[i] * elementSize); //Allocate memory for each row
       
	   if (arrayJagged[i] == NULL) //Checks for malloc failure
	   {
		   #ifdef DEBUG //Checks for debug "setting"
		   {
			   printf("DEBUG: Failed to allocate memory for row %d in AllocateJagged2DArray...\n", i);
		   }
		   #endif //Ends debugging exclusive code
            
            for (int j = 0; j < i; j++) 
			{
                free(arrayJagged[j]); //Free the previously allocated memory
            }
            free(arrayJagged); //Frees pointer
            return NULL; //Returns NULL as error code
        }
    }

    return arrayJagged;
}

void FreeJagged2DArray(void **arrayJagged) 
{
	int rows = GetRowCount(arrayJagged);
	
    for (int i = 0; i < rows; i++) 
	{
        free(arrayJagged[i]); //Free memory for each row
    }
	
    free(arrayJagged); // Free memory for the row pointers
}

int GetRowCount(void **arrayJagged) 
{
    //The number of rows is not stored explicitly, so it's assumed the array ends with a NULL pointer
	
    int count = 0;
    while (arrayJagged[count] != NULL) 
	{
        count++;
    }
    return count;
}

/*
int GetColCount(void **arrayJagged, int row) 
{
    
    if (arrayJagged[row] == NULL) //Check if the specified row is valid
	{
		#ifdef DEBUG //Checks for debug "setting"
		{
			printf("Invalid row index.\n");
		}
		#endif //Ends debugging exclusive code
		
        return -1;
    }

    
    int *rowPtr = (int *)arrayJagged[row]; //Cast the row pointer to the appropriate type

    
    int count = 0;
    while (rowPtr[count] != NULL) //Loops to calculate the number of elements in the row
	{
        count++;
    }
	
    return count;
}
*/
