#include<iostream>
class number {
public:
	//构造函数,初始化列表
	number(int frist,int second):m_num1(frist),m_num2(second){}
	//打印输出
	void print() { std::cout << m_num1 << ' ' << m_num2 << std::endl; }
	//两个对象之间相乘
	number operator* (const number& other) const {
		return number(this->m_num1 * other.m_num1, this->m_num2 * other.m_num2);
	}
	//重载版本，当前对象乘以整数
	number operator*(const int& temp) const {
		return number(this->m_num1 * temp, this->m_num2 * temp);
	}
private:
	int m_num1;
	int m_num2;
};
void test() {
	number n1(2, 3), n2(3, 4);
	number n3 = n1 * n2;
	n3.print();
	//重载版本
	//本质调用
	//number n4 = n3.operator*(10);
	number n4 = n3 * 10;
	n4.print();
}
int main() {
	test();
	return 0;
}