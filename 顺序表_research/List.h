#pragma once

#include <iostream>

using namespace std;

#define ElemType int
#define Initsize 100

typedef struct
{
	ElemType *elem;
	int length;
	int size;
} SqList;


void input(SqList &L, int n[], int l)
{
	L.elem = n;
	L.length = l;
}



void output(SqList L)
{
	for (int i = 0; i < L.length; i++)
	{
		cout << L.elem[i] << " ";
	}
	cout << endl << L.length << endl;
}

//��������
////1����ʼ�����Ա�
void InitList(SqList *L)
{
	
	L->elem = (ElemType*)malloc(Initsize*sizeof(ElemType));
	L->length = 0;
	L->size = 0;
}

////2�����
int Length(SqList* L)
{
	return L->length;
}

////3������ֵ���Ҳ���

void LocateElem()
{

}

////4����λ�ò��Ҳ���

void GetElem()
{

}

////5���������

void ListInsert(SqList* L,int e)
{
	if (L->length == 0)
	{
		*(L->elem) = e;
		L->length++;
	}
	else if (L->length < Initsize)
	{
		L->elem[L->length] = e;
		L->length++;
	}
}

////6��ɾ������

void ListDelete()
{

}

////7���������

void PrintList()
{

}

////8���пղ���

bool IsEmpty(SqList* L)
{
	if (L->elem == NULL)
		return true;
	else
		return false;
}

////9�����ٲ���

void DestroyList()
{

}