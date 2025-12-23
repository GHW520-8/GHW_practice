#include<iostream>
class my_integer {
	//友元声明
	friend std::ostream& operator<<(std::ostream& my_cout, const my_integer& other);
public:
	//初始化列表，默认参数
	my_integer(int num = 5):m_num(num){}
	//前置递减
	my_integer& operator--() {
		--this->m_num;
		return *this;
	}
	//后置递减
	my_integer operator--(int) {
		return my_integer(this->m_num--);
	}
private:
	int m_num;
};
//左移运算符重载
std::ostream& operator<<(std::ostream& my_cout, const my_integer& other) {
	my_cout << "m_num = " << other.m_num;
	return my_cout;
}
//前置递减操作
void test01() {
	my_integer myint;
	//链式操作本质调用
	//operator<<(operator<<(std::cout, "前置："), myint.operator--().operator--()).operator<<(std::endl);
	std::cout << "前置：" << --(--myint) << std::endl;
	std::cout << myint << std::endl;
}
//后置递减操作
void test02() {
	my_integer myint2;
	std::cout << "后置：" << (myint2--)-- << std::endl;
	//理想输出 3 实际输出 4
	std::cout << myint2 << std::endl;
}
int main() {
	test01();
	test02();
	return 0;
}