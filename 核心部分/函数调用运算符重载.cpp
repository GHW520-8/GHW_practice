#include<iostream>
#include<string>
class my_print {
public:
	//仿函数，打印输出字符串
	void operator()(std::string other) {
		std::cout << other << std::endl;
	}
	//两个数相加
	void operator()(int first, int second) {
		std::cout << first + second << std::endl;
	}
};
void test01() {
	my_print mint;
	//mint.operator()("我爱C++");
	mint("我爱C++");
	//mint.operator()(10,12);
	mint(10, 12);
	//my_print().operator()("匿名对象");
	my_print()("匿名对象");
}
int main() {
	test01();
	return 0;
}