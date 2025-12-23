#include<iostream>							//函数模板特化
#include<string>							//提供了函数模板就最好不要提供普通函数，否则容易出现二义性
class person {
public:
	person(std::string name,int age):m_name(name),m_age(age){}
	std::string m_name;
	int m_age;
};

template<typename T>		//实现函数模板特化必须要有主模板，函数名也必须相同
bool flie(T& a, T& b) {		//函数模板不是万能的，例如结构体，数组，类的一些特殊实现就无法满足(比较、运算...)
	if (a == b) {
		return true;
	}
	else {
		return false;
	}
}
//格式: template<> 
//类型 重载的函数名 <类型>(可省略）(有具体类型的形参)
//如果函数名后不显式指定类型，编译器会自动推导
template<>
bool flie<person>(person& p1, person& p2) {  //使用函数模板重载，提供具体化的模板 
	if (p1.m_name == p2.m_name && p1.m_age == p2.m_age) {
		return true;
	}
	else {
		return false;
	}
}
void test01() {
	int a = 10;
	int b = 20;
	bool ret = flie(a, b);
	if (ret) {
		std::cout << "a==b" << std::endl;
	}
	else {
		std::cout << "a!=b" << std::endl;
	}
}
void test02() {
	person p1("小亮", 14);
	person p2("小光", 16);
	bool ret = flie(p1, p2);
	if (ret) {
		std::cout << "p1==p2" << std::endl;
	}
	else {
		std::cout << "p1!=p2" << std::endl;
	}
}
int main() {
	test01();
	test02();
	system("pause");
	return 0;
}