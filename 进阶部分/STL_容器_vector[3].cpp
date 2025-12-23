#include<iostream>											//vector的构造函数和赋值操作
#include<vector>

//打印输出
void print_vector(std::vector<int>& v) //因为要打印容器里的数据 所以需要定义一个容器来接收
{
	//定义一个迭代器读取容器里的数据
	for (std::vector<int>::iterator it = v.begin(); it!= v.end(); it++)
	{
		std::cout << *it << ' ';
	}
}
//构造
void test01()
{
	std::cout << "构造函数：" << std::endl;
	std::vector<int> v1; //默认构造
	//初始化
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	print_vector(v1);
	std::cout << std::endl;

	//使用区间的方式构造
		        //注意：begin()开始的值可以取到 但是end() 结束的值取不到，只会取到他前一个的值， 因为end()返回的是最后元素的后一位
	std::vector<int> v2(v1.begin(),v1.end());
	print_vector(v1);
	std::cout << std::endl;

	//使用n个elem的方式构造          原型：--vector(n,elem) 将n个elem拷贝给自身
	std::vector<int> v3(10, 99);

	print_vector(v3);
	std::cout << std::endl;

	//使用普通的拷贝构造函数
	std::vector<int> v4(v3);

	print_vector(v4);
	std::cout << std::endl;
}

//赋值
void tets02()
{
	std::cout << std::endl<< "赋值操作：" << std::endl;
	std::vector<int> v1; //默认构造
	//初始化
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i*2-1);
	}
	//赋值操作 operato=
	std::vector<int> v2;
	v2 = v1;
	print_vector(v2);
	std::cout << std::endl;

	//使用区间的方式赋值 assign()函数
	std::vector<int> v3;

	v3.assign(v1.begin(), v1.end());
	print_vector(v3);
	std::cout << std::endl;

	//使用n个elem
	std::vector<int> v4;

	v4.assign(6,666);				//   原型：assign(n, elem) 将n个elem赋值给自身
	print_vector(v4);
	std::cout << std::endl;

}
int main()
{
	test01();
	tets02();
	system("pause");
	return 0;
}