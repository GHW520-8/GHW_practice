#include<iostream>						//copy(begin,end,destination) 拷贝算法
#include<vector>						//参数三是目标容器位置
#include<algorithm>

//打印输出
void my_print(int val)
{
	std::cout << val << ' ';
}
void test01()
{
	std::vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };
	std::vector<int> v2;

	v2.resize(v.size());
	
	std::copy(v.begin(), v.end(), v2.begin());

	std::for_each(v2.begin()+3, v2.end(), my_print);
}
int main()
{
	test01();
	system("pause");
	return 0;
}	