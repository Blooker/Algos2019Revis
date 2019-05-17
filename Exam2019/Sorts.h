#pragma once
class Sorts
{
public:

	static void printList(int list[], const int& len);

	static void selectionSort(int list[], const int& len);
	static void insertionSort(int list[], const int& len);
	static void countSort(int list[], const int& len);

	static void mergeSort(int list[], const int& len);

	static void swap(int list[], int a, int b);

private:
	static void _mergeSort(int list[], int lo, int hi);
	static void merge(int list[], int lo, int mid, int hi);
};

