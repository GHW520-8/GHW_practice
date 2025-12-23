#include<iostream>				//成员函数和成员变量是分开存储的
class person {					//只有非静态成员变量才属于类的对象上
public:
	static void m_t(){}
	void p_m() {}	//非静态函数它也不占用内存，因为它属于类但不属于单个对象 (this指针会用到)

	int m_age_2;		//而当类里定义了非静态成员变量，返回的就是定义类型的字节，它是属于类的对象上的
	static int m_age;
};					//静态成员变量不属于对象，所以它不占用内存,静态成员函数同理

int person::m_age = 12;

void test0()
{
	person p1;
					//当对象为空时系统会默认占用一个字节，为了区分空对象占内存的位置
	std::cout << "p1占用空间为:" << sizeof(p1) << std::endl;
}

int main()
{
	test0();
	system("pause");
	return 0;
}