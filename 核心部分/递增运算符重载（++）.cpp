#include<iostream>
class my_integer {
	friend std::ostream& operator<<(std::ostream& my_cout, my_integer myint);//给左移重载做友元
public:
	//使用初始化列表给成员变量赋初值
	my_integer():m_num(0){}
	//重载++运算符——前置(先自增)
	my_integer& operator++() {
		//前置版本需要返回引用，支持链式操作
		++m_num;
		return *this;
	}
	//重载++运算符——后置(后自增)		
	my_integer operator++(int) {			
		//这里的int是作为占位参数，做重载时就可以与其他函数区分
		//后置的设计理念是后自增，所以返回的是临时对象
		my_integer temp = *this;
		m_num++;
		return temp;
	}
private:
	int m_num;
};
//左移运算符重载
std::ostream& operator<<(std::ostream& my_cout, my_integer myint) {																
	my_cout << "myint= " << myint.m_num << std::endl;
	return my_cout;
}
void test01() {
	my_integer myint;
	//链式调用本质：
	//operator<<(operator<<(std::cout,"前置："),myint.operator++().operator++());
	//因为前置返回的是引用，所以可以链式调用和输出
	std::cout << "前置：" << ++(++myint);	

	std::cout << myint << std::endl;
	//链式调用本质：
	//operator<<(std::cout,myint).operator<<(std::endl);
}
void test02() {
	my_integer myint;
	//参数写什么无所谓，它只是一个占位参数，没有具体形参接收
	//后置递增不能返回引用，所以就不能链式调用
	std::cout << "后置：" << (myint++)++ ;
	std::cout << myint << std::endl; //理想输出 2 实际为 1
}
int main() {
	test01();
	test02();
	return 0;
}