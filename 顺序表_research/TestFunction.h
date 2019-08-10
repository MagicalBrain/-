#pragma once

#include <iostream>
#include "List.h"
#include "CreatFuntion.h"
#include "func.h"

using namespace std;

/*
TestFunction.h
只放测试函数
*/

//测试基本操作函数

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



//测试辅助函数
////为第8题写的测试辅助函数
SqList* testForfunc08(int l1, int l2)
{
	//int l1,l2;
	SqList* L1, * L2, * re;
	L1 = (SqList*)malloc(sizeof(SqList));
	L2 = (SqList*)malloc(sizeof(SqList));
	re = (SqList*)malloc(sizeof(SqList));

	InitList(L1);
	InitList(L2);
	InitList(re);

	CreatList(L1, l1, L2, l2, 0);

	//l1 = Length(L1), l2 = Length(L2);
	if (l1 > 1 && l2 > 1)
	{
		for (int i = 0; i < l1; i++)
		{
			ListInsert(re, L1->elem[i], i);
		}
		for (int i = 0; i < l2; i++)
		{
			ListInsert(re, L2->elem[i], l1 + i);
		}
	}

	if (re != NULL)
		return re;
	return NULL;
}



//测试对应题目的函数

int test11()
{
	//先分配内存
	SqList* L0, * L1, * L2;
	L0 = (SqList*)malloc(sizeof(SqList));
	L1 = (SqList*)malloc(sizeof(SqList));
	L2 = (SqList*)malloc(sizeof(SqList));

	//初始化线性表
	InitList(L0);
	InitList(L1);
	InitList(L2);

	CreatList(L1, L2, 1);

	L0 = func07(L1, L2);

	cout << "L0:" << endl;
	PrintList(L0);

	cout << L0->length << "	中位数：" << L0->elem[L0->length / 2 - 1] << endl;
	cout << "序号：" << L0->length / 2 << endl;

	cout << "中位数： " << func11(L1, L2) << endl;

	cout << "L1:" << endl;
	PrintList(L1);
	cout << L1->length << endl;

	cout << "L2:" << endl;
	PrintList(L2);

	return 1;
}

int test12()
{
	//先分配内存
	SqList* L0, * L, * L1;
	L = (SqList*)malloc(sizeof(SqList));
	L0 = (SqList*)malloc(sizeof(SqList));
	L1 = (SqList*)malloc(sizeof(SqList));

	//初始化线性表
	InitList(L);
	InitList(L1);
	InitList(L0);

	CreatListF(L);
	
	
	PrintList(L);
	cout << L->length << endl;

	int re = 0;
	re = func12(L);
	cout << "主元素为：" << re << endl;

	PrintList(L);

	//DestroyList(L);

	return 1;
}


int test13()
{
	//先分配内存
	SqList* L;
	L = (SqList*)malloc(sizeof(SqList));

	//初始化线性表
	InitList(L);

	CreatList(L,0);

	PrintList(L);
	cout << L->length << endl;

	int re;
	re = func13(L);
	cout << "最小正整数：" << re << endl;

	PrintList(L);
	cout << L->length << endl;

	//DestroyList(L);

	return 1;
}