#include <iostream>
#include "List.h"
#include "TestForFuntion.h"

using namespace std;

void fun01(SqList* L)
/*
������ P18 �ڶ��µڶ��� �ۺ���1
*/
{
	int min,loca=0,l=Length(L);

	if (l == 0)
	{
		cout << "�����Ա�Ϊ�գ��޷�ɾ������fun01��" << endl;
		return;
	}
	else
	{
		min = L->elem[0];

		for (int i = 0; i < l; i++)
		{
			if (L->elem[i] < min)
			{
				min = L->elem[i];
				loca = i;
			}
		}

		ListDelete(L, loca);
		ListInsert(L, L->elem[l - 1], loca);
		L->length--;
		//cout<<""
	}
}

//����˳����󽻼��ĺ��� (�ú����������⣬���������ԣ�)
/*
SqList Jiao(SqList n1,SqList n2)
{
	SqList* re;
	ElemType* w;
	int n;
	if (n1.length > n2.length)
		n = n2.length;
	else
		n = n1.length;

	int k = 0;
	w = (ElemType*)malloc(n * sizeof(ElemType));

	re = (SqList*)malloc(sizeof(SqList));
	re->elem = w;
	//re->size = n;

	for (int i = 0; i < n1.length; i++)
	{
		for (int j = 0; j < n2.length; j++)
		{
			if (n1.elem[i] == n2.elem[j])
			{
				w[k] = n1.elem[i];
				k++;
				//re->length++;
			}

		}
	}

	re->length = k;

	return *re;
}

void test(int n1[],int n2[])
{
	//cout << sizeof(n1) / sizeof(int) << endl;
	SqList* L1, * L2;
	L1 = (SqList*)malloc(sizeof(SqList));
	L2 = (SqList*)malloc(sizeof(SqList));

	input(*L1, n1, sizeof(n1) / sizeof(int));
	input(*L2, n2, sizeof(n2) / sizeof(int));



	output(*L1);
	output(*L2);

	//Inv(*L);
	SqList re = Jiao(*L1, *L2);
	output(re);
}

int n1[] = {1,2,3,4,5,6,8,10,11};
int n2[] = { 1,2,3,4,5,7,9,10,11,12,13 };
*/


int main()
{
	//test(n1,n2);

	//�ȷ����ڴ�
	SqList* L;
	L = (SqList*)malloc(sizeof(SqList));

	//��ʼ�����Ա�
	InitList(L);
	
	int l = Length(L);
	cout << l << endl;

	CreatList(L);
	cout << L->length << endl;
	
	PrintList(L);
	//�������Ա���ӡ������

	//test_LocateElem(L);
	//test_GetElem(L);

	//test_ListDelete(L);
	
	fun01(L);

	PrintList(L);
	
	return 0;
}