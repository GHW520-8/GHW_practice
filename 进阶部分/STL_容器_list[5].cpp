#include<iostream>							//list容器的存取 front() and back() 
#include<list>								//list容器的反转和排序 reverse() and sort()
//声明比较函数
bool desc(int v1, int v2);

//打印输出
void print_list(const std::list<int>& L)
{
	for (std::list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		std::cout << *it << ' ';
	}
	std::cout << std::endl;
}

//存取
void test01()
{
	std::list<int> L;				//list不支持at()和[]访问数据，因为他是一个链表，不是连续的线性空间存储数据，迭代器也不支持随机访问
	L.push_back(10);				//只要能自增或自减，他就是双向迭代器或更高级的  迭代器能 "it=it+1"  他就是随机访问迭代器
	L.push_back(20);
	L.push_back(30);
	L.push_back(40);
	std::cout << "L原数据：" << std::endl;
	print_list(L);

	//返回第一个元素
	std::cout << "第一个元素：" << std::endl;
	std::cout << L.front() << std::endl;

	//返回最后一个元素
	std::cout << "最后一个元素：" << std::endl;
	std::cout << L.back() << std::endl;

}
//反转和排序
void test02()
{
	std::list<int> L2;
	L2.push_back(1);
	L2.push_back(4);
	L2.push_back(5);
	L2.push_back(3);
	L2.push_back(2);
	std::cout << "L2原数据：" << std::endl;
	print_list(L2);

	//反转  ----将大局逆转吧
	L2.reverse();
	std::cout << "L2反转后数据：" << std::endl;
	print_list(L2);

	//排序  升序						不支持随机访问迭代器的容器不能直接使用标准库的算法
	L2.sort();						//	但是内部会提供对应的一些算法函数
	std::cout << "L2排序后数据(升序)：" << std::endl;
	print_list(L2);
	
	//降序								如果要实现降序必须提供一个比较函数，让程序知道两个元素的相对顺序，
									 // 同时这个比较函数我们可以自定义各种复杂的排序规则，灵活性很强
	L2.sort(desc);
	std::cout << "L2排序后数据(降序)：" << std::endl;
	print_list(L2);
}
//比较函数
bool desc(int v1,int v2)
{
	return v1 > v2;
}
int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}