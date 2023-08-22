#include <stdio.h>
#include <stdlib.h>
#include "lab1.h"

/*****************************************************
The following function "getAverage" will be passed an
array, an integer representing the size, and a pointer
representing the result that will be returned by this
function. It will first check for a valid size value.
If the size is an integer less than 1, it will return 1.
However, if the size is valid, the function will then 
calculate the average of the array by looping through
the array for the total and dividing by the size value.
The calculated average will be assigned to the pointer
representing the result and the function will return 0.
********************************************************/
  
int getAverage (int array [], int size, float* result)
{
	if(size < 1) //Checks for valid size value
	{
		return 1; //Returns error code
	}
	
	float total = 0; //Intializes variable representing total of array
	for(int i = 0; i < size; i++) //Loops through array
	{
		total = total + array[i]; //Assisns total of values in array
	}
	
	*result = (total / size); 
	//Assigns the average by taking the variable representing the total and
	//dividing it by the size passed to the function
		
	return 0; //Returns success error code
}



/*******************************************************
The following function "sumPositive" will be passed an
array, an integer representing the size of the array, and
an integer pointer representing the result that will be
returned from this function. First, the function will check
for a valid size. If the size is an integer value less than
1, the function will return the error code 1 to the user.
However, if the size passed to the function is valid,
the function will then loop through the array and check for
any values greater than 0. If the value in the array is 
greater than 0, it will be added to the tempSum variable.
After looping through the array, the value in the tempSum
variable is assigned to the result pointer and the function
returns with the success error code 0.
********************************************************/

int sumPositive(int array[], int size, int *result)
{
	if(size < 1) //Checks for valid size
	{
		return 1; //Returns error code
	}
	
	int tempSum = 0; //Intializes variable for sum of all positive values
	
	for(int i = 0; i < size; i++) //Begins looping through array
	{
		if(array[i] > 0) //Checks if the value in the Ith element is positive
		{
			tempSum = tempSum + array[i]; 
			//Assigns the tempSum value to be the value of all positive values
		}
	}
	
	*result = tempSum; //Assigns the value held in tempSum to the pointer representing the result
	
	return 0; //Returns success error code
	
}

	
	