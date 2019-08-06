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

//基本操作
////1、初始化线性表
void InitList(SqList *L)
{
	
	L->elem = (ElemType*)malloc(Initsize*sizeof(ElemType));
	L->length = 0;
	L->size = 0;
}

////2、求表长
int Length(SqList* L)
{
	return L->length;
}

////3、按键值查找操作

void LocateElem()
{

}

////4、按位置查找操作

void GetElem()
{

}

////5、插入操作

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

////6、删除操作

void ListDelete()
{

}

////7、输出操作

void PrintList()
{

}

////8、判空操作

bool IsEmpty(SqList* L)
{
	if (L->elem == NULL)
		return true;
	else
		return false;
}

////9、销毁操作

void DestroyList()
{

}