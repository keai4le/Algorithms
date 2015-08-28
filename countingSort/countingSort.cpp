// countingSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
void CountingSort(int a[],int b[],int k,int n)
{
	int* c=new int[k+1];
	//初始化c为0
	memset(c, 0, (k+1)*sizeof(int));
	//统计每个数字出现的次数，记录在c数组中
	for (int i = 0; i < n; i++)
	{
		c[a[i]]++;
	}
	//计算小于等于c下标的数字出现的次数
	for (int i = 1; i < k+1; i++)
	{
		c[i] = c[i] + c[i - 1];
	}
	//一次从A中取出数字，通过c数组找到在b数组中的位置
	for (int i = n-1; i >= 0; i--)
	{
		b[c[a[i]]-1] = a[i]; //注意此处数组B的下标要-1
		c[a[i]]--;
	}
}

int main()
{
	int a[] = { 5,4,3,2,1,0 };
	int b[6] = { 0 };
	CountingSort(a, b, 5, 6);
	for (int i = 0; i < 6;i++)
		std::cout << b[i] << std::endl;
    return 0;
}

