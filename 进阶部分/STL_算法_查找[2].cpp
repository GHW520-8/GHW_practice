#include<iostream>								 //find_if() 查找符合条件的元素
#include<vector>							//格式：find_if(begin,end,predicate)
#include<algorithm>							//前两个参数是范围 最后一个是谓词
											//lambda表达式格式：[](参数){ return 表达式; } (具体的后面会和c++11特性一起写)
//普通函数定义谓词
bool my_creater(int num)
{
	return num > 5;
}
//查找内置数据类型
void test01()
{
	std::cout << "内置数据类型" << std::endl;
	std::vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };
	//查找大于5的数(条件查找)
	
	//[1] 第一种方法 自定义谓词
	std::cout << "普通函数定义谓词判断：" << std::endl;
	auto pos = std::find_if(v.begin(), v.end(), my_creater);
	if (pos != v.end())
	{
		std::cout << "找到了：" << *pos << std::endl;
	}
	else {
		std::cout << "没找到" << std::endl;
	}

	//[2] 第二种方法 lambda 表达式(强烈推荐)
	std::cout << "lambda表达式定义谓词判断：" << std::endl;
	pos = std::find_if(v.begin(), v.end(), [](auto n) {return n > 8; });
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
	person(std::string name, int age) : m_name(name), m_age(age) {}
	bool operator==(const person& p) const
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

//函数对象定义谓词
class Mycreater {
public:
	bool operator()(person p) const
	{
		return p.m_age > 14;
	}
};
void test02()
{
	std::cout << std::endl << "自定义数据类型" << std::endl;
	std::vector<person> v{ {"小亮",14},{"小光",16},{"小兮",12},{"小李",16} };

	//查找年龄大于14的元素(条件查找)
	//[1] 第一种方法 自定义谓词
	std::cout << "函数对象定义谓词判断：" << std::endl;
	auto pos = std::find_if(v.begin(), v.end(),Mycreater());
	if (pos != v.end())
	{
		std::cout << "找到了！" << std::endl;
		std::cout << "姓名：" << (*pos).m_name << "  年龄：" << (*pos).m_age << std::endl;
	}
	else {
		std::cout << "没找到" << std::endl;
	}

	//第二种方法 lambda 表达式
	std::cout << "lambda表达式定义谓词判断：" << std::endl;
	pos = std::find_if(v.begin(), v.end(), [](auto p) {return p.m_age > 12; });
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
