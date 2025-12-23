#include<iostream>					//去重排序
using namespace std;
int len, n;
void print2(int b[], int n) {
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)//冒泡排序
			if (b[j] > b[j + 1]) {
				int temp = b[j];
				b[j] = b[j + 1];
				b[j + 1] = temp;
		}
	}
	for (int i = 0; i < n; i++)			//输出
	{
		cout << b[i] << ' ';
	}
}
void print(int a[],int b[],int len)
{
	for (int i = 0; i < len; i++)//外层循环控制次数
	{
		bool h = false;
		for (int j = 0; j < n; j++)
		{
			if (a[i] == b[j])//当两个数相等的时候跳出循环(去重操作)
			{
				h = true;
				break;
			}
		}
		if (!h)				//n的初始值为0，直接将数组a的值赋给数组b
		{					//当后面的值不同的时候再赋值
			b[n] = a[i];
			n++;			//记录数组b中的元素
		}
	}
	print2(b, n);
}
int main()
{
	int a[100], b[100];
	cout << "请输入数组的长度：" << endl;
	cin >> len;
	cout << "请输入数组中的元素： " << endl;
	for (int i = 0; i < len; i++)
	{
		cin >> a[i];
	}
	print(a,b,len);
	system("pause");
	return 0;
}