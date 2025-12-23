#include<iostream>
inline int add(int a,int b)
{
	return a + b;
}
int main()
{
	std::cout << add(10, 20) << std::endl;
	return 0;
}