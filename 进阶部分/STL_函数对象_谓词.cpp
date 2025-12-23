#include<iostream>				//谓词就是返回bool 类型的普通函数、函数指针、lambda表达式、函数对象 他分为一元谓词和二元谓词
#include<vector>				//一元谓词就是接受一个参数返回bool 二元谓词就是接受两个参数返回bool
#include<algorithm>
class find_five {
public:
	find_five()
	{
		std::cout << "默认构造调用" << std::endl;
	}
	bool operator()(int num) const
	{
		return num > 5;
	}

	bool operator()(int v1, int v2) const
	{
		return v1 > v2;
	}
};
//一元谓词 
void test01()
{
	std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	//find_if(first,last,p)算法 查找范围内第一个满足条件的元素 找到返回元素位置的迭代器 没找到返回给定范围的最后一个元素的迭代器
	//前两个参数是指定的区间 最后一个参数要求为bool类型的一元谓词
	auto pos = std::find_if(v.begin(), v.end(), find_five()); //find_five() 为匿名对象 通过调用默认构造函数创建的
	if (pos != v.end())
	{
		std::cout << "找到了，大于5的数字：" << *pos << std::endl;
	}
	else {
		std::cout << "未找到" <<*pos << std::endl;
	}
}

//二元谓词
void test02()
{
	std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	for (const auto& it : v)
	{
		std::cout << it << ' ';
	}
	std::cout << std::endl;

	//sort算法格式：sort(first,last,comp) 前两个参数是指定的区间 最后一个参数要求为bool类型的二元谓词
	std::sort(v.begin(), v.end(), find_five()); //这里也是创建的匿名对象 通过调用默认构造函数创建的
	for (const auto& it : v)
	{
		std::cout << it << ' ';
	}
}
int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}