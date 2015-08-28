// quickSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
int partition(int a[], int p, int r)
{
	int x = a[r];
	int i = p - 1;
	for (int j = p; j < r; j++)
	{
		if (a[j] < x)
		{
			i++;
			int temp = a[j];
			a[j] = a[i];
			a[i] = temp;
		}
	}
	a[r] = a[i + 1];
	a[i + 1] = x;
	return i + 1;
}
void quickSort(int a[], int p, int r)
{
	if (p < r)
	{
		int q = partition(a, p, r);
		quickSort(a, p, q - 1);
		quickSort(a, q + 1, r);
	}
}
int main()
{
	int a[] = { 4,5,1,2,3 };
	quickSort(a, 0, 4);
	for (int aa : a)
		std::cout << aa << std::endl;
    return 0;
}

