#include<iostream>
struct data {
	union {
		int num1{ 10 };
		long num2;
	};
}d1;

int main()
{
	std::cout << d1.num1 << std::endl;
	d1.num2 = 20;
	std::cout << d1.num2 << std::endl;
	std::cout << d1.num1 << std::endl;
	data d2{ 520 };
	std::cout << d2.num1 << std::endl;
	return 0;
}