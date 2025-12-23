#include<iostream>
union data {
	double dob;
	int num;
}d1{ 3.14 };
int main()
{
	std::cout << "dob=" << d1.dob << std::endl;
	d1.num = 10;
	std::cout << "num=" << d1.num << std::endl;
	std::cout << "dob=" << d1.dob << std::endl;
	d1.dob = 13.14;
	std::cout << "dob=" << d1.dob << std::endl;
	std::cout << "num=" << d1.num << std::endl;
	return 0;
}