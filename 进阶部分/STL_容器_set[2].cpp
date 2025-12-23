#include<iostream>								//set容器的插入删除  查找和统计
#include<set>

//打印输出
void print_set(std::set<int>& s)
{
	for (std::set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		std::cout << *it << ' ';
	}
	std::cout << std::endl;
}

//set容器的插入与删除
void test01()
{
	std::set<int> s{ 10,40,30,20,50 }; //c++11标准后可以直接使用花括号初始化
	//set容器的插入目前常用就 insert()
	/*s.insert(10);
	s.insert(40);
	s.insert(30);
	s.insert(20);
	s.insert(50);*/
	print_set(s);

	//删除指定位置的元素 
	//set/multiset 容器由于底层是二叉树的数据结构 不是连续的存储空间 所以也不支持随机访问 双向迭代器
	s.erase(++s.begin());
	print_set(s);

	//删除指定区间的元素
	s.erase(++++s.begin(),s.end());
	print_set(s);

	//删除指定的元素
	s.erase(30);
	print_set(s);
	
	//清空
	s.clear();
	print_set(s);
	if (s.empty())
	{
		std::cout << "数据为空" << std::endl;
	}
}

//查找和统计
void test02()
{
	std::cout << std::endl;
	std::set<int> s;
	std::set<int>::iterator it;
	//set容器的插入目前常用就 insert()
	s.insert(10);
	s.insert(40);
	s.insert(30);
	s.insert(20);
	s.insert(50);
	print_set(s);

	//查找元素  find()  找到了返回元素的迭代器 没找到返回end()
	it = s.find(10);
	if(it!=s.end()){ 
		std::cout <<"找到了：" << *it << std::endl;
	}
	else {
		std::cout << "没找到" << std::endl;
	}

	//统计个数   因为set容器不会存在重复值 所以count()函数的返回值只有 1 或 0   multiset可以返回重复的个数
	std::cout << s.count(10) << std::endl;
}
int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}