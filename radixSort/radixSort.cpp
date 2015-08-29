// radixSort.cpp : 定义控制台应用程序的入口点。
// 由于对二级指针理解不到位，二维数组用int** 表示了，该算法待改进。我的想法是二维数组中每个元素存储一位数字，一行相当于一个整数。
// 该算法对二维数组中每行构成的数字排序。

#include "stdafx.h"
#include <iostream>
void RadixSort(int** a,int** b,int cols,int rows)
{
	for (int j = cols - 1; j >= 0; j--)
	{
		int* c = new int[10];
		memset(c, 0, 10 * sizeof(int));
		//统计各数字出现次数
		for (int i = rows - 1; i >= 0; i--)
		{
			c[a[i][j]]++;
		}
		//
		for (int i = 1; i < 10; i++)
		{
			c[i] = c[i] + c[i - 1];
		}
		//
		for (int i = rows - 1; i >= 0; i--)
		{
			b[c[a[i][j]] - 1] = a[i];
			c[a[i][j]]--;
		}
		//将第j位计数排序后的结果复制覆盖原数组a
		memcpy(a, b, cols*rows*sizeof(int));
	}
}
int main()
{
	return 0;
}

