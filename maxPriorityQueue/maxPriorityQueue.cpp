// maxPriorityQueue.cpp : �������̨Ӧ�ó������ڵ㡣
// ע�⣺δ�������г�Ա����
// ���ݡ��㷨���ۡ�ʵ�ֵ�������ȶ���
#include "stdafx.h"
#include <iostream>
class MaxPriorityQueue
{
private:
	int size;
	int* a;
public:
	//�ṩ�ѵ��������max����ʼ��
	MaxPriorityQueue(int max)
	{
		a = new int[max];
		memset(a, 0, sizeof(int)*max);
		size = 0;
	}
	//������
	void MaxHeapify(int index)
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
			MaxHeapify(largest);
		}
	}
	//��������
	void BuildMaxHeap()
	{
		for (int i = size / 2; i >= 0; i--)
		{
			MaxHeapify(i);
		}
	}
	//����key����Ԫ��
	int HeapMaxum()
	{
		return a[0];
	}
	//����key����Ԫ��
	int HeapExtractMax()
	{
		int max = a[0];
		a[0] = a[size];
		size--;
		MaxHeapify(0);
	}
	//����Ԫ�ص�key
	void HeapIncreaseKey(int index,int key)
	{
		a[index] = key;
		while (index > 0 && a[(index - 1) / 2] < a[index])
		{
			int temp = a[(index - 1) / 2];
			a[(index - 1) / 2] = a[index];
			a[index] = temp;
			index = (index - 1) / 2;
		}
	}
	//����Ԫ��
	void MaxHeapInsert(int key)
	{
		size++;
		a[size] = INT_MIN;
		HeapIncreaseKey(size, key);
	}
	//��ӡ����ǰ10��Ԫ��
	void Print1to10()
	{
		for (int i = 0; i < 10;i++)
			std::cout << a[i] << std::endl;
	}
};

int main()
{
	/*MaxPriorityQueue mpq(10);
	mpq.MaxHeapInsert(8);
	mpq.MaxHeapInsert(10);
	mpq.MaxHeapInsert(12);
	mpq.Print1to10();*/
    return 0;
}

