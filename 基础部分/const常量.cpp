#include<iostream>
using namespace std;
const int SIZE{ 10 };
int main() {
	int a = 10;
	int b = 10;

	int* const p1 = &a;//指针常量  指针本身就是一个常量，它的指向不可更改，但值可以更改
	*p1 = 100;
	//p1 = &b;  错误

	const int* p = &a;//常量指针  指向常量的指针，它本质就是一个指针，它的指向可以更改，但是不能通过它来修改值
	//*p = 20;  错误
	p = &b;
	const int* const p2 = &a;//常量指针常量  都不可变
	//*p2 = 100;
	//p2 = &b;

	cout << p << endl;//输出地址
	cout << *p << endl;//解引用  输出值
	int y = 2;
	const int a = y  + 10;
	return 0;
	system("pause");
}