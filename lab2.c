#include "lab2.h"

int makeArray(int **array, int size)
{
	
	if(array != NULL) //Checks for valid pointer
	{
		
		if(size > 0) //Checks for valid size
		{
			*array = malloc(sizeof(int) * size); //Allocates memory for an integer array of given size
		
			if (*array != NULL) //Checks for malloc success
			{
				#ifdef DEBUG //Checks for DEBUG setting
				{
					printf("\nDEBUG: Malloc in makeArray Succeeded!\n"); //Prints success message if memory allocation is successful
				}
				#endif //Ends debugging exclusive code
				
				return 0;
			}
	
			else
			{
				#ifdef DEBUG //Checks for DEBUG setting
				{
					printf("\nDEBUG: Malloc in makeArray Failed!\n"); //Prints error message if memory allocation fails
				}
				#endif //Ends debugging exclusive code
			
				return 1;
			}
		}
	
	
	
		else
		{
			#ifdef DEBUG //Checks for DEBUG setting
			{
				printf("\nDEBUG: Invalid size detected in makeArray!\n");
			}
			#endif  //Ends debugging exclusive code
		
			return 1;
		}
	}
	
	else
	{
		#ifdef DEBUG //Checks for DEBUG setting
		{
			printf("\nDEBUG: Invalid pointer detected in makeArray!\n");
		}
		#endif  //Ends debugging exclusive code
		
		return 1;
	}
	

}

void initArray(int *array, int size)
{
	if(size > 0)
	{
		if(array != NULL)
		{
			#ifdef DEBUG //Checks for DEBUG setting
			{
				printf("\nDEBUG: Initializing the array...\n");
			}
			#endif //Ends debugging exclusive code
	
			for (int i = 0; i < size; i++)
			{
				array[i] = 0; //Initializes each element of the array to 0
		
				#ifdef DEBUG //Checks for DEBUG setting
				{
					printf("DEBUG: array[%d] has been set to %d.\n",i,array[i]);
				}
				#endif //Ends debugging exclusive code
			}
		}
	}
}

int multiplyEven(int *array, int size, int multiplicand)
{
	int tempCount = 0; //Initializes a temporary count variable to 0
	
	#ifdef DEBUG //Checks for DEBUG setting
	{
		printf("\nDEBUG: Multiplying the even values in the array...\n");
	}
	#endif //Ends debugging exclusive code
	
	if(size > 0) //Checks for valid size
	{
		if(array != NULL)
		{
	
			for (int i = 0; i < size; i++)
			{
				if (array[i] % 2 == 0) //Checks if the current array element is even
				{
					#ifdef DEBUG //Checks for DEBUG setting
					{
						printf("DEBUG: The value of array[%d] before being multiplied is %d.\n",i,array[i]);
					}
					#endif //Ends debugging exclusive code
			
					array[i] = array[i] * multiplicand; //Multiplies the even element by the multiplicand
			
					#ifdef DEBUG //Checks for DEBUG setting
					{
						printf("DEBUG: The value of array[%d] after being multiplied is %d.\n",i,array[i]);
					}
					#endif //Ends debugging exclusive code
			
					tempCount++; //Increments the temporary count variable
				}
			}
		}
	}

    return tempCount; //Returns the count of even elements that were multiplied
}

void freeArray(int **array)
{
	if(array != NULL) //Checks for valid pointer
	{	
		free(*array); //Releases the memory allocated for the array back to the operating system
		*array = NULL; //Frees the pointer by setting it to NULL
	

		if (*array == NULL) //Checks if the pointer has successfully been freed
		{
			#ifdef DEBUG //Checks for DEBUG setting
			{
				printf("DEBUG: Memory successfully freed!\n"); //Prints a success message
			}
			#endif //Ends debugging exclusive code
		}
	}
}
