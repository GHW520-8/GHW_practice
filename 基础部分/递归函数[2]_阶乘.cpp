#include<iostream>
long long multiply(int num)
{
	if (num <= 1)
	{
		return 1;
	}
	else
	{
		return num * multiply(num - 1);
	}

}
int main()
{
	long long mult = multiply(10);
	std::cout << mult << std::endl;
	return 0;
}