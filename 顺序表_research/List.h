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

//基础函数
/*
基本操作函数里可能会用到的功能函数
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

////拷贝函数：
/*
	将一个线性表里的所有数据元素按顺序拷贝到另外一个同数据元素类型的动态数组里去
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

//基本操作
////1、初始化线性表
void InitList(SqList *L)
{
	
	L->elem = (ElemType*)malloc(Initsize*sizeof(ElemType));
	L->length = 0;
	L->size = Initsize;
}

////2、求表长
int Length(SqList* L)
{
	if (L->elem == NULL)
		return 0;
	return L->length;
}

////3、按键值查找操作

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

////4、按位置查找操作

ElemType GetElem(SqList* L,int loca)
{
	int l = Length(L);
	if (loca <= l)
	{
		return L->elem[loca];
	}
	return -1;
}

////5、插入操作
/*
在指定位置插入元素
*/
void ListInsert(SqList* L,int e,int i)
{
	//特殊情况
	if (L->length >= Initsize)
	{
		ElemType* p,*t;
		t = (ElemType*)malloc((L->size + Addsize) * sizeof(ElemType));
		p = ListCopy(L);
		if (p == NULL)
		{
			cout << "重分配内存失败！" << endl;
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
	//第一种情况（这个是为了创建线性表的时候用插入函数才写的，正常不用）
	if (L->length == 0)
	{
		L->elem[L->length] = e;
		L->length++;
	}
	//第二种情况
	else if (i == L->length)
	{
		L->elem[L->length] = e;
		L->length++;
		
	}
	//第三种情况
	else if (i < L->length && i >= 0)
	{
		for (int j = L->length-1; j >= i; j--)
		{
			L->elem[j + 1] = L->elem[j];
		}

		L->elem[i] = e;
		L->length++;
	}
	//第四种情况
	else
	{
		cout << "插入位置不合理！" << endl;
	}
}

////6、删除操作
/*
删除指定位置的元素，并返回该元素
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

////7、输出操作

void PrintList(SqList* L)
{
	if (L == NULL)
	{
		cout << "输出失败，线性表为空" << endl;
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
		cout << "输出失败，线性表为空" << endl;
	}
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
/*
销毁失败VS会抛出异常
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
			cout << "销毁成功！" << endl;
		}
	}
	else
		cout << "销毁失败，线性表已销毁。" << endl;
}