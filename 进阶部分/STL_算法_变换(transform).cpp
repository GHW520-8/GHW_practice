#include<iostream>				//变换算法 transform() 将一个容器的元素转移到另一个容器
				//注意：新容器必须先开辟足够的空间  不同类型的容器也可以转移 但是必须通过转换函数转换为目标容器类型
#include<vector>				//格式：transform(begin1,end1,begin2,func)
#include<algorithm>				//第一个参数是原容器起始迭代器 第二个参数是原容器结束迭代器 
								//第三个参数是目标容器的起始迭代器 第四个参数是函数或者函数对象
#include<functional> //内置的函数对象
//函数对象输出
class my_print {
public:
	void operator()(int val) const
	{
		std::cout << val << ' ';
	}
};
void test01()
{
	//原容器
	std::vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };
	//目标容器
	std::vector<int> v2;
	//事先开辟内存空间
	v2.resize(v.size());
	//变换算法     negate 取反  
	std::transform(v.begin(), v.end(),v2.begin(), std::negate<int>());
	//逆序排序
	std::sort(v2.begin(), v2.end());
	//遍历输出
	std::for_each(v2.begin(), v2.end(), my_print());
	std::cout << std::endl;
	//输出原容器的元素  可以发现元素并没有发生改变
	std::for_each(v.begin(), v.end(), my_print());
	//如果要修改原容器的元素 可以变换同一个容器
}
int main()
{
	test01();
	system("pause");
	return 0;
}
