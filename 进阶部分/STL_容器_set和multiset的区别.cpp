#include<iostream>
#include<set>       //set容器和multiset容器的头文件都是 set

//打印输出
void print_multiset(const std::multiset<int>& ms)
{
	for (std::multiset<int>::const_iterator it = ms.begin(); it != ms.end(); it++)
	{
		std::cout << *it << ' ';
	}
	std::cout << std::endl;
}
void test01()
{
	std::multiset<int> ms;
	//插入和set 无异
	ms.insert(20);
	ms.insert(20);
	ms.insert(10);
	ms.insert(40);
	ms.insert(30);
	//可以发现他也会自动排序，并且可以输出重复值  因为multiset容器在插入的时候不会检测重复值
	print_multiset(ms);

	//这里使用pair对组来查看不同
	std::set<int> s;
	//对组格式：pair<type1，type2>  他有两个成员变量  一个frist指向第一个传入的值 一个second 指向第二个传入的值
	//因为set容器的insert()使用了pair对组来定义 实际上有两个返回类型，一个迭代器，一个布尔型判断重复
	std::pair<std::set<int>::iterator, bool> ret = s.insert(10);

	//这里的boll型就是判断是否重复的  而second变量就是存储这个布尔型的
	//ture 插入成功 false 插入失败
	if (ret.second)
	{
		std::cout << "第一次插入成功" << std::endl;
	}
	else {
		std::cout << "第一次插入失败" << std::endl;
	}
	//第二次插入同样的值  可以发现就插入失败，这是因为set容器会检测重复的值
	ret = s.insert(10);
	if (ret.second)
	{
		std::cout << "第二次插入成功" << std::endl;
	}
	else {
		std::cout << "第二次插入失败" << std::endl;
	}
	//而multiset容器就不会,因为他不会检测  他直接返回迭代器  具体可以转到定义查看
}

//multiset容器的删除，查询和计数
void test02()
{
	std::cout << std::endl << "删除前：" << std::endl;
	std::multiset<int> ms;
	//插入和set 无异
	ms.insert(2);
	ms.insert(2);
	ms.insert(2);
	ms.insert(1);
	ms.insert(4);
	ms.insert(3);
	print_multiset(ms);

	//查询 find() 他会返回一个迭代器 如果有重复的元素 返回第一个查找到的位置
	
	//count()计数 他可以返回具体的元素个数
	std::cout << " 2 的元素个数为：" << ms.count(2) << std::endl;

	std::cout << "删除后：" << std::endl;
	//multiset容器的删除大多和set一致 但是multiset可以删除所有和指定值相同的元素
	ms.erase(2);
	print_multiset(ms);

}
int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}