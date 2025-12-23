#include<iostream>
//加法函数
int add(int num1, int num2)
{
	return num1 + num2;
}
//减法函数
int minus(int num1, int num2)
{
	return num1 - num2;
}
//乘法函数
int multiply(int num1, int num2)
{
	return num1 * num2;
}
int main()
{
	//定义函数指针 初始化
	int (*ptr)(int, int) = nullptr;
	//将函数指针指向某个函数
	ptr = add;
	//ptr = minus;
	//ptr = multiply;
	int num = ptr(2, 4);
	std::cout << num << std::endl;
	return 0;
}