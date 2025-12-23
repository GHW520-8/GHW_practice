#include<iostream>
void test01();
void test02();
int main()
{
	int a = 10;
	//使用取地址符将a的地址存储
	int* p = &a;
	std::cout << &a << std::endl;
	std::cout << p << std::endl;
	//使用解引用输出指针指向内存中的数据
	std::cout << *p << std::endl;  // 10
	int b = 20;
	p = &b;
	*p = 666;
	std::cout << b << std::endl;
	test01();
	return 0;
}
//数组指针
void test01()
{
	int a = 10;
	int b = 20;
	int c = 30;
	int* arr[3] = { &a,&b,&c };
	std::cout << *arr[2] << std::endl;
	//字符串指针数组
	const char* names[] = {"Mike","Alice","Bob"};
	std::cout << names[0] << std::endl;
}

//多级指针
void test02()
{
	int num = 10;
	//一级指针，指向 int的指针
	int* p = &num;
	//二级指针，指向 int* 的指针
	int** p2 = &p;
	//三级指针，指向 int** 的指针
	//依次类推...
	int*** p3 = &p2;
	*p = 10;
	**p2 = 20;
	***p3 = 30;
}

void test03()
{
	int arr1[4][5];
	int (*p)[5] = arr1;

	int arr2[4][5][6];
	int (*p2)[5][6] = arr2;

	int arr3[5] = { 1,2,3,4,5 };
	int (*ptr)[5] = &arr3;

	int arr4[4][5];
	int (*ptr)[4][5] = &arr4;

	int arr[4][5];
	int (*p)[5] = arr;

	int arr2[4][5][6];
	int (*p)[5][6] = arr2;
}