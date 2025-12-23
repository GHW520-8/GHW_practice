#include<iostream>							//count(begin,end,value) 统计元素个数
#include<vector>							//返回值为整型 没有返回0
#include<algorithm>
#include<string>

//内置数据类型计数
void test01()
{
	std::vector<int> v{ 1,2,2,3,4,3,4,2,5,2 };
	auto num = std::count(v.begin(), v.end(), 2);
	std::cout << "容器里有" << num << "个2" << std::endl;
}

//自定义数据类型计数
class person {
public:
	person(std::string name,int age):m_name(name),m_age(age){}
	//这里判断年龄相同的就行
	bool operator==(const person& p) const
	{
		if (this->m_age == p.m_age)
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
	std::vector<person> v{ {"小亮",14},{"小光",15},{"小兮",14},{"小李",16},{"小王",14} };

	auto num = std::count(v.begin(), v.end(), person("小亮",14));
	std::cout << "和小亮年龄相同的还有" << num-1 << "个" << std::endl;
}

int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}