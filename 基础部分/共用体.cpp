#include<iostream>
union data {
	int num;
	float f;
}d1{ 10 };
int main()
{
	std::cout << "num=" << d1.num << std::endl;
	d1.f = 6.66;
	std::cout << "f=" << d1.f << std::endl;
	std::cout << "num=" << d1.num << std::endl;
	d1.num = 52;
	std::cout << "num=" << d1.num << std::endl;
	std::cout << "f=" << d1.f << std::endl;
	return 0;
}