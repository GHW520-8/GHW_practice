#include<iostream>									//遍历算法 for_each()
#include<vector>							//格式：for_each(begin,end,_func) 
#include<algorithm>				//第一个参数是起始迭代器 第二个参数是结束迭代器 第三个参数是函数或函数对象
//自定义函数输出
void print_num(const int& val)
{
	std::cout << val << ' ';
}

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
	std::vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };
	//使用自定义函数
	std::cout << "自定义函数输出" << std::endl;
	std::for_each(v.begin(), v.end(), print_num);
	std::cout << std::endl;

	//使用函数对象
	std::cout << "函数对象输出" << std::endl;
	std::for_each(v.begin(), v.end(), my_print());
	std::cout << std::endl;

}
int main()
{
	test01();
	system("pause");
	return 0;
}
