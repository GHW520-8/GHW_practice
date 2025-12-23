#include<iostream>					/				"list容器"(链表容器)
						链表就是将数据链式存储，它是非连续的结构，通过指针来链接每个节点
						节点有两部分组成："数据域"和"指针域"  数据域存储真实数据  而指针域存储下一个节点的地址，
					这样就可以通过指针指向下一个节点，实现链式结构  "头节点无前驱 尾节点next指针为NULL 只能由头遍历到尾，这就是单向链表"
					而每个节点都额外存储着上一个节点的地址，可以实现"反向遍历"，这就是"双向链表"
					STL里的list容器底层采用的是"双向循环链表"，他的头节点的前驱为最后一个节点，尾节点的next指针指向第一个元素，组成了一个"循环"

				因为链表的存储方式不是连续的内存空间，因此迭代器只支持前移后移，属于"双向迭代器"
				他也是采用动态存储分配，不会造成内存的浪费溢出  链表的插入删除很方便，直接操作指针就可以，并且"不会"使"原迭代器失效(重要区别)"
				因为指针域的存在，他的内存空间占用比较大  遍历耗时比较多
							*/
#include<list>
//打印输出
void print_list(const std::list<int>& L)
{
	for (std::list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		std::cout << *it << ' ';
	}
	std::cout << std::endl;
}
void test01()							//list的构造函数(其实容器的构造函数都差不多，这里是复习)
{
	//默认构造
	std::list<int> L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	print_list(L1);
	//拷贝构造
	std::list<int> L2(L1);
	print_list(L2);

	//区间内拷贝
	std::list<int> L3(L2.begin(),L2.end());
	print_list(L3);

	//n个elem拷贝
	std::list<int> L4(6, 666);
	print_list(L4);

}
int main()
{
	test01();
	system("pause");
	return 0;
}