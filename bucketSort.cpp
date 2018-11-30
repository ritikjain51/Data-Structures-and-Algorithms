#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
void InsertionSort(int*, int);
void SelectionSort(int*, int);
void BucketSort(int*, int);
void SortForBucket(int*, int);
int InsertionSwap = 0, SelectionSwap = 0, BucketSwap = 0;
int InsertionCmp = 0, SelectionCmp = 0, BucketCmp = 0;

void main()
{
	srand(time_t(NULL));
	int size = 100;
	int *arr = (int*) calloc (size, sizeof(int));
	int *arr1 = (int*)calloc(size, sizeof(int));
	int *arr2 = (int*)calloc(size, sizeof(int));
	int i;
	
	for (i = 0; i < size; i++)
	{
		arr[i] = arr1[i] = arr2[i] = rand() % 100 + 0;
	}
	InsertionSort(arr1, size);
	SelectionSort(arr, size);
	BucketSort(arr2, size);
	printf("\nTesting all 3 algorithms with 100's of random number(range 0 - 100)\n\n");
	printf("\n\nComparison in Insertion Sort: %d \t Swaps: %d\n", InsertionCmp, InsertionSwap);
	printf("Comparison in Selection Sort: %d \t Swaps: %d\n", SelectionCmp, SelectionSwap);
	printf("Comparison in Bucket Sort: %d \t\t Swaps: %d\n", BucketCmp, BucketSwap);

	system("pause");
}

void InsertionSort(int* arr, int size)
{
	int i, j, key;
	for (i = 1; i < size; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
			InsertionCmp++;
		}
		arr[j + 1] = key;
		InsertionSwap++;
	}
}

void SelectionSort(int* arr, int size)
{
	int i, j, index, temp;
	for (i = 0; i < size; i++)
	{
		index = i;
		for (j = i + 1; j < size; j++)
		{
			if (arr[index] > arr[j])
			{
				SelectionCmp++;
				index = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[index];
		arr[index] = temp;
		SelectionSwap++;
	}
}

void BucketSort(int* arr, int size)
{
	int **Bucket = (int**)calloc(10, sizeof(int)); // Creating Buckets
	int divisor, buck, index = 0; 
	int i, max= 0, min = arr[0], j;
	int *BucketSize = (int*) calloc (10, sizeof(int)); // Creating Index Count of every Bucket
	for (i = 0; i < 10; i++)
		Bucket[i] = (int*)calloc(10, sizeof(int)); //Creating 10x10 bucket
	

	for (i = 0; i < size; i++)
	{
		if (max < arr[i])
			max = arr[i]; //Finding Max
		if (min > arr[i])
			min = arr[i]; //Finding Mix
	}

	divisor = (int)ceil((max + 1) / (float)10); //Finding Divisor value
	for (i = 0; i < size; i++)
	{
		buck = (int)floor(arr[i] / (float)divisor); //Finding Bucket Value
		Bucket[buck][BucketSize[buck] ++] = arr[i];
	}

	for (i = 0; i < 10; i++)
	{
		SortForBucket(Bucket[i], BucketSize[i]);
		for (j = 0; j < BucketSize[i]; j++)
			arr[index++] = Bucket[i][j];
	}
}

void SortForBucket(int* arr, int size)
{
	int i, j, key;
	for (i = 1; i < size; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
			BucketCmp++;
		}
		arr[j + 1] = key;
		BucketSwap++;
	}
}