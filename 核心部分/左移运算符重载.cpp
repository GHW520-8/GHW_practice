#include<iostream>
class person {
	//设置友元
	friend std::ostream& operator<<(std::ostream& create_cout, person& p1);
public:
	person(int a, int b) :m_a(a), m_b(b) {};
	//原式：p.operator << (cout) 简化后为：p << cout
		/*ostream operator<<(ostream &cout){
		//this指针指向的p为左操作数，无法实现cout在左侧
		//不符合我们的使用习惯
		//所以通常使用全局函数做左移运算符重载
		}*/
private:
	int m_a;
	int m_b;
};
//使用全局函数做左移运算符重载
//需要链式操作就需要返回值
std::ostream& operator<<(std::ostream& create_cout, person& p1) {		
	create_cout << "p1.m_a= " << p1.m_a << ' ' << "p1.m_b= " << p1.m_b << std::endl;
	return create_cout;
}
void test01() {
	person p1(10, 20);
	// std::cout << p1; 如果重载没有返回值,那么重载后就只能结束语句
	std::cout << p1 << ' ' << "Holle world!" << std::endl;		
	//本质调用：operator<<(std::cout,p1)...;
}
int main() {
	test01();
	return 0;
}