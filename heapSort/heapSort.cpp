// heapSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

void MaxHeapify(int a[], int index, int size)
{
	int l = 2 * index + 1;
	int r = 2 * index + 2;
	int largest = index;
	if (l <= size && a[l]>a[index])
		largest = l;
	if (r <= size && a[r]>a[largest])
		largest = r;
	if (largest != index)
	{
		int temp = a[index];
		a[index] = a[largest];
		a[largest] = temp;
		MaxHeapify(a, largest, size);
	}
}
void BuildMaxHeap(int a[], int size)
{
	for (int i = size / 2; i >= 0; i--)
	{
		MaxHeapify(a, i, size);
	}
}
void HeapSort(int a[], int size)
{
	BuildMaxHeap(a, size - 1);
	int tempsize = size - 1;
	for (int i = size - 1; i > 0; i--)
	{
		int temp = a[i];
		a[i] = a[0];
		a[0] = temp;
		--tempsize;
		MaxHeapify(a, 0, tempsize);
	}
}
int main()
{
	int a[] = { 8,7,6,5,4,3,2,1 };
	HeapSort(a, 8);
	for (int aa : a)
		std::cout << aa << std::endl;
	return 0;
}

