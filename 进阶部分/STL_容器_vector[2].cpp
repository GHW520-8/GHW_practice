#include<iostream>								//vector存放自定义类型和容器嵌套
#include<vector>								//救命，不知道以后再来看这个代码的时候自己会是什么表情哈哈哈　　
#include<string>					
class person
{
public:
	person(std::string name,int age):m_name(name),m_age(age){}
	std::string m_name;
	int m_age;
};
void test01()
{
	//容器嵌套就相当于一个二维数组
	//创建一个大容器
	std::vector<std::vector<person*>>v;
	//创建小容器，注意创建的是person类的指针
	std::vector<person*>v1;
	std::vector<person*>v2;
	std::vector<person*>v3;
	std::vector<person*>v4;

	person p1("小光", 14);
	person p2("小亮", 15);
	person p3("小强", 16);
	person p4("小李", 17);

	//因为创建的是person类的指针，所以需要将地址传递
	v1.push_back(&p1);
	v1.push_back(&p2);
	v1.push_back(&p3);
	v1.push_back(&p4);

	v2.push_back(&p1);
	v2.push_back(&p2);
	v2.push_back(&p3);
	v2.push_back(&p4);

	v3.push_back(&p1);
	v3.push_back(&p2);
	v3.push_back(&p3);
	v3.push_back(&p4);

	v4.push_back(&p1);
	v4.push_back(&p2);
	v4.push_back(&p3);
	v4.push_back(&p4);

	//将小容器的数据插入到大容器里
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);

	//通过大容器遍历所有数据
	for (std::vector<std::vector<person*>>::iterator it = v.begin(); it != v.end(); it++)
	{
		//这里对大容器解引用，这样解出来的就是小容器
		for (std::vector<person*>::iterator v_it = (*it).begin(); v_it != (*it).end(); v_it++)
		{
			//因为定义的是person类的指针，而迭代器本身也需要解引用才能读取数据，就构成二级指针，所以这里需要解两层引用
			//也可以解一层引用，通过->访问类成员变量 (*v_it)->...
			std::cout << (**v_it).m_name << ' ' << (**v_it).m_age << '\t';
		}
		std::cout << std::endl << std::endl;
	}
}
int main()
{
	test01();
	system("pause");
	return 0;
}