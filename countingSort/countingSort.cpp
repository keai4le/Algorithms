// countingSort.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
void CountingSort(int a[],int b[],int k,int n)
{
	int* c=new int[k+1];
	//��ʼ��cΪ0
	memset(c, 0, (k+1)*sizeof(int));
	//ͳ��ÿ�����ֳ��ֵĴ�������¼��c������
	for (int i = 0; i < n; i++)
	{
		c[a[i]]++;
	}
	//����С�ڵ���c�±�����ֳ��ֵĴ���
	for (int i = 1; i < k+1; i++)
	{
		c[i] = c[i] + c[i - 1];
	}
	//һ�δ�A��ȡ�����֣�ͨ��c�����ҵ���b�����е�λ��
	for (int i = n-1; i >= 0; i--)
	{
		b[c[a[i]]-1] = a[i]; //ע��˴�����B���±�Ҫ-1
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

