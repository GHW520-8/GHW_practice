#include<iostream>
//加
int add(int num1, int num2)
{
	return num1 + num2;
}
//减
int minus(int num1, int num2)
{
	return num1 - num2;
}
//乘
int multiply(int num1, int num2)
{
	return num1 * num2;
}
int main()
{
	//定义函数指针数组
	/*int(*arr[3]) (int,int) = {add, minus, multiply};*/
	//typedef int(*Array)(int, int);
	using Array = int(*)(int, int);
	Array arr[3] { add, minus, multiply };
	
	int num1 = 10;
	int num2 = 5;
	for (int i = 0; i < 3; i++)
	{
		//调用每个函数输出结果
		int over = arr[i](num1, num2);
		std::cout << over << " ";
	}
	return 0;
}