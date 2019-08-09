#pragma once
#include <iostream>
#include "List.h"
#include <time.h>
#include <windows.h>

using namespace std;

/*
TestFunction.h:
ֻ�Ÿ������Ժ���
���������Ե������һЩ�������������������������ʲô��
*/

//const int len = 80;

//����������к���
int* CreatRand(int x)
/*
x:1������0������
��������n������n�����Ԫ�ص�����
*/
{
	int* p;
	cout << "����������ĸ���" << endl;
	int n,len,tmp;
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
x:1������0������
��������n������n�����Ԫ�ص�����
*/
{
	int* p;
	//cout << "����������ĸ���" << endl;
	int len, tmp;
	//cin >> n;
	cout << "����������Ĵ�С��Χ��" << endl;
	cin >> len;

	p = (int*)malloc((n + 1) * sizeof(int));
	p[0] = n;

	cout << endl << "���ɵ��������" << endl;
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
x:1������0������
��������n������n�����Ԫ�ص�����
*/
{
	int* p;
	//cout << "����������ĸ���" << endl;
	int tmp;
	//cin >> n;
	//cout << "����������Ĵ�С��Χ��" << endl;
	//cin >> len;

	p = (int*)malloc((n + 1) * sizeof(int));
	p[0] = n;

	cout << endl << "���ɵ��������" << endl;
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

//�������Ա���
void CreatList(SqList* L,int x)
/*
L:��������Ա�
x:1->����0->����
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
L:��������Ա�
x:1->����0->����
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
L:��������Ա�
x:1->����0->����
*/
{
	int* p1, * p2,len;
	cout << "����������Ĵ�С��Χ��" << endl;
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

//Ϊ��8��д�Ĳ��Ը�������
SqList* testForfunc08(int l1,int l2)
{
	//int l1,l2;
	SqList* L1, * L2, * re;
	L1 = (SqList*)malloc(sizeof(SqList));
	L2 = (SqList*)malloc(sizeof(SqList));
	re = (SqList*)malloc(sizeof(SqList));

	InitList(L1);
	InitList(L2);
	InitList(re);
	
	CreatList(L1,l1, L2,l2, 0);

	//l1 = Length(L1), l2 = Length(L2);
	if (l1 >1 && l2 > 1)
	{
		for (int i = 0; i < l1; i++)
		{
			ListInsert(re, L1->elem[i], i);
		}
		for (int i = 0; i < l2; i++)
		{
			ListInsert(re, L2->elem[i], l1+i);
		}
	}

	if (re != NULL)
		return re;
	return NULL;
}

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

