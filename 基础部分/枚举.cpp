#include<iostream>
enum data {
	first,
	second,
	third = 'A',
	fourth
}da1;
int main()
{
	da1 = first;
	std::cout << da1 << std::endl;
	data da2 = fourth;
	std::cout << (char)da2 << std::endl;
	da2 = (data)52;
	std::cout << da2 << std::endl;
	int value = da1;
	return 0;
}