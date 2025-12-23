#include<iostream>						//sort(begin,end,perdicate)排序算法 和 random_shuffle(begin,end)随机洗牌算法
#include<vector>						
#include<algorithm>
#include<ctime>

//使用sort()排序
void test02(std::vector<int>& v2)
{
	//最后一个参数是谓词，可以自定义，也可以直接使用内建的函数对象
	std::sort(v2.begin(), v2.end(), std::greater<int>());
	for (const auto& it : v2)
	{
		std::cout << it << ' ';
	}
	std::cout << std::endl;
}

//随机洗牌算法
void test01()
{
	std::vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };

	std::random_shuffle(v.begin(), v.end());    //randdom_shuffle()在c++14就被废弃了 <random>库的shffle()取代
	for (const auto& it : v)					//救命看不懂这个库，后面用到的时候再学
	{
		std::cout << it << ' ';
	}
	std::cout << std::endl;
	test02(v);
}

int main()
{
	//使用随机数种子保证每次随机结果不同
	srand((unsigned int)time(nullptr));
	test01();
	system("pause");
	return 0;
}