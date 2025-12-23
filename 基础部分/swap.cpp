#include"swap.h"
void swap(int a, int b)
{
	std::cout << a<<'\t'<<b << std::endl;
}
int main()
{
	int x = 10, y = 3;
	int* p=(int *)0x11000;
	std::cout << *p<<'\t';
	swap(x, y);
	system("pause");
	return 0;
} 