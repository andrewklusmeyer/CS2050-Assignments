#include "lab2.h"

int main(void)
{
	int *array = NULL; //Declare a pointer to an integer and initialize it to NULL
    int size = 5; //Size of the array
    int multiplicand = 2; //Multiplicand for multiplyEven

    //Make the array
    int makeArrayResult = makeArray(&array, size); //Allocate memory for the array
    if (makeArrayResult == 0) //Check if the array allocation is successful
    {
        initArray(array, size);
		
		array[0] = -4;
		array[1] = 5;
		array[2] = 0;
		array[3] = 2;
		array[4] = -7;
		
		printf("\nModifying the array in main...\n");
		for(int j = 0; j < size; j++)
		{
			printf("array[%d] is now %d.\n",j,array[j]);
		}
		
        //Multiply the even elements of the array
        int multiplyCount = multiplyEven(array, size, multiplicand); //Multiply even elements of the array
        printf("\nNumber of even elements multiplied: %d\n", multiplyCount);

        //Free the array
        freeArray(&array); //Free the memory allocated for the array
    }
	
    else
    {
        printf("MAIN: Array allocation failed!\n"); //Print an error message if array allocation fails
    }
}