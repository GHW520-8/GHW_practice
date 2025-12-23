#include<iostream>								//类模板和友元
#include<string>								//为什么出问题我也不道啊，也没招了，为了进度先继续了，反正代码和老师的大差不差
//提前让编译器知道								//记住尽量使用类内实现，不然可读性太差，别人看代码会被骂死！！！
template<typename T1, typename T2>				//防御性代码可以哈哈哈( 狗头 狗头 )
class person;

template<typename T1, typename T2>
void print_person2<>(const person<T1, T2>& p)
{
	std::cout << "友元全局函数类外实现" << p.m_name << '\t'<< p.m_age << std::endl;
}
//先看这里
template<typename T1,typename T2>
class person
{
	//使用friend关键字实现全局函数类内实现 友元全局函数
	friend void print_person(const person<T1,T2>& p)	//这里就相当于一个普通的全局函数，可以任意定义各种类型使用
	{
		std::cout << p.m_name <<'\t'<< p.m_age << std::endl;
	}
	//使用friend关键字实现全局函数类内声明，类外实现
	//如果要使这个函数模板化，在函数名后加上空模板参数列表"<>"
	//必须要先让编译器认识这个全局函数
	friend void print_person2<>(const person<T1, T2>& p);

public:
	person(T1 name, T2 age)
	{
		this->m_name = name;
		this->m_age = age;
	}
private:
	T1 m_name;
	T2 m_age;
};
void test01()
{
	person <std::string, int>p("小光", 14);
	print_person(p);
}
void test02()
{
	person<std::string, int>p2("小亮", 18);
	print_person2(p2);
}
int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}