#include<iostream>												//复习
#include<list>											//list容器的赋值和交换(基本一致)
														//注意的时，list是操作的指针，并且无法也不需要收缩内存
//打印输出
void print_list(const std::list<int>& L)
{
	for (std::list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		std::cout << *it << ' ';
	}
	std::cout << std::endl;
}
//赋值  assign()和"="
void test01()
{
	std::list<int> L;
	L.push_back(1);
	L.push_back(2);
	L.push_back(3);
	L.push_back(4);
	std::cout << "L原数据：" << std::endl;
	print_list(L);

	std::list<int> L2;
	L2.push_back(11);
	L2.push_back(22);
	L2.push_back(33);
	L2.push_back(44);
	std::cout << "L2原数据：" << std::endl;
	print_list(L2);

	//n个elem拷贝
	std::cout << "使用n个elem拷贝后L原数据：" << std::endl;
	L.assign(6, 666);
	print_list(L);

	//将区间内的值拷贝
	L2.assign(L.begin(),L.end());
	std::cout << "拷贝L后L2数据：" << std::endl;
	print_list(L2);

	//使用operator重载的"="
	std::list<int> L3 = L2;
	std::cout << "用L2赋值后L3原数据：" << std::endl;
	print_list(L3);

}

//交换  注意的是，list容器是交换指针，而不是真实数据  所以他无法实现像vectro那样收缩内存
void test02()
{
	//交换数据
	std::cout << std::endl << "交换：" << std::endl;
	std::list<int> L;
	L.push_back(1);
	L.push_back(2);
	L.push_back(3);
	L.push_back(4);
	std::cout << "L原数据：" << std::endl;
	print_list(L);

	std::list<int> L2;
	L2.push_back(11);
	L2.push_back(22);
	L2.push_back(33);
	L2.push_back(44);
	std::cout << "L2原数据：" << std::endl;
	print_list(L2);

	std::cout << "互换后L数据：" << std::endl;
	L2.swap(L);
	print_list(L);

	std::cout << "互换后L2数据：" << std::endl;
	print_list(L2);

}
int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}