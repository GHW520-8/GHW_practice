#include<iostream>
class dad1 {
protected:
	dad1() : m_a(12) {}
	int m_a;
};
class dad2 {
public:
	int m_a = 14;
private:
	int m_b;
};
class son : public dad1, public dad2 {
public:
	int m_d = 15;
	//若多个基类都存在同名函数，直接访问会触发二义性
	//可以使用using指定访问哪个基类的成员
	using dad1::m_a;
};
void test01() {
	son s;
	//使用using后可以直接访问指定的成员
	std::cout << "dad1的m_a = " << s.m_a << std::endl;
	//也可以使用作用域访问
	std::cout << "dad2的m_a = " << s.dad2::m_a << std::endl;
	std::cout << "对象s占用的内存字节数：" << sizeof(s);
}
int main() {
	test01();
	return 0;
}