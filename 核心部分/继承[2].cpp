#include<iostream>					//使用构造函数时，编译器会先执行父类的构造函数再执行子类的构造函数
									//而使用析构函数则相反，编译器会先执行子类再执行父类		
class dad {							//当发生重名时，需要加上作用域 " 父类 :: " 非静态函数和变量也同理
public:								//当子类出现和父类重名的静态成员函数时
	static void func() {			//系统会自动隐藏父类中所有重名的静态成员函数
		std::cout << "dad--静态成员函数" << std::endl;
	}
	static void func(int) {
		std::cout << "dad--重载静态成员函数" << std::endl;
	}
	static int m_a;
};

int dad::m_a = 100;

class son :public dad {
public:
	static void func() {
		std::cout << "son--静态成员函数" << std::endl;
	}
	static int m_a;
};

int son::m_a = 200;
//访问重名的静态成员变量
void test01() {
	son s1;
	std::cout << "创建对象访问：" << std::endl;
	std::cout << "dad--d1.m_a= " << s1.m_a << std::endl;
	std::cout << "son--d1.m_a= " << s1.dad::m_a << std::endl;	//只需要加上父类的作用域就行

	std::cout <<std::endl<< "类名直接访问：" << std::endl;
	std::cout << "dad--d1.m_a= " << son::m_a << std::endl;
	std::cout << "son--d1.m_a= " << son::dad::m_a << std::endl;	
}											//第一个"::"代表通过类名的方式	// 第二个"::"是父类的作用域

void test02() {
	son s1;
	std::cout << "创建对象访问：" << std::endl;
	s1.func();
	s1.dad::func();

	std::cout << std::endl << "类名直接访问：" << std::endl;
	son::func();
	son::dad::func();

	//son::func(100);		
	son::dad::func(100);		
}
int main() {
	test01();
	std::cout << "-----------我是分割线----------" << std::endl;
	test02();
	system("pause");
	return 0;
}