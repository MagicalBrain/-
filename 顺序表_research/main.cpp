#include <iostream>
#include "List.h"
#include "TestForFuntion.h"

using namespace std;

int func01(SqList* L)
/*
������ P18 �ڶ��µڶ��� �ۺ���1
*/
{
	int min,loca=0,l=Length(L);

	if (l == 0)
	{
		cout << "�����Ա�Ϊ�գ��޷�ɾ������fun01��" << endl;
		return 0;
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
		return 1;
		//cout<<""
	}
}

int func02(SqList* L)
/*
������ P18 �ڶ��µڶ��� �ۺ���2
*/
{
	int t;
	if (Length(L) < 1)
	{
		cout << "���Ա�Ϊ�գ�" << endl;
		return 0;
	}
	else
	{
		for (int i = 0; i < (Length(L) /2); i++)
		{
			t = L->elem[i];
			L->elem[i] = L->elem[Length(L) - 1 - i];
			L->elem[Length(L) - 1 - i] = t;
		}
		return 1;
	}
		
}

int func03(SqList* L)
/*
������ P18 �ڶ��µڶ��� �ۺ���3
*/
{
	//int l = Length(L), t;
	int e;
	cout << "����Ҫɾ���ļ�ֵ��" << endl;
	cin >> e;
	if (Length(L) < 1)
	{
		cout << "���Ա�Ϊ�գ�" << endl;
		return 0;
	}
	else
	{
		for (int i = 0; i < Length(L); i++)
		{
			if (L->elem[i] == e)
				ListDelete(L, i);
		}
		return 1;
	}
}

int func04(SqList* L)
/*
������ P18 �ڶ��µڶ��� �ۺ���4
*/
{
	int s, t,l=Length(L),p;
	cout << "����Ҫɾ����Ԫ��ֵ�ķ�Χ��" << endl;
	cin >> s >> t;

	if (l < 1)
	{
		cout<<"���Ա��Ȳ�����"<<endl;
		return 0;
	}
	else if (s >= t)
	{
		cout << "������ֵ��Χ������" << endl;
		return 0;
	}
	else
	{
		for (int i = 0; i < l; i++)
		{
			if (L->elem[i] > s && L->elem[i] < t)
			{
				p = L->elem[i + 1];
				int n = 0;
				while (p > s && p < t)
				{
					ListDelete(L, i + 1 + n);
					n++;
					p = L->elem[i + 1 + n];
				}
				ListDelete(L, i);
			}
		}
	}
	return 1;
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

int test()
{
	//�ȷ����ڴ�
	SqList* L, * L1;
	L = (SqList*)malloc(sizeof(SqList));
	L1 = (SqList*)malloc(sizeof(SqList));

	//��ʼ�����Ա�
	InitList(L);
	InitList(L1);

	int l = Length(L);
	cout << l << endl;

	CreatList(L);
	cout << L->length << endl;

	PrintList(L);
	//�������Ա���ӡ������

	//test_LocateElem(L);
	//test_GetElem(L);
	//test_ListDelete(L);

	//func01(L);
	//func02(L);
	//func03(L);
	func04(L);

	PrintList(L);
	//DestroyList(L);

	return 1;
}

int main()
{
	test();
	return 0;
}