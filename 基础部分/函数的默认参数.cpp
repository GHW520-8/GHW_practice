#include<iostream>
int func(int a, int b = 30,int c = 20/*,int d*/)
{
	return a + b + c;
}
int main()
{
	std::cout << func(10) << std::endl;
	return 0;
}