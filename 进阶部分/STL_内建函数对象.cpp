#include<iostream>								//STL为我们提供了一些内置的函数对象供我们使用
#include<vector>								//算术仿函数  关系仿函数 逻辑仿函数
#include<algorithm>								//超超超超超爱 STL!!!!!
#include<functional>//要使用内建的函数对象必须包含此头文件

//算术内建函数对象
void test01()
{
	//一元仿函数 取反：negate
	std::negate<int>n1;
	std::cout<<n1(10)<<std::endl;

	//二元仿函数 加 减 乘 除 取模		 关键字：加：plus 减：minus 乘：multiplies 除：divides 取模：modulus
	std::plus<int> n2; //注意这里虽然是二元谓词 但是类型声明只需要一个 因为只能同类型之间算术运算
	std::cout << n2(11, 4) << std::endl;
}

//关系内建函数对象
void test02()
{
	std::vector<int> v{ 1,3,2,5,4,6,7,10,8,9 };
	for (const auto& it : v)
	{
		std::cout << it << ' ';
	}
	std::cout << std::endl;
	//降序排序 大于">"：greater       等于：equal_to 不等于：not_equal_to 大于等于：greater_equal 小于：less 小于等于：less_equal
	std::sort(v.begin(), v.end(), std::greater<int>());  //注意必须声明对象类型因为是模板类  这里也是匿名对象
	for (const auto& it : v)
	{
		std::cout << it << ' ';
	}
	std::cout << std::endl;

}

//逻辑内建函数对象  不常用
void test03()
{
	std::vector<bool> v{ true,false,true,false,true };
	for (const auto& it : v)
	{
		std::cout << it << ' ';
	}
	std::cout << std::endl;

	std::vector<bool> v2;
	//实现开辟v2的空间，否则无法将数据转移
	v2.resize(v.size());
	
	//转移算法  前两个参数为指定原容器要转移数据的范围  第三个参数是新容器接收数据的位置  第四个参数可以使用函数对象制定一些规则
	// logical_not 逻辑非  logical_and 逻辑与  logical_or  逻辑或
	std::transform(v.begin(), v.end(), v2.begin(), std::logical_not<bool>());
	for (const auto& it : v2)
	{
		std::cout << it << ' ';
	}
	std::cout << std::endl;
}
int main()
{
	//test01();
	//test02();
	test03();
	system("pause");
	return 0;
}