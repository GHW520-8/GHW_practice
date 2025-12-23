#include<iostream>
class dad {
public:
	void func() {
		std::cout << "dad成员函数" << std::endl;
	}
	//同名的函数重载
	void func(int) {
		std::cout << "dad函数重载" << std::endl;
	}
	int m_num = 10;
};
class son : public dad {
public:
	//同名的成员函数
	void func() {
		std::cout << "son成员函数" << std::endl;
	}
	//同名的成员变量
	int m_num = 20;
};
void test01() {
	son s;
	s.func();
	std::cout << s.m_num << std::endl;
}
void test02() {
	son s;
	s.dad::func();
	//s.func(100);
	s.dad::func(100);
	std::cout << s.dad::m_num << std::endl;
}
int main() {
	test01();
	test02();
	return 0;
}