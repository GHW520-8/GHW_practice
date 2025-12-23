#include<iostream>
using namespace std;
namespace number {
	bool flag;
	int num;
}
using namespace number;
int main()
{
	int i=2;
	num = 0;
	flag = true;
	cout << "请输入一个数：" << endl;
	cin >> num  ;
	while (i<num)
	{
		if (num%i == 0)
		{
			flag = false;
		}
		i++;
	}
	if (flag)
	{
		cout << "这个数是质数" << endl;
	}
	else
		cout << "这个数不是质数" << endl;
	system("pause");
	return 0;
}