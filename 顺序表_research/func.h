#pragma once
#include <iostream>
#include "List.h"
#include "CreatFuntion.h"

using namespace std;

/*
func.h
对应于2020王道书上的P18页的习题的解决函数
*/

int func01(SqList* L)
/*
王道书 P18 第二章第二节 综合题1
*/
{
	int min, loca = 0, l = Length(L);

	if (l == 0)
	{
		cout << "该线性表为空，无法删除！（fun01）" << endl;
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
王道书 P18 第二章第二节 综合题2
*/
{
	int t;
	if (Length(L) < 1)
	{
		cout << "线性表为空！" << endl;
		return 0;
	}
	else
	{
		for (int i = 0; i < (Length(L) / 2); i++)
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
王道书 P18 第二章第二节 综合题3
*/
{
	//int l = Length(L), t;
	int e;
	cout << "输入要删除的键值：" << endl;
	cin >> e;
	if (Length(L) < 1)
	{
		cout << "线性表为空！" << endl;
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
王道书 P18 第二章第二节 综合题4
*/
{
	int s, t, l = Length(L), p;
	cout << "输入要删除的元素值的范围：" << endl;
	cin >> s >> t;

	if (l < 1)
	{
		cout << "线性表长度不合理！" << endl;
		return 0;
	}
	else if (s >= t)
	{
		cout << "输入数值范围不合理！" << endl;
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

int func05(SqList* L)
/*
王道书 P18 第二章第二节 综合题5
*/
{
	int s, t, l = Length(L), p;
	cout << "输入要删除的元素值的范围：" << endl;
	cin >> s >> t;

	if (l < 1)
	{
		cout << "线性表长度不合理！" << endl;
		return 0;
	}
	else if (s >= t)
	{
		cout << "输入数值范围不合理！" << endl;
		return 0;
	}
	else
	{
		for (int i = 0; i < l; i++)
		{
			if (L->elem[i] >= s && L->elem[i] <= t)
			{
				p = L->elem[i + 1];
				int n = 0;
				while (p >= s && p <= t)
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

int func06(SqList* L)
/*
王道书 P18 第二章第二节 综合题6
*/
{
	int l = Length(L), num = 0, flag = 0;
	ElemType* p;

	if (l < 1)
	{
		cout << "线性表长度不合理" << endl;
		return 0;
	}
	else
	{
		p = (ElemType*)malloc(l * sizeof(ElemType));
		p[0] = L->elem[0];
		num = 1;


		for (int i = 1; i < l; i++)
		{
			for (int j = 0; j < num; j++)
			{
				if (L->elem[i] != p[j])
				{
					flag++;
				}
			}
			if (flag == num)
			{
				p[num] = L->elem[i];
				num++;
			}
			flag = 0;
		}


		for (int i = 0; i < num; i++)
		{
			L->elem[i] = p[i];
		}
		L->length = num;
	}
	return 1;
}

SqList* func07(SqList* L1, SqList* L2)
/*
王道书 P18 第二章第二节 综合题7
*/
{
	int l1 = Length(L1), l2 = Length(L2), num = 0;
	SqList* re;
	re = (SqList*)malloc(sizeof(SqList));

	InitList(re);

	if (l1 >= 1 && l2 >= 1)
	{
		int i = 0, j = 0;
		while (i < l1 && j < l2)
		{
			if (L1->elem[i] < L2->elem[j])
			{
				ListInsert(re, L1->elem[i], num);
				i++;
			}
			else
			{
				ListInsert(re, L2->elem[j], num);
				j++;
			}
			num++;
		}
		if (i < l1)
		{
			for (int k = i; k < l1; k++)
			{
				ListInsert(re, L1->elem[k], num);
				num++;
			}
		}
		else if (j<l2)
		{
			for (int k = j; k < l2; k++)
			{
				ListInsert(re, L2->elem[k], num);
				num++;
			}
		}

		return re;
	}

	return NULL;
}

int func08(SqList*L,int m,int n)
/*
王道书 P18 第二章第二节 综合题8
备注：算法逻辑应该是没问题的，但是不知道哪里出问题了，
一到main函数的return 0程序就会崩溃。
*/
{
	SqList* re;
	re = (SqList*)malloc(sizeof(SqList));
	InitList(re);

	if (L->length > 0 && m > 0 && n > 0)
	{
		for (int i = 0; i < n; i++)
		{
			re->elem[i] = L->elem[m + i];
		}
		for (int i = 0; i < m; i++)
		{
			re->elem[n+i] = L->elem[i];
		}
		L = re;
		return 1;
	}

	return 0;
}

int func09(SqList* L,int e)
/*
王道书 P18 第二章第二节 综合题9
备注：
*/
{
	int l = Length(L),mid,flag=1;
	ElemType tmp;
	if (l > 0)
	{
		if (e > L->elem[l - 1])
		{
			ListInsert(L, e, l);
		}
		else if (e < L->elem[0])
		{
			ListInsert(L, e, 0);
		}
		else
		{
			mid = l / 2;
			while (flag)
			{
				if (e < L->elem[mid])
				{
					l = mid;
					mid = l / 2;
				}
				else if (e > L->elem[mid])
				{
					mid = (l + mid) / 2;
				}
				else if(e == L->elem[mid])
				{
					//flag = 0;
					tmp = L->elem[mid];
					L->elem[mid] = L->elem[mid + 1];
					L->elem[mid + 1] = tmp;
					break;
				}
				if (flag == Length(L))
				{
					ListInsert(L, e, l);
					break;
				}
				flag++;
				//break;
			}
			
		}
		return 1;
	}
	return 0;
}

int func10(SqList* L)
/*
王道书 P18 第二章第二节 综合题10
备注：
*/
{
	int l = Length(L),n,t;
	cout << "输入左移的位数：" << endl;
	cin >> n;
	if (l>0 && n>0)
	{
		for (int i = 0; i < n; i++)
		{
			t = ListDelete(L, l - 1);
			ListInsert(L, t, 0);
		}
		return 1;
	}
	cout << "左移失败！" << endl;
	return 0;
}

int func11(SqList* L1,SqList*L2)
/*
王道书 P18 第二章第二节 综合题11
备注：
*/
{
	int l1 = Length(L1), l2 = Length(L2);
	int re = 0, num = 0;

	if (l1 > 0 && l2 > 0)
	{
		int i = 0, j = 0;
		while (num<l1)
		{
			if (L1->elem[i] < L2->elem[j])
			{
				re = L1->elem[i];
				i++;
			}
			else
			{
				re = L2->elem[j];
				j++;
			}
			num++;
		}

		i--; j--;

		if (L1->elem[i]  < L2->elem[j])
		{
			re = L2->elem[j];
		}
		else
		{
			re = L1->elem[i];
			
		}
		
		return re;
	}

	return 0;
}

int func12(SqList* L)
{
	int l = Length(L), num = 0, flag = 0;
	ElemType* p;

	if (l < 1)
	{
		cout << "线性表长度不合理" << endl;
		return 0;
	}
	else
	{
		p = (ElemType*)malloc(l * sizeof(ElemType));
		p[0] = L->elem[0];
		num = 1;

		for (int i = 1; i < l; i++)
		{
			for (int j = 0; j < num; j++)
			{
				if (L->elem[i] != p[j])
				{
					flag++;
				}
			}
			if (flag == num)
			{
				p[num] = L->elem[i];
				num++;
			}
			flag = 0;
		}

		for (int i = 0; i < num; i++)
		{
			cout << p[i] << " ";
		}
		cout << endl;

		ElemType* n = (ElemType*)malloc(num*sizeof(ElemType));
		//SqList* re = (SqList*)malloc(sizeof(SqList));

		for (int i = 0; i < num; i++)
		{
			n[i] = 0;
			for (int j = 0; j < l; j++)
			{
				if (p[i] == L->elem[j])
				{
					n[i]++;
				}
			}
			if (n[i] > l/2)
			{
				return p[i];
			}
		}
	}

	return -1;
}

//有序顺序表求交集的函数 (该函数存在问题，输出结果不对！)
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