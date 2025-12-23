#include<iostream>			//交集：set_intersection(begin1,end1,begin2,end2,destination,[compare])
#include<algorithm>			//前四个为两个容器的范围  第五个参数为交集存放的位置  第六个参数是自定义比较函数(二元谓词) 可写可不写
							//注意：使用前必须保证元素是有序序列  默认升序 可以更改排序规则(一定要写入算法内，否则不认识)
#include<vector>
#include<iterator>//使用迭代器适配器最好包含此头文件

							//并集：set_union(begin1,end1,begin2,end2,destination,[compare])  
							//差集：set_defference(begin1,end1,begin2,end2,destination,[compare])   
							//他们两个和交集的格式一样 但功能不同  注意：并集是将两个容器里所有的元素组合到新容器里(自动去重)	
							
							//差集则是：将容器a中有但容器b中没有的元素插入到新的容器 (改变容器位置会影响，改变顺序不会)
							//a:1,2,3 b:2,3,4  a和b的差集：1   b和a的差集：4
							
							//back_inserter(容器对象) 插入迭代器 在容器尾部插入元素，无需手动分配内存空间 可以根据元素自动动态扩展 
							//他是一个迭代器适配器  使用他时会自动调用 push_back()
//打印输出
void my_print(int val)
{
	std::cout << val << ' ';
}

//交集 set_intersection()
void test01()
{
	std::vector<int> v1{ 10,20,0,1,2,4,3,5,-1 };
	//使用排序算法降序排序 因为使用集合算法必须是有序序列
	std::sort(v1.begin(), v1.end(),std::greater<int>());

	std::vector<int> v2{ 4,5,10,-1,0,22,32,21,11,2 };
	std::sort(v2.begin(), v2.end(), std::greater<int>());
	//存放交集的容器
	std::vector<int> v_target;
	//返回值为迭代器 返回最后一个插入的元素的后一个位置
	auto end_it = std::set_intersection(
		v1.begin(), v1.end(), 
		v2.begin(), v2.end(), 
		std::back_inserter(v_target), std::greater<int>());	//使用插入迭代器可以动态扩展并插入  如果自定义了排序，必须写入算法

	//遍历打印输出
	std::for_each(v_target.begin(), v_target.end(), my_print);
	std::cout << std::endl;
}

//并集 set_union()
void test02()
{
	std::vector<int> v1{ 10,20,0,1,2,4,3,5,-1 };
	//使用排序算法降序排序 因为使用集合算法必须是有序序列
	std::sort(v1.begin(), v1.end(), std::greater<int>());

	std::vector<int> v2{ 4,5,10,-1,0,22,32,22,11,2 };
	std::sort(v2.begin(), v2.end(), std::greater<int>());
	//存放并集的容器
	std::vector<int> v_target;
	//返回值为迭代器 返回最后一个插入的元素的后一个位置
	auto end_it = std::set_union(
		v1.begin(), v1.end(),
		v2.begin(), v2.end(),
		std::back_inserter(v_target), std::greater<int>());	//使用插入迭代器可以动态扩展并插入  如果自定义了排序，必须写入算法

	std::for_each(v_target.begin(), v_target.end(), my_print);
	std::cout << std::endl;
}

//差集 set_difference()
void test03()
{
	std::vector<int> v1{ -2,-1,0,1,2,3,4 };

	std::vector<int> v2{ 0,2,3,4,5,6,7 };

	//存放差集的容器
	std::vector<int> v_target;
	//返回值为迭代器 返回最后一个插入的元素的后一个位置
	auto end_it = std::set_difference(
		v1.begin(), v1.end(),
		v2.begin(), v2.end(),
		std::back_inserter(v_target));	//使用插入迭代器可以动态扩展并插入  如果自定义了排序，必须写入算法

	std::for_each(v_target.begin(), v_target.end(), my_print);
	std::cout << std::endl;
	//清空容器内的数据
	v_target.clear();

	//可以发现调换容器的位置，差集会发生改变
	end_it = std::set_difference(
		v2.begin(), v2.end(),
		v1.begin(), v1.end(),
		std::back_inserter(v_target));	

	std::for_each(v_target.begin(), v_target.end(), my_print);
	std::cout << std::endl;


}
int main()
{
	test01();
	test02();
	test03();
	system("pause");
	return 0;
}