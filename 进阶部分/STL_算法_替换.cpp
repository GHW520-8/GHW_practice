#include<iostream>						//replace(begin,end,old_value,new_value) 按照给定的具体的值替换
#include<vector>						//前两个参数为范围 后两个参数分别为旧元素和新元素

#include<algorithm>						//replace_if(begin,end,perdicate,new_value) 按照条件替换
										//前两个参数为范围 第三个参数为一元谓词 第四个元素为替换的值
										
										//swap(容器1，容器2) 注意：他们必须是同一种容器 同类型
//打印输出
void my_print(int val)
{
	std::cout << val << ' ';
}

//replace() 替换算法 按照给定的值替换
void test01()
{
	std::vector<int> v{ 1,2,2,4,5,2,7,8,2,10 };

	//满足值为2 的替换为20
	std::replace(v.begin(), v.end(), 2, 20);

	//遍历算法打印输出
	std::for_each(v.begin(), v.end(), my_print);
	std::cout << std::endl;
}

//repalce_if() 按照给定的条件替换
void test02()
{
	std::vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };
	//将满足条件的值全部替换
	std::replace_if(v.begin(), v.end(), [](auto num) { return num % 2 == 1; },666);

	//遍历算法打印输出
	std::for_each(v.begin(), v.end(), my_print);
}
int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}