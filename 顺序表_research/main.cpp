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

	

	//CreatList(L,L1);
	CreatList(L,1);

	cout << endl;
	//CreatRand1();
	PrintList(L);
	//PrintList(L1);
	//�������Ա���ӡ������

	//int l = Length(L);
	//cout << l << endl;

	//test_LocateElem(L);
	//test_GetElem(L);
	//test_ListDelete(L);

	//func01(L);
	//func02(L);
	//func03(L);
	//func04(L);
	//func05(L);
	func06(L);

	PrintList(L);
	//PrintList(L1);
	//DestroyList(L);

	return 1;
}

int main()
{
	test();
	return 0;
}