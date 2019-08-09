#pragma once

#include <iostream>

using namespace std;

#define ElemType int
#define Initsize 20
#define Addsize 10

typedef struct
{
	ElemType *elem;
	int length;
	int size;
} SqList;

//��������
/*
����������������ܻ��õ��Ĺ��ܺ���
*/
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

////����������
/*
	��һ�����Ա������������Ԫ�ذ�˳�򿽱�������һ��ͬ����Ԫ�����͵Ķ�̬������ȥ
*/
ElemType* ListCopy(SqList* L)
{
	ElemType* p;
	if (L->length > 0)
	{
		p = (ElemType*)malloc(L->size * sizeof(ElemType));

		for (int i = 0; i < L->length; i++)
		{
			p[i] = L->elem[i];
		}
		return p;
	}
	else
		return NULL;
}

//��������
////1����ʼ�����Ա�
void InitList(SqList *L)
{
	
	L->elem = (ElemType*)malloc(Initsize*sizeof(ElemType));
	L->length = 0;
	L->size = Initsize;
}

////2�����
int Length(SqList* L)
{
	if (L->elem == NULL)
		return 0;
	return L->length;
}

////3������ֵ���Ҳ���

int LocateElem(SqList* L,int e)
{
	int add = 0,l = Length(L);
	if (l > 0)
	{
		for (int i = 0; i < l; i++)
		{
			if (L->elem[i] == e)
				return i;
		}
	}
	return -1;
}

////4����λ�ò��Ҳ���

ElemType GetElem(SqList* L,int loca)
{
	int l = Length(L);
	if (loca <= l)
	{
		return L->elem[loca];
	}
	return -1;
}

////5���������
/*
��ָ��λ�ò���Ԫ��
*/
void ListInsert(SqList* L,int e,int i)
{
	//�������
	if (L->length >= Initsize)
	{
		ElemType* p,*t;
		t = (ElemType*)malloc((L->size + Addsize) * sizeof(ElemType));
		p = ListCopy(L);
		if (p == NULL)
		{
			cout << "�ط����ڴ�ʧ�ܣ�" << endl;
			return;
		}

		L->elem = t;
		L->size += Addsize;

		for (int i = 0; i < L->length; i++)
		{
			L->elem[i] = p[i];
			//cout << L->elem[i] << " ";
		}
		//cout << endl;
	}
	//��һ������������Ϊ�˴������Ա��ʱ���ò��뺯����д�ģ��������ã�
	if (L->length == 0)
	{
		L->elem[L->length] = e;
		L->length++;
	}
	//�ڶ������
	else if (i == L->length)
	{
		L->elem[L->length] = e;
		L->length++;
		
	}
	//���������
	else if (i < L->length && i >= 0)
	{
		for (int j = L->length-1; j >= i; j--)
		{
			L->elem[j + 1] = L->elem[j];
		}

		L->elem[i] = e;
		L->length++;
	}
	//���������
	else
	{
		cout << "����λ�ò�����" << endl;
	}
}

////6��ɾ������
/*
ɾ��ָ��λ�õ�Ԫ�أ������ظ�Ԫ��
*/
ElemType ListDelete(SqList* L,int n)
{
	int l = Length(L);
	ElemType e;
	if (n < l)
	{
		e = L->elem[n];

		for (int i = n+1; i < l; i++)
		{
			L->elem[i - 1] = L->elem[i];
		}
		L->length--;
		return e;
	}

	return -1;
}

////7���������

void PrintList(SqList* L)
{
	if (L == NULL)
	{
		cout << "���ʧ�ܣ����Ա�Ϊ��" << endl;
		return;
	}
	if (L->length > 0)
	{
		for (int i = 0; i < L->length; i++)
		{
			cout << L->elem[i] << " ";
		}
		cout << endl;
	}
	else
	{
		cout << "���ʧ�ܣ����Ա�Ϊ��" << endl;
	}
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
/*
����ʧ��VS���׳��쳣
*/
void DestroyList(SqList* L)
{
	if (L != NULL)
	{
		if (L->elem != NULL)
		{
			free(L->elem);
			L->length = 0;
			L->size = 0;
			cout << "���ٳɹ���" << endl;
		}
	}
	else
		cout << "����ʧ�ܣ����Ա������١�" << endl;
}