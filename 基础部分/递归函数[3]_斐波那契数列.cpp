#include<iostream>
int fibonacci(int num)
{
	//前两项为 1 
	if (num <= 2)
	{
		return 1;
	}
	//第三项开始为前两项相加
	else {
		return fibonacci(num - 1) + fibonacci(num - 2);
	}
}
int main()
{
	//输出斐波那契数列的前10项
	for (int i = 1; i <= 10; i++)
	{
		std::cout << fibonacci(i) << ' ';
	}
	return 0;
}