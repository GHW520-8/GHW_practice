#include<iostream>									//类模板对象做函数参数
#include<string>
template<typename T1,typename T2>
class person
{
public:
	person(T1 name, T2 age) :m_name(name),m_age(age){}
	void show_temp()
	{
		std::cout << "姓名：" << this->m_name << std::endl;
		std::cout << "年龄：" << this->m_age << std::endl;
	}
	T1 m_name;
	T2 m_age;
};
//[1] 指定传入类型--显式指定类型 ( 最常用 )
void print_person1(person <std::string, int> &p)
{
	p.show_temp();
}

void test01()
{
	person <std::string, int>p("孙悟空", 999);
	print_person1(p);
}

//[2] 参数模板化--将对象的参数变为模板传递
template<typename T1,typename T2>
void print_person2(person <T1, T2>& p)
{
	p.show_temp();
	//typeid()可以返回参数的类型
	std::cout << "T1的类型：" << typeid(T1).name() << std::endl;
	std::cout << "T2的类型：" << typeid(T2).name() << std::endl;
}

void test02()
{
	person <std::string, int>p("猪八戒", 1111);
	print_person2(p);
}

//[3] 整个类模板化--将对象类型模板化传递
template<typename T>
void print_person3(T & p)
{
	p.show_temp();
	std::cout << "T的类型：" << typeid(T).name() << std::endl;
}

void test03()
{
	person <std::string, int>p("唐僧", 40);
	print_person3(p);
}
int main()
{
	test01();
	test02();
	test03();
	system("pause");
	return 0;
}