#include<iostream>
int add(int num)
{
	if (num <= 0)
	{
		return 0;
	}
	else
	{
		return num + add(num - 1);
	}

}
int main()
{
	int sum = add(10);
	std::cout << sum << std::endl;
	return 0;
}