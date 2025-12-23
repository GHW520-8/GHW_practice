#include<iostream>
using namespace std;
void temp(int *arr,int len) {//传递过来的arr其实是数组的首地址，所以定义一个指针变量arr接收地址
	for (int i = 0; i < len - 1; i++)		//冒泡排序
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (arr[j] > arr[j + 1]) {//这里的换位其实是对原数组的值换位，地址不会发生任何改变
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
void print(int* arr, int len) {

	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << endl;
	}
}
int main() {
	int arr[10] = { 1,10,2,9,3,8,4,7,5,6 };
	int len = sizeof(arr) / sizeof(arr[0]);//数组总长度/数组中一个元素的长度=数组中元素的个数
	//注意：长度为定义变量类型的长度  如int  4  char  1
	cout << sizeof(arr) <<' '<<sizeof(arr[2]) <<endl;
	temp(arr, len);
	print(arr, len);
	system("pause");
	return 0;
}