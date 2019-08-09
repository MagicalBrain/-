#include <iostream>
#include "List.h"
#include "TestForFuntion.h"
#include "func.h"

using namespace std;

/*
main.cpp
只放测试函数和主函数
*/

int test()
{
	//先分配内存
	SqList* L0, * L, * L1;
	L = (SqList*)malloc(sizeof(SqList));
	L0 = (SqList*)malloc(sizeof(SqList));
	L1 = (SqList*)malloc(sizeof(SqList));

	//初始化线性表
	InitList(L);
	InitList(L1);
	InitList(L0);

	CreatList(L,L1,1);
	//CreatList(L,0);

	//cout << endl;
	//CreatRand1();
	//PrintList(L);
	//PrintList(L1);
	//PrintList(L1);
	//创建线性表并打印，结束

	//int l = Length(L);
	//cout << l << endl;

	//test_LocateElem(L);
	//test_GetElem(L);
	//test_ListDelete(L);
	
	/*
	int l1, l2;
	cout << "输入两线性表长度:" << endl;
	cin>>l1>>l2;
	L = testForfunc08(l1,l2);
	*/
	

	//func01(L);
	//func02(L);
	//func03(L);
	//func04(L);
	//func05(L);
	//func06(L);
	L0 = func07(L, L1);

	PrintList(L0);
	cout << L0->length << "	中位数：" << L0->elem[L0->length / 2 - 1] << endl;
	cout<<"序号："<< L0->length / 2 << endl;

	//func08(L, l1, l2);

	/*
	int n;
	cout << "输入查找键值：" << endl;
	cin >> n;
	func09(L, n);
	*/
	//func10(L);
	cout << "中位数： "<<func11(L, L1) << endl;

	cout << "L1:" << endl;
	PrintList(L);
	cout << L->length << endl;
	cout << "L2:" << endl;
	PrintList(L1);
	
	//DestroyList(L);

	return 1;
}

int main()
{
	test();
	return 0;
}