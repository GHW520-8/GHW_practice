#include<iostream>
#include<list>										//list容器的插入和删除 (复习...)
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

	//头插
	L.push_front(100);
	//尾插
	L.push_back(200);
	std::cout << "插入后L数据：" << std::endl;
	print_list(L);

	//头删
	L.pop_front();
	//尾删
	L.pop_back();
	std::cout << "删除后L数据：" << std::endl;
	print_list(L);

	//指定位置(迭代器) 插入elem的拷贝，并返回新元素的位置
	std::list<int>::iterator it = L.begin();
	it = L.insert(++it, 100);
	std::cout << "插入后L数据：" << std::endl;
	print_list(L);
	std::cout << "返回迭代器：" << *it << std::endl;

	//指定位置插入n个elem  返回指向第一个插入的元素的迭代器
	it = L.begin();
	it=L.insert(++it,8, 888);
	std::cout << "插入后L数据：" << std::endl;
	print_list(L);
	std::cout << "返回迭代器：" << *it << std::endl;

	//在指定位置插入一个区间的数据 返回的迭代器也是指向第一个插入的元素
	std::list<int> L2;
	L2.push_back(1);
	L2.push_back(2);
	L2.push_back(3);
	L2.push_back(4);
	it = L2.begin();
	it=L2.insert(++(++it), L.begin(), L.end());
	std::cout << "插入后L2数据：" << std::endl;
	print_list(L2);
	std::cout << "返回迭代器：" << *it << std::endl;

	//list容器独有的 remove()函数可以移除指定的所有相同的元素  没有返回值
	L2.remove(888);
	std::cout << "移除后L2数据：" << std::endl;
	print_list(L2);

	//删除指定位置的单个元素 返回下一个元素的位置(迭代器)
	it = L2.erase(++++L2.begin());
	std::cout << "单个删除后L2数据：" << std::endl;
	print_list(L2);
	std::cout << "返回迭代器：" << *it << std::endl;

	//删除指定区间里的数据  返回下一个元素的位置 和上面一样(迭代器)
	L2.erase(++++L2.begin(), L2.end());
	std::cout << "区间删除后L2数据：" << std::endl;
	print_list(L2);

	//清空
	L2.clear();
	print_list(L2);
}
int main()
{
	test01();
	system("pause");
	return 0;
}