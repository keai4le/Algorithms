// radixSort.cpp : �������̨Ӧ�ó������ڵ㡣
// ���ڶԶ���ָ����ⲻ��λ����ά������int** ��ʾ�ˣ����㷨���Ľ����ҵ��뷨�Ƕ�ά������ÿ��Ԫ�ش洢һλ���֣�һ���൱��һ��������
// ���㷨�Զ�ά������ÿ�й��ɵ���������

#include "stdafx.h"
#include <iostream>
void RadixSort(int** a,int** b,int cols,int rows)
{
	for (int j = cols - 1; j >= 0; j--)
	{
		int* c = new int[10];
		memset(c, 0, 10 * sizeof(int));
		//ͳ�Ƹ����ֳ��ִ���
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
		//����jλ���������Ľ�����Ƹ���ԭ����a
		memcpy(a, b, cols*rows*sizeof(int));
	}
}
int main()
{
	return 0;
}

