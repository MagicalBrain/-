#include <iostream>
#include "List.h"
#include "TestForFuntion.h"
#include "func.h"

using namespace std;

/*
main.cpp
ֻ�Ų��Ժ�����������
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

	//CreatList(L,L1,1);
	CreatList(L,0);

	//cout << endl;
	//CreatRand1();
	//PrintList(L);
	//PrintList(L1);
	//PrintList(L1);
	//�������Ա���ӡ������

	//int l = Length(L);
	//cout << l << endl;

	//test_LocateElem(L);
	//test_GetElem(L);
	//test_ListDelete(L);
	
	/*
	int l1, l2;
	cout << "���������Ա���:" << endl;
	cin>>l1>>l2;
	L = testForfunc08(l1,l2);
	*/
	

	//func01(L);
	//func02(L);
	//func03(L);
	//func04(L);
	//func05(L);
	//func06(L);
	//L = func07(L, L1);

	PrintList(L);
	cout << L->length << endl;

	//func08(L, l1, l2);

	/*
	int n;
	cout << "������Ҽ�ֵ��" << endl;
	cin >> n;
	func09(L, n);
	*/
	func10(L);

	PrintList(L);
	cout << L->length << endl;
	//PrintList(L1);
	//DestroyList(L);

	return 1;
}

int main()
{
	test();
	return 0;
}