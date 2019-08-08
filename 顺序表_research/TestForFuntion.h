#pragma once
#include <iostream>
#include "List.h"
#include <time.h>

using namespace std;

/*
TestFunction.h:
只放辅助测试函数
即用来测试的另外的一些操作，包括生成随机有序序列什么的
*/

//const int len = 80;

//生成随机无序数列函数
int* CreatRand()
/*
输入数字n，生成n个随机元素的数组
*/
{
	int* p;
	cout << "输入随机数的个数" << endl;
	int n,len;
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
	return p;
}

//生成随机有序数列函数
int* CreatRand1()
/*
输入数字n，生成n个随机元素的数组
*/
{
	int* p,tmp;
	cout << "输入随机数的个数" << endl;
	int n, len;
	cin >> n;
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

	for (int j=1;j<p[0]+1;j++)
	{
		for (int i = 1; i < p[0]; i++)
		{
			if (p[i] > p[i+1])
			{
				tmp = p[i];
				p[i] = p[i+1];
				p[i+1] = tmp;
			}
		}
	}
	
	for (int i = 1; i <= p[0]; i++)
	{
		cout << p[i] << " ";
	}
	cout << endl;
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
		p = CreatRand1();
		break;
	case 0:
		p = CreatRand();
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

void CreatList(SqList* L1,SqList* L2)
/*
L:处理的线性表
x:1->有序；0->无序
*/
{
	int* p1,* p2;
	p1 = CreatRand();
	p2 = CreatRand();

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

void test_LocateElem(SqList* L)
{
	int n, loca;
	cin >> n;
	loca = LocateElem(L, n);
	if (loca > -1)
	{
		cout << "找到了！" << endl;
		cout << "Location:" << loca << endl;
	}
	else
		cout << "未找到!" << endl;
}

void test_GetElem(SqList* L)
{
	int n;
	cin >> n;
	ElemType e;
	e = GetElem(L, n);
	if (e > -1)
	{
		cout << e << endl;
	}
	else
		cout << "位置无效！" << endl;
}

void test_ListInsert(SqList* L)
{

}

void test_ListDelete(SqList* L)
{
	int n;
	cin >> n;
	ElemType e = ListDelete(L, n);
	if (~e)
	{
		cout << e << endl;
	}
	else
		cout << "删除失败！" << endl;
}

