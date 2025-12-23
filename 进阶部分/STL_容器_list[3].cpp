#include<iostream>										//list的大小操作 也是一致
#include<list>											//复习...
//打印输出
void print_list(const std::list<int>& L)
{
	for (std::list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		std::cout << *it << ' ';
	}
	std::cout << std::endl;
}
void test01()
{
	std::list<int> L;
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	L.push_back(40);
	std::cout << "L原数据：" << std::endl;
	print_list(L);

	//返回个数
	std::cout << "L容器元素个数：" << L.size() << std::endl;
	//为空返回ture 不为空返回 false
	if (L.empty())
	{
		std::cout << "数据为空" << std::endl;
	}else {
		std::cout << "数据不为空" << std::endl;
	}
	//比原长度大则赋0或自定义数代替 小则删除多余元素
	L.resize(2);
	std::cout << "指定长度2后数据：" << std::endl;
	print_list(L);
	L.resize(10, 66);
	std::cout << "指定长度10并赋值后数据：" << std::endl;
	print_list(L);
}
int main()
{
	test01();
	system("pause");
	return 0;
}