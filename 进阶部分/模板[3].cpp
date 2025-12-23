#include<iostream>							//类模板
#include<string>			//普通类的成员函数一开始就创建
							//类模板的成员函数只有在调用的时候才创建	
							//当使用通用类型创建对象，并在类模板里的成员函数调用，此时只要未编译就不会报错
							//而当编译的时候，编译器就不知道是哪个类的对象，就会失败，而普通类未编译也会报错
template<typename nameType,typename ageType=int> //可以定义多个通用类型,类模板可以使用默认参数
class person	
{
public:
	person(nameType name, ageType age)
	{
		this->m_name = name;
		this->m_age = age;
	}
	void show_info()
	{
		std::cout << "name=" << this->m_name << std::endl;
		std::cout << "age=" << this->m_age << std::endl;
	}
	std::string m_name;
	int m_age;
};
void test01()
{	//因为使用了默认参数，所以只需要指定未使用的类型
	person<std::string> p1("小亮", 16);	//在调用模板函数时，必须要显式指定类型
	p1.show_info();						//因为类模板没有自动推导的使用方式
}
int main()
{
	test01();
	system("pause");
	return 0;
}