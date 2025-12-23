#include<iostream>					//加号运算符重载  operator+
class person						//内置的数据类型不可能更改
{									//不要滥用运算符重载
public:
	//person operator+ (person& p)	//使用成员函数实现加号重载
	//{								//this指针指向的是p1,传进来的是p2
	//	person temp;
	//	temp.m_a = this->m_a + p.m_a;
	//	temp.m_b = this->m_b + p.m_b;
	//	return temp;
	//}
	int m_a;
	int m_b;
};

//全局函数实现加号重载
person operator+(person& p1, person& p2)
{
	person temp;
	temp.m_a = p1.m_a + p2.m_a;
	temp.m_b = p1.m_b + p2.m_b;
	return temp;
}
//运算符重载并且函数也是重载
person operator+(person& p3, int num)
{
	person temp;
	temp.m_a = p3.m_a + num;
	temp.m_b = p3.m_b + num;
	return temp;
}
void test01()
{
	person p1;
	p1.m_a = 10;
	p1.m_b = 10;

	person p2;
	p2.m_a = 10;
	p2.m_b = 10;					//这里是使用了加号重载才简化了，原式为 成员函数："p3=p1.operator+(p2)"
	person p3 = p1 + p2;			//全局函数："p3=operator+(p1,p2)"
	std::cout << "p3.m_a= " << p3.m_a << std::endl;
	std::cout << "p3.m_b= " << p3.m_b << std::endl;
	std::cout << "p3.m_a+p3.m_b= " << p3.m_a + p3.m_b << std::endl;
	person p4 = p3 + 100;			//运算符重载也可以发生函数重载 "p4=operator+(p3,100)"
	std::cout << "p4.m_a= " << p4.m_a << std::endl;
	std::cout << "p4.m_b= " << p4.m_b << std::endl;
	std::cout << "p4.m_a+p4.m_b= " << p4.m_a + p4.m_b << std::endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}