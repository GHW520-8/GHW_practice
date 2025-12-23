#include<iostream>									//类模板和继承
#include<string>									//类模板的成员函数类外实现
													//具体代码见分文件

//因为类模板在分文件编写的时候，系统逐个读取源文件，不知道到底要实例化哪些的对象，所以出错
//第一种解决办法，直接包含源文件
//#include"xxxxxx.cpp"

//第二种解决方法，将声明和实现放在一个源文件里，加上hpp，是能直观的分辨类模板
#include"类模板的分文件.hpp"
void test01()
{
	Son_person<std::string, int,std::string,int>p("小光", 15);	//这里前两个是子类的指定类型，后两个是父类的
	p.show_son();
}
int main()
{
	test01();
	system("pause");
	return 0;
}