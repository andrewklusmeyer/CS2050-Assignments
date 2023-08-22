#include "lab3.h"


/****************************************************
The following function "strAlloc" will allocate memory 
for a string of characters. When passed the desired
size of the string as an integer, it will allocate
the correct amount of memory along with storing the
size before the string for later use. If the function
is unable to allocate the memory, it will return NULL.
Otherwise, it will return the pointer to the array.
****************************************************/

char * strAlloc(int size)
{
	if(size > 0)
	{
		char *charArray = malloc((size * sizeof(char)) + sizeof(int)); //Allocates desired size + space for hidden size integer
		if(charArray != NULL) //Checks for malloc success
		{
			#ifdef DEBUG //Checks for DEBUG setting
			{
				printf("DEBUG: Malloc has succeded!\n"); //prints success message
			}
			#endif //Ends debugging exclusive code
		}
		
		else
		{
			#ifdef DEBUG //Checks for DEBUG setting
			{
				printf("Error! Malloc has failed!\n"); //prints fail message
			}
			#endif //Ends debugging exclusive code
			
			return NULL; //Returns NULL representing an error
		}
	
		charArray[0] = size; //Assigns size integer to 0th element
		charArray = charArray + sizeof(int); //Reassigns the pointer to point ahead of the hidden size integer
		
		#ifdef DEBUG //Checks for DEBUG setting
		{
		//	printf("DEBUG: Testing hidden size...\nSize is supposed to be %d but actually is %d\n", size, (int)charArray[-1]);
		}
		#endif //Ends debugging exclusive code
	
		return (char*)charArray;
	}
	
	else
	{
		#ifdef DEBUG //Checks for DEBUG setting
		{
			printf("DEBUG: Invalid size passed to strAlloc.\n");
		}
		#endif //Ends debugging exclusive code
		
		return NULL; //Returns NULL representing an error condition
	}
}

/*****************************************************************
The following function "strLen" will be passed a pointer to 
a string that was created using "strAlloc". It will then create
a temporary copy and return the integer value representing the size.
If the pointer that was passed to the function is NULL, the function
will return an error value of -1.
******************************************************************/

int strLen(char *str)
{
	if(str != NULL) //Checks for valid pointer
	{
		int* tempArray = (int*)str - 1; //Creates and assigns tempArray[0] to be the size value
		return (tempArray[0]); //Returns hidden size variable
	}
	else
	{
		#ifdef DEBUG //Checks for DEBUG setting
		{
			printf("DEBUG: Invalid pointer passed to strLen.\n");
		}
		#endif //Ends debugging exclusive code
		
		return -1; //Returns error code
	}
}

/**************************************************************
The following function "strCpy" will be passed two pointers, in
which, were previously created using "strAlloc". It will then loop
through the source string as long as the source has not reached the 
NULL terminator and assign the value at the current position to the
destination string. It is assumed that the destination string will 
have enough allocated space to execute this function.
**************************************************************/

void strCpy(char *source, char *dest)
{
	int tempLength = strLen(source);
	if(source != NULL && dest != NULL) //Checks for valid pointers
	{
		for(int i = 0; i < tempLength; i++) //Begins looping through source string
		{
			dest[i] = source[i]; //Copies from source into destination
		}
	}
	
	else
	{
		#ifdef DEBUG //Checks for DEBUG setting
		{
			printf("DEBUG: Invalid pointer passed to strCopy.\n");
		}
		#endif //Ends debugging exclusive code
	}
}

/**************************************************************
The following function "strRev" will be passed two pointers, in
which, were previously created using "strAlloc". It will then loop
through the source string by using a the length given by strLen
and assign the value at the current position to the reverse in the
destination string. It is assumed that the destination string will 
have enough allocated space to execute this function.
**************************************************************/

int strRev(char *source, char *dest)
{
	int stringLengthSource = strLen(source) - 1;
	int stringLengthDest = strLen(dest) - 1;
	int tempCounter = 0;
	
	if(source != NULL && dest != NULL && stringLengthSource > 0 && stringLengthDest > 0) //Checks for valid pointers and size
	{
		for(int i = stringLengthSource; i >= 0; i--)
		{
			dest[tempCounter] = source[i];
			#ifdef DEBUG //Checks for DEBUG setting
			{
				printf("DEBUG: source[%d] = %c\ndest[%d] = %c\n",i,source[tempCounter],i,dest[tempCounter]);
			}
			#endif //Ends debugging exclusive code
			tempCounter++;
		}
		
		if(stringLengthSource == stringLengthDest)
		{
			return 1; //Returns value representing the strings are the same size
		}
		else 
		{
			return 0; //Returns value representing the strings are different sizes
		}
		
	}
	
	else
	{
		#ifdef DEBUG //Checks for DEBUG setting
		{
			printf("DEBUG: Invalid pointer passed to strRev.\n");
		}
		#endif //Ends debugging exclusive code
		
		return -1; //Returns an error code
	}
	
}
	
	
	
/***************************************************
The following function "strFree" will free a string
in which was previously created by "strAlloc". After
being passed the string, it will reassign the pointer
and free the memory. It will then check to ensure successful
execution
****************************************************/
void strFree(char *str)
{
	if(str != NULL)
	{
		str = str - sizeof(int); //Reassigns pointer
		free(str); //frees string
		str = NULL; //frees pointer
	
		if(str == NULL) //Checks for successful execution
		{
			printf("Memory Sucessfully Freed!\n"); //prints success message
		}
		else
		{
			printf("Error! Couldn't Free Memory.\n"); //prints error
		}
	}
	else
	{
		#ifdef DEBUG
		{
			printf("DEBUG: Invalid pointer passed to strFree.\n");
		}
		#endif
	}
}
