// maxPriorityQueue.cpp : 定义控制台应用程序的入口点。
// 注意：未测试所有成员函数
// 根据《算法导论》实现的最大优先队列
#include "stdafx.h"
#include <iostream>
class MaxPriorityQueue
{
private:
	int size;
	int* a;
public:
	//提供堆的最大容量max并初始化
	MaxPriorityQueue(int max)
	{
		a = new int[max];
		memset(a, 0, sizeof(int)*max);
		size = 0;
	}
	//调整堆
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
	//建立最大堆
	void BuildMaxHeap()
	{
		for (int i = size / 2; i >= 0; i--)
		{
			MaxHeapify(i);
		}
	}
	//返回key最大的元素
	int HeapMaxum()
	{
		return a[0];
	}
	//弹出key最大的元素
	int HeapExtractMax()
	{
		int max = a[0];
		a[0] = a[size];
		size--;
		MaxHeapify(0);
	}
	//增加元素的key
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
	//插入元素
	void MaxHeapInsert(int key)
	{
		size++;
		a[size] = INT_MIN;
		HeapIncreaseKey(size, key);
	}
	//打印堆中前10个元素
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

