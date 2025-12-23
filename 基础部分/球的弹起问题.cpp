#include<iostream>
using namespace std;
int main(){
	double high, rest;
	cout << "请输入球的高度："<<endl;
	cin >> high;
	rest = high;
	int i = 1;
	while (i < 10)
	{
		 high= high / 2.0;
		 rest += 2*high;
		 i++;
	}
	cout << rest << endl;
	cout << high / 2.0 << endl;
}