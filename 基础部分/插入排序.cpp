#include<iostream>				//插入排序
#include<array>
using namespace std;
int arr[100], n;
void print(int arr[], int n) {
	for (int i = 1; i < n; i++)//因为第一个自然数是有序的，所以从第二元素开始
	{
		int t = arr[i];		//将第二个元素储存在变量t中,此时第二值为空，方便插入
		int j = i;			//将下标存储
		while (j > 0 && t < arr[j - 1]) {//因为是从后往前遍历的，所以当j为0时结束
			arr[j] = arr[j - 1];//当前值比前值小的时候换位
			j--;				//直到当前值与所有前值比较完后才结束
		}
		arr[j] = t;			//最后将拿出来的值放入对应的空位
	}
}
void print2(int arr[], int n) {
	for (int i = 0; i < n; i++)//打印排好顺序后的数组
	{
		cout << arr[i] << ' ';
	}
}
int main()
{
	cout << "插入排序" << endl;
	cout << "请输入数组的长度： " << endl;
	cin >> n;
	cout << "请输入数组的元素： "<<endl;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	print(arr, n);
	print2(arr, n);
	system("pause");
	return 0;
}