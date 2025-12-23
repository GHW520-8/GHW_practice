#include<iostream>
void func(int& num) {
	std::cout << "普通引用" << std::endl;
}
void func(const int& num) {
	std::cout << "常量引用" << std::endl;
}
//void func(int num){}
//void func(int num,int num2 = 10){}
int main()
{
	//func(10);  错误，出现二义性，避免这种写法
	int num = 10;
	func(num);
	func(10);
	return 0;
}