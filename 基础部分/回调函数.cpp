#include<iostream>
//给函数指针起别名简化书写
using SORTORD = int (*)(int, int);

//回调函数--降序
int desc(int num1, int num2)
{
	return num1 < num2 ? 1 : 0;
}
//回调函数--升序
int asce(int num1, int num2)
{
	return num1 > num2 ? 1 : 0;
}
//排序函数
void sort(int* arr, int len, SORTORD p)
{
	for (int i = 0; i < len - 1; i++)		//冒泡排序
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			//调用回调函数
			if ( p(arr[j],arr[j + 1]) ) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
//打印输出
void print(int* arr, int len) {

	for (int i = 0; i < len; i++)
	{
		std::cout << arr[i] << "  ";
	}
	std::cout << std::endl;
}

int main()
{
	int arr[10] = { 1,10,2,9,3,8,4,7,5,6 };
	//计算长度
	int len = sizeof(arr) / sizeof(arr[0]);
	//调用排序函数，使用降序方法回调函数
	sort(arr, len, desc);
	print(arr, len);
	return 0;
}
