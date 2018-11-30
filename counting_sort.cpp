#include<iostream>
#include<conio.h>

using namespace std;

int * count_sort(int A[], int);

void main()
{
	int a[] = { 6, 5, 4, 3, 2, 1 };
	int * b = count_sort(a,6);
	for (int i = 0; i < 6; i++)
		cout << b[i] << "  ";
	_getch();
}

int * count_sort(int A[], int n)
{
	int *B = (int *)calloc(n, sizeof(int));
	int  max = 0;
	for (int i = 0; i < n; i++)
	{
		if (A[i]> max)
		{ 
			max = A[i];
		}
	}
	int * c = (int *)calloc(max, sizeof(int));
	for (int i = 0; i < n; i++)
		c[A[i] - 1]++;

	for (int i = 1; i < max; i++)
		c[i] += c[i - 1];

	for (int i = n-1; i >= 0; i--)
	{
		B[c[A[i]-1]-1] = A[i];
		c[A[i]-1]--;
	}
	return B;
}