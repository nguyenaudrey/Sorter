/*
* Student: Audrey Nguyen
* Professor: Robert Dimpsey
* Assignment #4: Sorting
* Description: This is the cpp file for Sorting Implementations
*/
#include "SortImpls.h"
#include <vector>

int main()
{
	vector<int> items = { 30, 2, 5, 12, 6, 18, 7, 1 };
	cout << "Items" << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << items[i] << " ";
	}
	cout << endl;

	int a = 0;
	int b = 7;
	items = {30, 2, 5, 12, 6, 18, 7, 1};
	BubbleSort(items, a , b);
	cout << "Bubble Sort" << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << items[i] << " ";
	}
	cout << endl;

	items = { 30, 2, 5, 12, 6, 18, 7, 1 };
	InsertionSort(items, a, b);
	cout << "Insertion Sort" << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << items[i] << " ";
	}
	cout << endl;

	items = { 30, 2, 5, 12, 6, 18, 7, 1 };
	MergeSort(items, a, b);
	cout << "Merge Sort" << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << items[i] << " ";
	}
	cout << endl;

	
	items = { 30, 2, 5, 12, 6, 18, 7, 1 };
	IterativeMergeSort(items, a, b);
	cout << "Iterative MergeSort" << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << items[i] << " ";
	}
	cout << endl;

	items = { 30, 2, 5, 12, 6, 18, 7, 1 };
	QuickSort(items, a, b);
	cout << "QuickSort: " << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << items[i] << " ";
	}
	cout << endl;

	items = { 30, 2, 5, 12, 6, 18, 7, 1 };
	ShellSort(items, a, b);
	cout << "ShellSort: " << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << items[i] << " ";
	}
	cout << endl;
}