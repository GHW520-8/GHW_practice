#include<iostream>						//STL算法主要是由头文件 <algorithm> <functional> <numeric>组成
#include<algorithm>						//其中algorithm是最大的，范围涉及 比较 交换 查找 遍历 复制 修改等
#include<functional>					//functional是预定义好的一些模板类 声明函数对象
#include<numeric>						//而 numeric 是最小的 用于几个序列上进行简单运算的模板函数
						//算法主要通过迭代器访问和操作容器内的数据(统一访问接口)  可以用于容器的各种类型 
						//算法又分为四类 非修改序列操作 修改式序列操作 排序和相关操作 数值操作
						//非修改序列操作：不改变容器的内容，只读取数据 如：find() for_each()
						//修改式序列操作：可以改变容器的内容 可以修改值 也可以修改值的排列顺序 如：transform() copy() random_shuffle()
						//排序和相关操作：包括多个排序函数 合并 二分查找等 包括集合操作(交集 并集 差集 对称差集)
						//数值操作：+ - * / % ... vector容器最常用
int main()
{
	system("pause");
	return 0;
}