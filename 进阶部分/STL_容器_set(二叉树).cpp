#include<iostream>						//set和multiset容器的底层就是一个红黑树的结构 他们都属于关联式容器
#include<set>							//所有元素在插入时会自动排序，默认升序
										//set容器不允许有重复的值  而multiset容器可以有重复值  这是设计的目的 与底层的二叉树无关
										//二叉树具体的概念等学到了再来补充
//打印输出
void print_set(std::set<int>& s)
{
	for (std::set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		std::cout << *it << ' ';
	}
	std::cout << std::endl;
}
//set容器的构造和赋值
void test01()								
{
	//默认构造
	std::set<int> s;
	//插入数据							//注意：set和multiset容器 最常用的只有insert()函数  我们目前的学习只会用到他
	s.insert(10);						//当我们插入数据后他会自动排序，并且会自动去重
	s.insert(30);
	s.insert(20);
	s.insert(40);
	s.insert(40);
	print_set(s);

	//拷贝构造
	std::set<int> s2(s);
	print_set(s2);

	//使用重载的 = 赋值
	std::set<int> s3=s2;
	print_set(s3);

}

//set容器的大小和交换
void test02()
{
	std::cout << std::endl;
	std::set<int> s;
	s.insert(3);
	s.insert(2);
	s.insert(4);
	s.insert(1);
	print_set(s);
	//empty()函数判断是否为空 ，空1否0
	if (s.empty())
	{
		std::cout << "数据为空" << std::endl;
	}
	else {
		std::cout << "数据不为空" << std::endl;
	}
	//size()判断容器内数据大小(长度)
	std::cout << "容器大小为" << s.size()<<std::endl;

	std::set<int> s2;
	s2.insert(11);
	s2.insert(44);
	s2.insert(55);
	s2.insert(33);
	std::cout << "s2为" <<  std::endl;
	print_set(s2);
	//swap()互换两个集合容器
	s2.swap(s);
	std::cout << "s互换后" << std::endl;
	print_set(s);
	std::cout << "s2互换后" << std::endl;
	print_set(s2);
}
int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}