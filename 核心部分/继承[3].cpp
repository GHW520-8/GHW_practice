#include<iostream>							//C++允许一个类继承多个类 使用 " , "分隔就行
class Animal								//多继承可能会引发同名成员存在，这时候就需要加作用域区分
{											//实际开发不建议使用多继承
public:
	int m_age;
};
											//菱形继承
class sheep :virtual public Animal{};		//使用虚继承解决菱形继承问题：在继承之前加上关键字"virtual"
											//此时就变成虚继承了，而"Animal类"称为虚基类
class tuo :virtual public Animal{};			//虚继承就相当于是继承的指针，指向虚基类表
											//表中包含偏移量，加上之后会找到唯一的数据
class sheep_tuo :public sheep,public tuo	
{
											//vbptr--virtul base pointer(虚基类指针) 它指向vbtable
};											//vbtable--vietul base table(虚基类表)
void test01()
{
	sheep_tuo st;
	st.sheep::m_age = 14;
	st.tuo::m_age = 16;
	//菱形继承时，两个父类拥有相同数据时，就需要使用作用域来区分
	std::cout << "sheep::m_age= " << st.sheep::m_age << std::endl;
	std::cout << "tuo::m_age= " << st.tuo::m_age << std::endl;
	//没有虚继承时就会二义性，导致出错，而虚继承后，数据相当是共享的，所以前面的赋值会被后面的覆盖
	std::cout << "sheep::m_age= " << st.m_age << std::endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}