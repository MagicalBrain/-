#pragma once
#include <iostream>
#include "List.h"
#include <time.h>

using namespace std;

//const int len = 80;

//生成随机数列函数
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

	p = (int*)malloc(n * sizeof(int));

	cout << endl << "生成的随机数：" << endl;
	srand((unsigned int)time(0));
	for (int i = 0; i < n; i++)
	{
		int re = rand();
		p[i] = re % len;
		cout << p[i] << " ";
	}
}

//创建线性表函数
void CreatList(SqList* L,int n[])
/*

*/
{

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

