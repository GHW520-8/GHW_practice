#include<iostream>							//adjacent_find() 和binary_search()
#include<algorithm>				//格式：adjacent_find(begin,end)  括号里直接给查找的范围就行
#include<vector>				//binary_search(begin,end,value,[comp]) 
#include<functional>			//前两个是查找范围 第三个是查找到元素 第四个是比较函数对象(可不写，默认从小到大升序)

//adjacent_find() 查找相邻重复的元素
void test01()
{
	std::vector<int> v{1,2,3,2,4,2,2,3,5,6,7,2};
	//adjacent_find() 必须相邻重复的元素才能被获取 
	auto pos = std::adjacent_find(v.begin(), v.end());
	if (pos != v.end())
	{
		std::cout << "找到了：" << *pos << std::endl;
	}
	else {
		std::cout << "没找到" << std::endl;
	}
}

//binary_search() 二分查找(折半查找)元素
void test02()
{
	//binary_search() 查找的前提是必须是有序序列才能查找 否则无法正确查找
	std::vector<int> v{ 10,9,8,7,6,5,4,3,2,1 };
	//他默认是从升序查找 如果要降序或者自定义查找规则 可以写入函数对象实现  这里使用了内建函数对象降序查找
	auto ret = std::binary_search(v.begin(), v.end(), 5, std::greater<int>());
	if (ret)
	{
		std::cout << "找到5了" << std::endl;
	}
	else {
		std::cout << "没找到5" << std::endl;
	}
}

int main()
{
	test01();
	test02();
	return 0;
}