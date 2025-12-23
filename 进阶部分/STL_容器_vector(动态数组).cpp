#include<iostream>							//vector容器的基本使用
#include<vector>					// "vector"容器就相当于一个可以存任意类型的数组，他也称为 " 单端数组 "
									//但是他可以动态扩展，可以将原有的数据拷贝到更大内存的新空间，再插入写入的数据
#include<algorithm>					//他的迭代器支持随机访问
//打印输出
void my_print(int val)
{
	std::cout << val << std::endl;
}
void test01()
{
	std::vector<int>v;
	//向容器里插入数据 "push_back()" 向末尾插入数据 相当于一个模板函数
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	//通过迭代器访问容器里的数据  格式：容器<类型>::迭代器类别 变量名=容器.位置方法
	//这里定义了"iterator"可读写类型的迭代器用于接收获取的容器里的元素
	std::vector<int>::iterator it_begin = v.begin(); //返回指向容器中第一个元素的迭代器 (起始迭代器)
	std::vector<int>::iterator it_end = v.end(); //返回指向末尾后的一个元素的迭代器 (结束迭代器)

	//输出方法
	//[1]使用while循环遍历
	while (it_begin != it_end) 
	{
		//对这个迭代器进行解引用，实际上就是读取容器里的数据
		std::cout << *it_begin << std::endl;
		//对容器里的数据向前推进1位
		it_begin++;
	}
	std::cout << std::endl;

	//[2]使用for循环遍历   这里只需要再次将迭代器指向第一个元素就行了，不需要释放或者置0，因为迭代器就相当于一个指针，只需要改变指向就行了
	for (it_begin = v.begin(); it_begin != it_end; it_begin++)
	{
		std::cout << *it_begin << std::endl;
	}
	std::cout << std::endl;

	//[3]使用STL提供的遍历算法  格式：for_each(起始迭代器,结束迭代器,任意函数);  这里需要自定义任意类型的函数接收遍历完的数据
	std::for_each(v.begin(), v.end(), my_print);  //注意: 普通函数写函数名，仿函数才加()
}
int main()
{
	test01();
	system("pause");
	return 0;
}