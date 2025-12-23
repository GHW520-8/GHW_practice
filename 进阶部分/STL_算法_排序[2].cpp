#include<iostream>						//merge(begin1,end1,begin2,end2,destination) 合并算法 必须有序
#include<vector>						//前四个分别是两个容器的范围 第五个参数为目标容器的位置
#include<algorithm>						//reverse(begin,end) 反转算法 即颠倒元素的顺序  可以无序
//函数声明
void test02(std::vector<int>& v);

//打印输出
void my_print(int v)
{
	std::cout << v << ' ';
}

//merge() 合并算法
void test01()
{
	//合并的容器必须是有序序列
	std::vector<int> v{ 1,2,3,4,5 };
	std::vector<int> v2{ 6,7,8,9,10 };
	std::vector<int> v_target;
	//必须事先开辟需要的内存空间
	v_target.resize(v.size() + v2.size()-3);

	//将 v和v2 合并到 v_target
	std::merge(v.begin()+1, v.end(), v2.begin()+2, v2.end(), v_target.begin());

	//利用遍历算法打印输出
	std::for_each(v_target.begin(), v_target.end(), my_print);
	std::cout << std::endl;

	test02(v_target);
}

//reverse() 反转算法
void test02(std::vector<int>& v)
{
	std::reverse(v.begin(), v.end());

	//利用遍历算法打印输出
	std::for_each(v.begin(), v.end(), my_print);
	std::cout << std::endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}