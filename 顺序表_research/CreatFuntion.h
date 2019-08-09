#pragma once
#include <iostream>
#include "List.h"
#include <time.h>
#include <windows.h>

using namespace std;

/*
TestFunction.h:
只放辅助测试函数
即用来测试的另外的一些操作，包括生成随机有序序列什么的
*/

//const int len = 80;

//生成随机数列函数
int* CreatRand(int x)
/*
x:1，有序；0，无序。
输入数字n，生成n个随机元素的数组
*/
{
	int* p;
	cout << "输入随机数的个数" << endl;
	int n,len,tmp;
	cin >> n;
	cout << "输入随机数的大小范围：" << endl;
	cin >> len;

	p = (int*)malloc((n+1) * sizeof(int));
	p[0] = n;

	cout << endl << "生成的随机数：" << endl;
	srand((unsigned int)time(0));
	for (int i = 1; i < n+1; i++)
	{
		int re = rand();
		p[i] = re % len;
		cout << p[i] << " ";
	}
	cout << endl;

	if (x == 1)
	{
		for (int j = 1; j < p[0] + 1; j++)
		{
			for (int i = 1; i < p[0]; i++)
			{
				if (p[i] > p[i + 1])
				{
					tmp = p[i];
					p[i] = p[i + 1];
					p[i + 1] = tmp;
				}
			}
		}
		for (int i = 1; i <= p[0]; i++)
		{
			cout << p[i] << " ";
		}
		cout << endl;
	}

	return p;
}

int* CreatRand(int n,int x)
/*
x:1，有序；0，无序。
输入数字n，生成n个随机元素的数组
*/
{
	int* p;
	//cout << "输入随机数的个数" << endl;
	int len, tmp;
	//cin >> n;
	cout << "输入随机数的大小范围：" << endl;
	cin >> len;

	p = (int*)malloc((n + 1) * sizeof(int));
	p[0] = n;

	cout << endl << "生成的随机数：" << endl;
	srand((unsigned int)time(0));
	for (int i = 1; i < n + 1; i++)
	{
		int re = rand();
		p[i] = re % len;
		cout << p[i] << " ";
	}
	cout << endl;

	if (x == 1)
	{
		for (int j = 1; j < p[0] + 1; j++)
		{
			for (int i = 1; i < p[0]; i++)
			{
				if (p[i] > p[i + 1])
				{
					tmp = p[i];
					p[i] = p[i + 1];
					p[i + 1] = tmp;
				}
			}
		}
		for (int i = 1; i <= p[0]; i++)
		{
			cout << p[i] << " ";
		}
		cout << endl;
	}

	return p;
}

int* CreatRand(int n,int len, int x)
/*
x:1，有序；0，无序。
输入数字n，生成n个随机元素的数组
*/
{
	int* p;
	//cout << "输入随机数的个数" << endl;
	int tmp;
	//cin >> n;
	//cout << "输入随机数的大小范围：" << endl;
	//cin >> len;

	p = (int*)malloc((n + 1) * sizeof(int));
	p[0] = n;

	cout << endl << "生成的随机数：" << endl;
	srand((unsigned int)time(0));
	for (int i = 1; i < n + 1; i++)
	{
		int re = rand();
		p[i] = re % len;
		cout << p[i] << " ";
	}
	cout << endl;

	if (x == 1)
	{
		for (int j = 1; j < p[0] + 1; j++)
		{
			for (int i = 1; i < p[0]; i++)
			{
				if (p[i] > p[i + 1])
				{
					tmp = p[i];
					p[i] = p[i + 1];
					p[i + 1] = tmp;
				}
			}
		}
		for (int i = 1; i <= p[0]; i++)
		{
			cout << p[i] << " ";
		}
		cout << endl;
	}

	return p;
}

//创建线性表函数
void CreatList(SqList* L,int x)
/*
L:处理的线性表
x:1->有序；0->无序
*/
{
	int* p = NULL;
	switch (x)
	{
	case 1:
		p = CreatRand(1);
		break;
	case 0:
		p = CreatRand(0);
		break;
	default:
		p = NULL;
		break;
	}
	//p = CreatRand();

	int n = p[0];
	for (int i = 0; i < n; i++)
	{
		ListInsert(L, p[i+1], i);
	}
}

void CreatList(SqList* L1,SqList* L2,int x)
/*
L:处理的线性表
x:1->有序；0->无序
*/
{
	int* p1,* p2;
	switch (x)
	{
	case 1:
		p1 = CreatRand(1);
		p2 = CreatRand(1);
		break;
	case 0:
		p1 = CreatRand(0);
		p2 = CreatRand(0);
		break;
	default:
		p1 = NULL, p2 = NULL;
		break;
	}
	

	int n1 = p1[0],n2=p2[0];
	for (int i = 0; i < n1; i++)
	{
		ListInsert(L1, p1[i + 1], i);
	}
	for (int i = 0; i < n2; i++)
	{
		ListInsert(L2, p2[i + 1], i);
	}
}

void CreatList(SqList* L1,int l1, SqList* L2,int l2, int x)
/*
L:处理的线性表
x:1->有序；0->无序
*/
{
	int* p1, * p2,len;
	cout << "输入随机数的大小范围：" << endl;
	cin >> len;
	switch (x)
	{
	case 1:
		p1 = CreatRand(l1,len,1);
		Sleep(500);
		p2 = CreatRand(l2, 2*len, 1);
		break;
	case 0:
		p1 = CreatRand(l1, len, 0);
		Sleep(500);
		p2 = CreatRand(l2, 2*len, 0);
		break;
	default:
		p1 = NULL, p2 = NULL;
		break;
	}


	int n1 = p1[0], n2 = p2[0];
	for (int i = 0; i < n1; i++)
	{
		ListInsert(L1, p1[i + 1], i);
	}
	for (int i = 0; i < n2; i++)
	{
		ListInsert(L2, p2[i + 1], i);
	}
}



void CreatListF(SqList* L)
/*
L:处理的线性表
f: 重复元素的个数
*/
{
	int f;
	cout << "输入重复元素的个数：" << endl;
	cin >> f;

	if ( f > (L->length / 2))
	{
		int* p = NULL;

		p = CreatRand(0);

		int n = p[0];
		for (int i = 0; i < n; i++)
		{
			ListInsert(L, p[i + 1], i);
		}

		srand((unsigned int)time(0));
		int re = rand();
		int e = re % n;

		
		int k = p[e + 1];
		cout << k << endl;
		int loca;
		for (int i = 0; i < f; i++)
		{
			int re1 = rand();
			loca = re1 % n;
			ListInsert(L, k, loca);
		}
	}
	else
		cout << "参数错误！" << endl;
}