#include<iostream>				//public 公共权限，类外类内都可以访问
#include<string>				//protected 保护权限，类内可以访问,类外不可以访问
using namespace std;			//private 私有权限，类内可以访问,类外不可以访问
class student {//类的语法
public://设置类的访问权限，默认私有，当前函数可以设置为公共权限

	//类中的属性和行为统一称为成员
	// 属性 成员变量 成员属性 
	// 行为 成员函数 成员方法

	//设置类的属性
	string s_name, s_id;
	//设置类的行为
	void enla() {
		cout << "姓名：" << s_name << '\t' << "学号：" << s_id << endl;
	}
	void set_name(string name)//可以通过行为直接给属性赋值
	{
		s_name = name;
	}
	void set_id(string id)
	{
		s_id = id;
	}
};
int main()
{
	student s1;		//实例化对象
	s1 = { "张三","E21278" };
	s1.enla();

	s1.set_name("老王");	//通过调用赋值函数实现修改属性
	s1.set_id("E00110");
	s1.enla();

	system("pause");
	return 0;
}