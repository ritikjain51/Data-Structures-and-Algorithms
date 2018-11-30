#include<iostream>
#include<conio.h>
#include<random>
using namespace std;
void insertion_sort(int[], int);


void main()
{
	int a[100], n = 100, b[100];;
	cout << "RANDOM NUMBER GENERATION : "<< endl;
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 10 + 500;
		cout << a[i] << "  ";
	}
	cout <<endl<< "Insertion implementation: " << endl;
	insertion_sort(a, n);
	for (int i = 0; i < 100; i++)
		cout << a[i] << "  ";
	cin >> n;
}

void insertion_sort(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int key = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;

	}
}