#include "lab10.h" 

int * createArray(int size) 
{
	#ifdef DEBUG //Checks for debug "setting"
	{
		printf("DEBUG: Entered into createArray...\n"); 
	}
	#endif //Ends dedugging exclusive code
	
	int *array = malloc(sizeof(int) * size + sizeof(int)); //Allocates memory for the array based on the given size
	if(array) //Checks if the memory allocation was successful
	{
		#ifdef DEBUG //Checks for debug "setting"
		{
			printf("DEBUG: Successfully allocated array in createArray...\n");
		}
		#endif //Ends dedugging exclusive code
		
		*array = size; //Stores the size of the array at the first element
		++array; //Increments the array pointer to skip the first element
	}
	
	return array; //Returns the pointer to the allocated array
}

int getSize(int *array) 
{
	#ifdef DEBUG //Checks for debug "setting"
	{
		printf("DEBUG: Entered into getSize...\n");
	}
	#endif //Ends dedugging exclusive code
	
	return array[-1]; //Returns the value stored at the index -1 of the array, in which, is the hidden size
}

int binarySearch(int *array, int value) 
{
	#ifdef DEBUG //Checks for debug "setting"
	{
		printf("DEBUG: Entered into binarySearch...\n"); 
	}
	#endif //Ends dedugging exclusive code
	
	int min = 0, max = getSize(array); //Initializes the search range with min and max values
	int median = max / 2; //Calculates the initial median index

	while(max > min) //Loops until the search range is narrowed down to a single element
	{
		if(array[median] == value) //If the middle element matches the target value
		{
			return median; //Returns the index of the match
		} 
		
		else if(array[median] > value) //If the middle element is greater than the target value
		{
			max = median - 1; //Updates the max to search the left half
		} 
		
		else //If the middle element is smaller than the target value
		{
			min = median + 1; //Updates the min to search the right half
		}
		
		//This line was initially "median = max / 2"
		median = min + (max - min) / 2; //Calculates the new middle index
	}
	
	return -1; //Returns -1 to indicate the target value was not found
}

void freeArray(int *array) 
{
	#ifdef DEBUG //Checks for debug "setting"
	{
		printf("DEBUG: Entered into freeArray...\n"); 
	}
	#endif //Ends dedugging exclusive code 
	
	free(array - 1); //Frees the memory allocated for the array (adjusting the pointer to the size element)
}
