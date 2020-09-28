/*
* Student: Audrey Nguyen
* Professor: Robert Dimpsey
* Assignment #4: Sorting
* Description: This is the h file for Sorting Implementations
*/

#ifndef SORTIMPLS_H
#define SORTIMPLS_H

#include <iostream>
#include <vector>
using namespace std;

	void BubbleSort(vector<int>& items, int start, int end);
	void InsertionSort(vector<int>& items, int start, int end);
	void MergeSort(vector<int>& items, int start, int end);
	void IterativeMergeSort(vector<int>& items, int start, int end);
	void QuickSort(vector<int>& items, int start, int end);
	void ShellSort(vector<int>& items, int start, int end);

	void Merge(vector<int>& items, int start, int middle, int end);
	void IterativeMerge(vector<int>& source, vector<int>& destination, int start, int middle, int end);
	int Partition(vector<int>& items, int start, int end);
	void Swap(vector<int>& items, int a, int b);

#include <iostream>
#include "SortImpls.h"
	using namespace std;

	// Based on Carrano's bubble sort
	void BubbleSort(vector<int>& items, int start, int end)
	{
		bool sorted = false;
		int pass = 0;
		while (!sorted && pass < end)
		{
			sorted = true;
			for (int index = start; index < end - pass; index++)
			{
				int nextIndex = index + 1;
				if (items[index] > items[nextIndex])
				{
					Swap(items, index, nextIndex);
					sorted = false;
				}
			}
			pass++;
		}
	}

	void InsertionSort(vector<int>& items, int start, int end)
	{
		for (int i = start; i < end; i++)
		{
			int j = i;
			while ((j >= 0) && (items[j] > items[j + 1]))
			{
				Swap(items, j, j + 1);
				j--;
			}
		}
	}

	// Recursive version of Merge sort
	void MergeSort(vector<int>& items, int start, int end)
	{
		int middle = (end + start) / 2;

		// Checks if there is only one element in which case there is nothing to sort
		if (start == end)
		{
			return;
		}
		MergeSort(items, start, middle);
		MergeSort(items, middle + 1, end);
		Merge(items, start, middle, end);
	}

	// Merges the array
	void Merge(vector<int>& items, int start, int middle, int end)
	{
		vector<int> tempLeft;
		vector<int> tempRight;

		// Creating subarray for lhs
		for (int i = start; i <= middle; i++)
		{
			tempLeft.push_back(items[i]);
		}
		// Creating subarray for rhs
		for (int i = middle + 1; i <= end; i++)
		{
			tempRight.push_back(items[i]);
		}
		// Integers left and right keep track of the indexes of the lhs and rhs
		int left = 0;
		int right = 0;

		for (int i = start; i <= end; i++)
		{
			if (left >= tempLeft.size())
			{
				items[i] = tempRight[right];
				right++;
			}

			else if (right >= tempRight.size())
			{
				items[i] = tempLeft[left];
				left++;
			}

			else if (tempLeft[left] < tempRight[right])
			{
				items[i] = tempLeft[left];
				left++;
			}

			else if (tempLeft[left] > tempRight[right])
			{
				items[i] = tempRight[right];
				right++;
			}
		}
	}

	// Iterative version of merge sort
	void IterativeMergeSort(vector<int>& items, int start, int end)
	{
		int size;
		int left;
		vector<int> destination(items.size(), 0);

		// Merge subarrays in bottom up manner.  First merge subarrays of 
		// size 1 to create sorted subarrays of size 2, then merge subarrays 
		// of size 2 to create sorted subarrays of size 4, and so on. 
		for (size = 1; size < end - start + 1; size *= 2)
		{
			// Pick starting point of different subarrays of current size 
			for (left = start; left <= end; left += (2 * size))
			{
				// Middle is the last point of the left hand subarray
				int middle = (left + size <= end) ? left + size : end;
				// Right is the last poin
				int right = (left + 2 * size - 1 <= end) ? left + 2 * size - 1 : end;

				// Merges the subarrays together
				IterativeMerge(items, destination, left, middle, right);
			}
		}
	}

	// Iterative version of merge function
	// Works under assumption both sides are sorted but whole thing is not sorted
	void IterativeMerge(vector<int>& source, vector<int>& destination, int start, int middle, int end)
	{
		int leftCount = start;
		int rightCount = middle;
		int index = start;

		while (leftCount < middle && rightCount <= end)
		{
			// If and else adds the smaller element to destination to merge the array
			if (source[leftCount] < source[rightCount])
			{
				destination[index] = source[leftCount];
				leftCount++;
			}
			else
			{
				destination[index] = source[rightCount];
				rightCount++;
			}
			index++;
		}

		// Adds rest of left hand side to array
		while (leftCount < middle)
		{
			destination[index] = source[leftCount];
			leftCount++;
			index++;
		}

		// Adds rest of right hand side to array
		while (rightCount <= end)
		{
			destination[index] = source[rightCount];
			rightCount++;
			index++;
		}

		// Copies destinations contents to source
		for (int i = start; i <= end; i++)
		{
			source[i] = destination[i];
		}
	}


	void QuickSort(vector<int>& items, int start, int end)
	{
		if (start < end)
		{
			// Partition the array
			int partition = Partition(items, start, end);

			// QuickSorts both sides of the partition
			QuickSort(items, start, partition - 1);
			QuickSort(items, partition + 1, end);
		}
	}

	// Partitions an array
	int Partition(vector<int>& items, int start, int end)
	{
		// Pivot is last element of array
		int pivot = items[end];
		int index = start - 1;

		// Looking for index where pivot should be
		for (int i = start; i <= (end - 1); i++)
		{
			// Swapping current position with index
			if (items[i] < pivot)
			{
				index++;
				Swap(items, i, index);
			}
		}

		// Swapping last element to be in place
		Swap(items, index + 1, end);

		return index + 1;
	}

	void ShellSort(vector<int>& items, int start, int end)
	{
		// Gap is half the size of the array
		int size = end - start;
		int gap = size;

		// Integer pos is the position we are at in the array
		for (int pos = start + gap; gap > 0; gap /= 2, pos = gap + start)
		{
			for (int i = pos; i <= end; i += 1)
			{
				int temp = items[i];

				int j;
				for (j = i; (j >= pos) && (items[j - gap] > temp); j -= gap)
				{
					items[j] = items[j - gap];
				}
				items[j] = temp;
			}

		}
	}

	// Swaps the elements of an array
	void Swap(vector<int>& items, int a, int b)
	{
		int temp = items[a];
		items[a] = items[b];
		items[b] = temp;
	}

#endif
