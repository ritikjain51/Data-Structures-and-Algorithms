#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct node
{
	struct node* next;
	int data;
}Node;

Node* initial(Node*, int);
void RadixSort(int*, int, int);

void main()
{
	int size, largest = 0;
	int *arr, i;
	printf("Enter the size: ");
	scanf_s("%d", &size);
	arr = (int*)calloc(size, sizeof(int));
	printf("Data in the array: ");
	for (i = 0; i < size; i++)
	{
		arr[i] = rand() % 10000 + 500;
		printf("%d  ", arr[i]);
		if (arr[i] > largest)
			largest = arr[i];
	}
	printf("\n");
	RadixSort(arr, size, largest);
	printf("\n\nArray after sorting:\n");
	for (i = 0; i < size; i++)
		printf("%d  ", arr[i]);
	free(arr);
	printf("\n");
	system("pause");
}

Node* initial(Node* head, int data)
{
	Node* ptr = (Node*)calloc(1, sizeof(Node));
	Node* temp = head;
	ptr->data = data;
	if (head == NULL)
		return ptr;
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = ptr;
	}
	return head;
}


void RadixSort(int* arr, int size, int largest)
{
	int divisor = 1;
	int rem, i, index;
	Node* temp;
	Node** bucket = (Node**)calloc(10, sizeof(Node));
	while (largest > 0)
	{
		for (i = 0; i < size; i++) // Creating the buckets
		{
			rem = (arr[i] / divisor) % 10;
			bucket[rem] = initial(bucket[rem], arr[i]);
		}

		divisor *= 10;
		largest /= 10;
		index = 0;

		for (i = 0; i < 10; i++) // Taking data out of the buckets
		{
			while (bucket[i] != NULL)
			{
				temp = bucket[i];
				arr[index++] = bucket[i]->data;
				bucket[i] = bucket[i]->next;
				free(temp);
			}
		}
	}
	free(bucket);
}