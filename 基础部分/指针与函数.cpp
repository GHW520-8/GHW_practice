#include<iostream>
//指针作为函数参数
void test01(int* num)
{
	*num = 666;
}

int main()
{
	int x = 10;
	std::cout << x << std::endl;
	test01(&x);
	std::cout << x << std::endl;
	return 0;
}
