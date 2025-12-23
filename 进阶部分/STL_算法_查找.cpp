#include<iostream>									//查找算法
#include<vector>								//find() 查找具体元素
#include<algorithm>							//格式：find(begin,end,value)   前两个是范围 后一个是具体查找的元素

//查找内置数据类型
void test01()
{
	std::cout << "内置数据类型" << std::endl;
	std::vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };

	//查找具体元素 5
	auto pos = std::find(v.begin(), v.end(), 2);
	//找到了会返回元素的位置迭代器，没找到会返回end()
	if (pos != v.end())
	{
		std::cout << "找到了：" << *pos << std::endl;
	}
	else {
		std::cout << "没找到" << std::endl;
	}
}

//查找自定义类型
class person {
public:
	person(std::string name,int age): m_name(name),m_age(age){}

	//使用find查找自定义类型的值时必须重载"=="比较符  因为编译器不知道比较规则     *first==value
	//因为find()算法实际上就是一个模板类 我们使用他时就指定了类型 使他可以通过迭代器解引用得到我们的对象 从而找到重载的版本
	bool operator==(person p) const
	{
		if (this->m_name == p.m_name && this->m_age == p.m_age)
		{
			return true;
		}
		else {
			return false;
		}
	}
	std::string m_name;
	int m_age;
};
void test02()
{
	std::cout << std::endl << "自定义数据类型" << std::endl;
	//使用初始化列表不会实例化对象
	std::vector<person> v{ {"小亮",14},{"小光",16},{"小兮",12},{"小李",16} };
	//所以我们使用find()需要实例化对象 这里使用的是匿名对象查找符合的元素  emplace_back()也是
	
	//查找自定义类型的具体的元素
	auto pos = std::find(v.begin(), v.end(), person("小亮", 14));
	if (pos != v.end())
	{
		std::cout << "找到了！" << std::endl;
		std::cout << "姓名：" << (*pos).m_name << "  年龄：" << (*pos).m_age << std::endl;
	}
	else {
		std::cout << "没找到" << std::endl;
	}
}
int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}
