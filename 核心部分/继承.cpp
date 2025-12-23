#include<iostream>				
class dad {  //父类也称基类，子类也称派生类
public:
	int m_a;
protected:
	int m_b;
private:
	int m_c;
};
class son :public dad {  //公有继承
public:
	void func() {
		m_a = 10;		//公有还是为公有
		m_b = 10;		//保护还是为保护
		//m_c = 10;		//私有不可访问
	}
	int m_d;
};
void test01()
{
	son s1;
	s1.m_a = 20;		//共有权限依旧正常访问
	//s1.m_b = 20;		//保护权限类外不可以访问
	//s1.m_c = 20;		//私有权限更不能访问

	//父类中的所有非静态成员都会被子类继承下去，而私有权限只是被编译器隐藏了，所以才访问不到
	std::cout << "sizeof of son: " << sizeof(son) << std::endl;

	//可以使用vs的开发者工具查看
	//跳转到文件所在盘  cd 文件目录路径 dir 输入命令：cl /d1 reportSingleClassLayout类名 文件名
} 
class son2 :protected dad {	 //保护继承
public:
	void func() {
		m_a = 5;		//公有变为保护，保护不变
		m_b = 5;
		//m_c = 5;
	}
};
void test02() {
	son2 s2;
	//s2.m_a = 25;		//此时类外都不能访问
	//s2.m_b = 25;
	//s2.m_c = 25;
}
class son3 : private dad {  //私有继承
public:
	void func() {
		m_a = 12;		//所有都变成私有权限
		m_b = 12;
		//m_c = 12;
	}
};
void test03() {
	son3 s3;
	//s3.m_a = 14;		//此时一样都不能访问
	//s3.m_b = 14;
	//s3.m_c = 14;
}
class pro_son :public son3 {  //再定义一个son3的子类
public:
	void func() {
		//m_a = 10;		//因为son3是私有继承，基类成员全为私有权限
		//m_b = 10;		//所以同样都不能访问
		//m_c = 10;
	}
};

int main() {
	test01();
	test02();
	test03();
	system("pause");
	return 0;
}