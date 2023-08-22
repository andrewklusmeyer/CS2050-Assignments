#include "lab9.h"

void* makeArray(int arraySize, int elementSize) 
{
    int* array = (int*)malloc(arraySize * elementSize + sizeof(int)); 
	//Allocates memory for the array plus the size information
   
   if (array != NULL) 
	{
        *array = arraySize; //Stores the size of the array before the start of the array
        return (void*)(array + 1); //Returns a pointer to the start of the array
    }
    return NULL; //Returns NULL if memory allocation failed
}

int getSize(void* array) 
{
    int* sizePtr = (int*)array - 1; //Retrieves the size pointer by shifting back the pointer by sizeof(int) bytes
    return *sizePtr; //Returns the size of the array stored before the array
}

int searchFlightsRecursive(Flight* array, Flight* query, int low, int high)
{
    if (low > high)
	{
        return -1; //Base case: query was not found
	}

    int mid = low + (high - low) / 2;

    if (compareFlights(&array[mid], query) == 0)
	{
        return mid; //Base case: query was found at mid index
	}
	
	//Recursively searches the right half
    if (compareFlights(&array[mid], query) < 0)
	{
        return searchFlightsRecursive(array, query, mid + 1, high);
	}		
	
	//Recursively searches the left half
    return searchFlightsRecursive(array, query, low, mid - 1); 
	
}

int searchFlights(Flight* array, Flight* query)
{
    int size = getSize(array); //Gets the size of the array
    return searchFlightsRecursive(array, query, 0, size - 1);
}


int compareFlights(Flight* a, Flight* b) 
{
    if (a -> distance < b -> distance) 
	{
        return -1; //Returns a strictly negative number if a < b
    }
    else if (a -> distance > b -> distance) 
	{
        return 1; //Returns a strictly positive number if a > b
    }
    
	else 
	{
        return 0; //Returns 0 if a and b are equal
    }
}

void freeArray(void* array) 
{
    int* sizePtr = (int*)array - 1; //Retrieves the size pointer by shifting back the pointer by sizeof(int) bytes
    free(sizePtr); //Frees the memory allocated for the array (including the size information)
}
