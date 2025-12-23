#include<iostream>								//将person自定义类型排序，姓名，年龄，身高
#include<list>									//按照年龄升序排序，如果相同按升高降序排序
#include<string>
class person
{
public:
	person(std::string name, int age, int high)
	{
		this->m_name = name;
		this->m_age = age;
		this->m_high = high;
	}
	std::string m_name;
	int m_age;
	int m_high;
};

//打印输出
void print_person(const std::list<person>& L)
{
	std::cout << "姓名\t" << "年龄\t" << "身高(cm)\t" << std::endl;
	for (std::list<person>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		//迭代器本质上就是个指针，所以需要解引用或者使用 -> 指向数据
		std::cout << (*it).m_name <<'\t'<< it->m_age <<'\t'<< (*it).m_high << std::endl;
	}
}
//自定义排序规则
bool p_sort(person& p1, person& p2)
{
	//判断 如果年龄相同按照身高降序排序
	if (p1.m_age == p2.m_age)
	{
		return p1.m_high > p2.m_high;
	}
	else { //否则按照年龄升序排序
		return p1.m_age < p2.m_age;
	}
}
void test01()
{
	std::list<person> L;
	person p1("小光", 14, 170);
	person p2("小李", 19, 176);
	person p3("小王", 19, 173);
	person p4("小亮", 14, 168);
	person p5("小周", 19, 178);
	person p6("小江", 16, 173);

	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);
	std::cout << "排序前：" << std::endl;
	print_person(L);

	std::cout << "排序后：" << std::endl;
	L.sort(p_sort);
	print_person(L);
}
int main()
{
	test01();
	system("pause");
	return 0;
}