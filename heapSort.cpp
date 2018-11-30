#include<iostream>
#include<stdlib.h>

using namespace std;

void HeapSort(int*, int);
void MaxHeap(int*, int, int);
int left(int);
int right(int);
void BuildHeap(int*, int);

void main()
{
	int arr[] = { 7,5,6,2,1,3,4 };
	HeapSort(arr, 7);
	for (int i = 0; i < 7; i++)
		cout << arr[i] << "  ";
	cout << endl;
	system("pause");
}


void BuildHeap(int* arr, int size)
{
	for (int i = size- 1; i >= 0; i--)
		MaxHeap(arr, size, i);
}

void MaxHeap(int* arr, int size, int i)
{
	int Left = 2 * i + 1;
	int Right = 2 * i + 2;
	int largest = i, temp;
	if (Left < size && arr[Left] > arr[i])
		largest = Left;

	if (Right < size && arr[Right] > arr[largest])
		largest = Right;

	if (largest != i)
	{
		temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;
		MaxHeap(arr, size, largest);
	}
}

void HeapSort(int *arr, int size)
{
	int temp;
	BuildHeap(arr, size);
	cout << endl;
	for (int i = size - 1; i >= 0; i--)
	{
		temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;
		MaxHeap(arr, i, 0);
	}
}
