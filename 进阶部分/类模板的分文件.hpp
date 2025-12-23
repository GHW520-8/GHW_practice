#pragma once
#include<iostream>
#include<string>
template<typename T3, typename T4>
class Dad_person
{
public:
	T3 m_name;										//父类是模板类时，子类必须要指定父类的类型  格式：父类名<类型>
	T4 m_age;										//如果想要灵活改变类型，只需要将子类也模板化
};
template<typename T1, typename T2, typename T3, typename T4>
class Son_person :public Dad_person<T3, T4>			//父类的模板参数有几个就指定几个	    
{
public:
	Son_person(T1 name, T2 age);	//使用了子类的模板化
	void show_son();
};

template<typename T1, typename T2, typename T3, typename T4>
Son_person<T1, T2, T3, T4>::Son_person(T1 name, T2 age) //类模板类外实现必须连同模板的声明，参数一同写，不然会认为是一个全局函数
{
	this->Dad_person<T3, T4>::m_name = name;			//明确指定的是父类里的成员变量，同时也要将模板参数一同写
	this->Dad_person<T3, T4>::m_age = age;
}

template<typename T1, typename T2, typename T3, typename T4>	//成员函数同理
void Son_person<T1, T2, T3, T4>::show_son()
{
	std::cout << "姓名：" << this->Dad_person<T3, T4>::m_name << std::endl;
	std::cout << "年龄：" << this->Dad_person<T3, T4>::m_age << std::endl;
}
