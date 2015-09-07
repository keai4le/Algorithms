// UnionFind.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class UF
{
private:
	int* a;
	int count;
	int* sz;
public:
	UF(int n)
	{
		count = n;
		a = new int[n];
		sz = new int[n];
		for (int i = 0; i < n; i++)
		{
			a[i] = i;
			sz[i] = 1;
		}
	}
	int Count()
	{
		return this->count;
	}
	bool Connected(int p, int q)
	{
		return Find(p) == Find(q);
	}
	int Find(int p)
	{
		while (p != a[p])
			p = a[p];
		return p;
	}
	void Union(int p, int q)
	{
		int pRoot = Find(p);
		int qRoot = Find(q);
		if (pRoot == qRoot)
			return;
		else
		{
			if (sz[pRoot] > sz[qRoot])
			{
				sz[pRoot] += sz[qRoot];
				a[qRoot] = pRoot;
			}
			else
			{	
				sz[qRoot] += sz[pRoot];
				a[pRoot] = qRoot;
			}
			this->count--;
		}
	}

};
int main()
{
    return 0;
}

