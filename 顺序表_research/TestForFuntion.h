#pragma once
#include <iostream>
#include "List.h"
#include <time.h>

using namespace std;

//const int len = 80;

//����������к���
int* CreatRand()
/*
��������n������n�����Ԫ�ص�����
*/
{
	int* p;
	cout << "����������ĸ���" << endl;
	int n,len;
	cin >> n;
	cout << "����������Ĵ�С��Χ��" << endl;
	cin >> len;

	p = (int*)malloc((n+1) * sizeof(int));
	p[0] = n;

	cout << endl << "���ɵ��������" << endl;
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

//�������Ա���
void CreatList(SqList* L)
/*

*/
{
	int* p;
	p = CreatRand();

	int n = p[0];
	for (int i = 0; i < n; i++)
	{
		ListInsert(L, p[i+1], i);
	}
}

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

