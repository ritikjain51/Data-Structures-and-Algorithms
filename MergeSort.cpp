#include<iostream>
#include<conio.h>
#include<time.h>
using namespace std;

void merge(int[], int, int, int);
void mergesort(int[], int, int);

void main()
{
	int *a = new int[100], n = 100;
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 100 + 5900;
		cout << a[i] << "  ";
	}

	cout << "\nMerge Sorting :\n";
	mergesort(a, 0, n);
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "  ";
	}
	cout << endl;
	system("pause");
}

void merge(int arr[], int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = (r - m);
	int* L = new int[n1];
	int* R = new int[n2];
	int j = m;


	for (int i = 0; i < n1; i++)
	{
		L[i] = arr[l + i];
	}

	for (int j = 0; j < n2; j++)
	{
		R[j] = arr[m + 1 + j];
	}
	int i = 0;
	j = 0;
	int k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
	delete L;
	delete R;
}

void mergesort(int arr[], int l, int h)
{

	if (l < h)
	{
		int m = (l + (h - 1)) / 2;
		mergesort(arr, l, m);
		mergesort(arr, m + 1, h);
		merge(arr, l, m, h);
	}


}