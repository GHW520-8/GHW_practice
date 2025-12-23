#include<iostream>
class point {
	//全局函数做友元
	friend point operator-(const point& frist, const point& second);
public:
	//设置点
	point(int x, int y) : m_a(x), m_b(y) {}
	//打印输出
	void print() { 
		std::cout << m_a << ' ' << m_b; 
	}
private:
	int m_a;
	int m_b;
};
//使用全局函数重载 " - "
point operator-(const point& frist,const point& second) {
	//创建临时对象返回
	return point(frist.m_a - second.m_a, frist.m_b - second.m_b);
}

void test01() {
	//创建并调用有参构造函数
	point a(20, 10), b(10, 5);
	//这里也是使用了减号运算重载才简化了
	//全局函数重载本质
	//point c = operator-(a, b);

	point c = a - b;
	//打印输出
	c.print();
}
int main() {
	test01();
	return 0;
}