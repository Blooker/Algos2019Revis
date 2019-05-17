#include "pch.h"
#include "Sorts.h"

#include <iostream>
#include <memory>

void Sorts::printList(int list[], const int& len) {
	for (size_t i = 0; i < len; i++)
	{
		std::cout << list[i];

		if (i < len - 1) {
			std::cout << ", ";
		}
		else {
			std::cout << std::endl;
		}
	}
}

void Sorts::selectionSort(int list[], const int & len)
{
	for (size_t i = 0; i < len - 1; i++)
	{
		int iMinNew = i;
		for (size_t j = i + 1; j < len; j++)
		{
			if (list[j] < list[iMinNew]) iMinNew = j;
		}

		Sorts::swap(list, i, iMinNew);
	}
}

void Sorts::insertionSort(int list[], const int & len)
{
	for (size_t i = 1; i < len; i++)
	{
		int j = i;
		while (j - 1 >= 0 && list[j - 1] > list[j]) {
			Sorts::swap(list, j, j - 1);
			j--;
		}
	}
}

void Sorts::countSort(int list[], const int & len)
{
	int max = 0;
	for (size_t i = 0; i < len; i++) {
		if (max == 0 || list[i] > max) { max = list[i]; }
	}

	int* count = new int[max];
	for (size_t i = 0; i < max; i++) { count[i] = 0; }
	for (size_t i = 0; i < len; i++) { count[list[i] - 1] += 1; }

	for (size_t i = 0; i < max - 1; i++) { count[i + 1] += count[i]; }

	int* result = new int[len];
	for (size_t i = 0; i < len; i++) {
		result[--count[list[i] - 1]] = list[i];
	}

	for (size_t i = 0; i < len; i++) { list[i] = result[i]; }

	delete[] count;
	delete[] result;
}

void Sorts::swap(int list[], int a, int b)
{
	int swap = list[a];
	list[a] = list[b];
	list[b] = swap;
}

void Sorts::mergeSort(int list[], const int & len)
{
	_mergeSort(list, 0, len);
}

void Sorts::_mergeSort(int list[], int lo, int hi)
{
	if (hi - lo <= 1) {
		return;
	}

	int mid = (hi + lo) / 2;
	_mergeSort(list, lo, mid);
	_mergeSort(list, mid, hi);

	Sorts::merge(list, lo, mid, hi);
}

void Sorts::merge(int list[], int lo, int mid, int hi)
{
	int i = lo, j = mid, index = 0;
	//std::unique_ptr<int[]> swapVals(new int[hi - lo]);

	int* swapVals = new int[hi - lo];

	while (i < mid || j < hi) {
		if (i < mid && (j >= hi || list[i] < list[j])) {
			swapVals[index] = list[i++];
		}
		else {
			swapVals[index] = list[j++];
		}

		index++;
	}

	for (size_t a = 0; a < hi-lo; a++)
	{
		list[lo + a] = swapVals[a];
	}

	delete[] swapVals;
}
