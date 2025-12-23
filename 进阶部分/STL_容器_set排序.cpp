#include<iostream>							     	//指定排序规则
#include<initializer_list>  //c++11引进了初始化列表，方便初始化一些容器之类的 (头文件可以不必包含 因为大多数容器隐式包含了)
#include<set>				//并且可以不用"=" 可以像数组结构体一样使用"{ }"初始化 (不过要用这个类必须包含)

//使用仿函数指定排序规则
class num {
public:
	//仿函数实际上就是有"()"的重载的类，其对象使用重载的调用运算符功能和函数差不多  这里必须加const 因为容器里规定了不能修改
	bool operator()(int n1,int n2) const
	{
		return n1 > n2;
	}
};
//内置类型指定排序规则
void test01()
{
	//使用c++11的初始化列表 方便多了
	//注意：要修改排序规则必须定义仿函数并把所在的类定义进来
	std::set<int,num> s{ 20,30,10,40,50 };  

	//c++11的范围性for循环和auto自动推导类型(方便多了) 这个后面我会自己单独写介绍  
	//这里使用引用防止拷贝，使用const防止修改 
	for (const auto& it : s)
	{
		//这里的for循环遍历的是容器自身，所有不用做解引用操作
		std::cout << it << ' ';
	}
	std::cout << std::endl;

}

//使用自定义类型排序规则
class person {
public:
	
	std::string m_name;
	int m_age;
};
//仿函数
class my_compare {
public:
	bool operator()(person p1, person p2) const
	{
		return p1.m_age > p2.m_age;
	}
};
void test02()
{
	//初始化列表 只能定义声明的时候使用 其他的时候最好使用 emplace_back() emplace_front()
	std::set<person, my_compare> s{ {"小光",14},{"小亮",13},{"小王",16},{"小周",17},{"小西",12} };
	std::cout << "姓名\t" << "年龄" << std::endl;
	for (const auto& it : s)
	{
		std::cout << it.m_name << '\t' << it.m_age << std::endl;
	}
	std::cout << std::endl;
}
int main()
{
	test01();
	test02();
	system("pause");
	return 0;

}