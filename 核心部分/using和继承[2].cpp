#include<iostream>
class dad {
protected:
	void func(int) {
		std::cout << "dad的函数重载" << std::endl;
	}
	double m_a = 3.14;
};
class son : public dad {
public:
	void func() {
		std::cout << "son的成员函数" << std::endl;
	}
	int m_a = 10;
public:
	using dad::func;
	//即使类型和值都不同，但是引入后导致二义性，编译失败
	//using dad::m_a;
};
void test01() {
	son s;
	s.func();
	s.func(10);
	//发生错误
	//std::cout << s.m_a << std::endl;
}
int main() {
	test01();
	return 0;
}