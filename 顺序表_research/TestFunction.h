#pragma once

#include <iostream>
#include "List.h"
#include "CreatFuntion.h"
#include "func.h"

using namespace std;

/*
TestFunction.h
ֻ�Ų��Ժ���
*/

//���Ի�����������

void test_LocateElem(SqList* L)
{
	int n, loca;
	cin >> n;
	loca = LocateElem(L, n);
	if (loca > -1)
	{
		cout << "�ҵ��ˣ�" << endl;
		cout << "Location:" << loca << endl;
	}
	else
		cout << "δ�ҵ�!" << endl;
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
		cout << "λ����Ч��" << endl;
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
		cout << "ɾ��ʧ�ܣ�" << endl;
}



//���Ը�������
////Ϊ��8��д�Ĳ��Ը�������
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



//���Զ�Ӧ��Ŀ�ĺ���

int test11()
{
	//�ȷ����ڴ�
	SqList* L0, * L1, * L2;
	L0 = (SqList*)malloc(sizeof(SqList));
	L1 = (SqList*)malloc(sizeof(SqList));
	L2 = (SqList*)malloc(sizeof(SqList));

	//��ʼ�����Ա�
	InitList(L0);
	InitList(L1);
	InitList(L2);

	CreatList(L1, L2, 1);

	L0 = func07(L1, L2);

	cout << "L0:" << endl;
	PrintList(L0);

	cout << L0->length << "	��λ����" << L0->elem[L0->length / 2 - 1] << endl;
	cout << "��ţ�" << L0->length / 2 << endl;

	cout << "��λ���� " << func11(L1, L2) << endl;

	cout << "L1:" << endl;
	PrintList(L1);
	cout << L1->length << endl;

	cout << "L2:" << endl;
	PrintList(L2);

	return 1;
}

int test12()
{
	//�ȷ����ڴ�
	SqList* L0, * L, * L1;
	L = (SqList*)malloc(sizeof(SqList));
	L0 = (SqList*)malloc(sizeof(SqList));
	L1 = (SqList*)malloc(sizeof(SqList));

	//��ʼ�����Ա�
	InitList(L);
	InitList(L1);
	InitList(L0);

	CreatListF(L);
	
	
	PrintList(L);
	cout << L->length << endl;

	int re = 0;
	re = func12(L);
	cout << "��Ԫ��Ϊ��" << re << endl;

	PrintList(L);

	//DestroyList(L);

	return 1;
}


int test13()
{
	//�ȷ����ڴ�
	SqList* L;
	L = (SqList*)malloc(sizeof(SqList));

	//��ʼ�����Ա�
	InitList(L);

	CreatList(L,0);

	PrintList(L);
	cout << L->length << endl;

	int re;
	re = func13(L);
	cout << "��С��������" << re << endl;

	PrintList(L);
	cout << L->length << endl;

	//DestroyList(L);

	return 1;
}