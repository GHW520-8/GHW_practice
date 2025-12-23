#include<iostream>				//静态成员变量和函数都有访问权限
class person {
public:
	person()
	{
		std::cout << "person的默认函数调用" << std::endl;
	}

	static void func()			//静态成员函数和静态成员变量都是共享的
	{							//静态成员函数除了静态成员变量以外都不能访问
		age = 18;				//因为是共享的的所以很好访问
		//m_age = 12;			//而非静态的并不是，它是特定的，系统无法区分是哪个对象的属性
		std::cout << "静态成员函数的调用" << std::endl;
	}

	~person() { std::cout << "person的析构函数调用" << std::endl; }
	static int age;		//静态成员变量
	int m_age;
};
						//静态成员变量不属于对象，它是数据共享的
int person::age = 14;	//类内是声明静态成员变量，类外才能初始化
						//编译阶段就分配内存
void test0()
{
	person p1;			//可以通过创建一个对象来调用
	std::cout << "p1.age= " << p1.age << std::endl;
	person p2;
	p2.age = 16;
	std::cout << "p1.age= " << p1.age << std::endl;		//因为是共享，所有无论哪个对数据修改，输出结果都会修改
						//也可以直接使用类名来调用
	std::cout << person::age << std::endl;
}

void test1()
{						//静态成员函数访问方式和静态成员变量一致
	person p1;
	p1.func();
	std::cout << "p1.age= " << p1.age << std::endl;
	person::func();
}

int main()
{
	test0();
	test1();
	system("pause");
	return 0;
}