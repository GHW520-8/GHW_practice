#include<iostream>					//accumulate(begin,end,value)  前两个是范围 最后一个是起始累加值 就是这个value + ...
#include<vector>					//fill(begin,end,value)  前两个是范围 最后一个是填充值 
#include<algorithm>
#include<numeric> //要使用数值算法必须包含此头文件 小型算法

//打印输出
void my_print(int val)
{
	std::cout << val << ' ';
}

// 区间内容器元素累加
void my_sum(std::vector<int>& v)
{
	//可以发现他是12+区间里元素的总和
	auto sum = std::accumulate(v.begin(), v.end(), 12);
	//总和
	std::cout << "总和："<< sum << std::endl;

}

void test01()
{
	std::vector<int> v;
	//填充元素也需要事先开辟内存空间 否则无法正常输出
	v.resize(8);
	//这里是填充了n个3
	std::fill(v.begin(), v.end(), 3);

	//遍历算法打印输出
	std::for_each(v.begin(), v.end(), my_print);
	std::cout << std::endl;
	my_sum(v);
}
int main()
{
	test01();
	system("pause");
	return 0;
}