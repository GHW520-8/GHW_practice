#include<iostream>
class divide {
	//全局函数做友元
	friend divide operator/(const divide& frist, const divide& second);
	friend divide operator/(const divide& frist, int num);
public:
	//构造函数初始化列表
	divide(int num1,int num2):m_num1(num1),m_num2(num2){}
	//打印输出
	void print() { std::cout << m_num1 << ' ' << m_num2 << std::endl; }
private:
	int m_num1;
	int m_num2;
};
//对象 / 对象
divide operator/(const divide& frist, const divide& second) {
	return divide(frist.m_num1 / second.m_num1, frist.m_num2 / second.m_num2);
}
//对象 / 整数
divide operator/(const divide& frist, int num) {
	return divide(frist.m_num1 / num, frist.m_num2 / num);
}
void test() {
	divide d1(100, 200), d2(25, 20);
	divide d3 = d1 / d2;
	d3.print();
	//重载版本，本质调用
	//divide d4 = operator/(d3, 2);
	divide d4 = d3 / 2;
	d4.print();
}
int main() {
	test();
	return 0;
}