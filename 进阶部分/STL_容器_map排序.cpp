#include<iostream>								//这里的排序规则制定和set容器差不多
#include<string>
#include<map>

//内置类型指定排序规则
class my_compare {
public:
	//仿函数指定排序规则
	bool operator()(int v1, int v2) const
	{
		return v1 > v2;
	}
};
void test01()
{
	//初始化列表  要包含仿函数所在的类
	std::map<int, int,my_compare> m1{ {1,20}, {4,30}, {5,50}, {2,40}, {3,20}, {6,60} };
	for (const auto& it : m1)
	{
		std::cout << it.first << ' ' << it.second << std::endl;
	}
}

//自定义类型指定排序规则
class person
{
public:
	person(std::string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}
	std::string m_name;
	int m_age;
};

//仿函数更改排序规则
class my_compare2 {
public:
	bool operator()(person p1, person p2) const
	{
		return p1.m_age > p2.m_age;
	}
};
void test02()
{
	//自定义类型排序还是使用set容器比较好 这里是演示方法
	//注意：因为map容器有key 所以要显式自定义的类型 否则编译器不知道哪个是键和值
	//这里person为键 int为值 值必须定义，可以不输出它 这里的int就是一个占位的类型 我们实际并不会用它输出
	std::map<person,int, my_compare2> m1{ {person("小光",14),14},{person("小亮",13),13},
	{person("小王",16),16}, {person("小周",17),17}, {person("小西",12),12} };
	for (const auto& it : m1)
	{
		std::cout << it.first.m_name << ' ' << it.first.m_age << std::endl;
	}
}
int main() 
{
	//test01();
	test02();
	system("pause");
	return 0;
}