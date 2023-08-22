#include <stdio.h>
#include <stdlib.h>
#include "lab1.h"

#define SIZE 5

int main(void)
{
	int array[SIZE] = {-513,-198,0,63,160};
	float avgResult = 0;
	int sumResult = 0;
	
	printf("\nHere's your array:\n");
	for(int i = 0; i < SIZE; i++)
	{
		printf("array[%d] = %d\n",i,array[i]);
	}
	printf("\n");
	
	
	
	float averageTesting = 0;
	for(int j = 0; j < SIZE; j++)
	{
		averageTesting = averageTesting + array [j];
	}
	averageTesting = averageTesting / SIZE;
	
	getAverage(array, SIZE, &avgResult);
	printf("The average of the array should be: %f\nThe value returned by getAverage is: %f\n\n",averageTesting,avgResult);
	
	
	int sumTesting = 0;
	for(int i = 0; i < SIZE; i++) 
	{
		if(array[i] > 0) 
		{
			sumTesting = sumTesting + array[i]; 
			
		}
	}
	sumPositive(array, SIZE, &sumResult);
	printf("The sum of all positive values in the array should be: %d\nThe value returned by sumPositive is: %d\n\n",sumTesting,sumResult);
}
	