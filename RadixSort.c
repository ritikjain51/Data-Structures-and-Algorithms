#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main()
{
	int arr[100], i, j;
	int bucket[10][100], divisor = 1, bucket_count[10], pass = 0;
	int rem = 1, index;
	int largest = 0;
	int size;
	srand(time(NULL));
	printf("Enter the size: ");
	scanf_s("%d", &size);
	printf("My Initial array is: \n");
	for (i = 0; i < size; i++)
	{
		arr[i] = rand() % 1500000 + 200; //Genereting Random Number 
		printf("%d  ", arr[i]);
		if (largest < arr[i]) // Checking for the largest number
			largest = arr[i]; 
	}
	printf("\n\nValue changing after every pass:\n\n");
	while (largest > 0) // Taking the number of passes
	{
		for (i = 0; i < size; i++) // Initializing bucket with all 0's 
			for (j = 0; j < 10; j++)
				bucket[i][j] = 0;

		for (i = 0; i < 10; i++) // Intitializing each bucket size with 0's
			bucket_count[i] = 0;

		for (i = 0; i < size; i++)
		{
			rem = (arr[i] / divisor) % 10; // Taking the unit digit by dividing
			bucket[rem][bucket_count[rem]++] = arr[i]; // Putting value in the bucket
		}

		divisor *= 10;
		largest /= 10;
		index = 0;
		printf("After %d pass -->  ", ++pass);
		for (i = 0; i < 10; i++)
		{
			for (j = 0; j < bucket_count[i]; j++)
			{
				arr[index++] = bucket[i][j]; // Taking out every value from bucket and putting back to array
				printf("%d  ", arr[index - 1]);
			}
		}
		printf("\n");
	}
	
	system("pause");
}