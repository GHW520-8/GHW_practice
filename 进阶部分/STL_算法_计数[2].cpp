#include<iostream>						//count_if(begin,end,perdicate)  按照条件统计元素出现次数
#include<vector>						//perdicate 为一元谓词
#include<algorithm>
#include<string>

//内置数据类型计数
void test01()
{
	std::vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };
	//almbda 表达式
	auto num = std::count_if(v.begin(), v.end(), [](auto num) { return num % 2 == 1; });
	std::cout << "容器里奇数的有" << num << "个" << std::endl;
}

//自定义数据类型计数
class person {
public:
	person(std::string name, int age) :m_name(name), m_age(age) {}
	std::string m_name;
	int m_age;
};
void test02()
{
	std::vector<person> v{ {"小亮",12},{"小光",13},{"小兮",14},{"小李",15},{"小王",16} };

	//almbda 表达式
	auto num = std::count_if(v.begin(), v.end(), [](auto p) { return p.m_age >= 13; });
	std::cout << "年龄大于等于13的有" << num << "个" << std::endl;
}

int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}