#include<iostream>
int* max_value(int* arr, int len)
{
	int* max = &arr[0];
	for (int i = 0; i < len; i++)
	{
		if (*max < arr[i])
		{
			max = &arr[i];
		}
	}
	return max;
}
	int main()
	{
		int arr[]{ 1,3,2,5,9,8,10 };
		int len = sizeof(arr) / sizeof(arr[0]);
		int* ptr = nullptr;
		ptr = max_value(arr, len);
		std::cout << *ptr << std::endl;
		return 0;
	}