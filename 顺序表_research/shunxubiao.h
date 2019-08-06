#pragma once

#include <iostream>

using namespace std;

#define ElemType int

typedef struct
{
	ElemType *elem;
	int length;
	int size;
	int increment;
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