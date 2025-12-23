#include<iostream>									//vector容器的容量和大小
#include<vector>									//vector容器的插入和删除
//打印输出											//vector容器的存取
void print_vector(std::vector<int>& v)
{
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

//vector容器的容量和大小
void test01()
{
	std::cout << "容量和大小：" << std::endl;
	std::vector<int>v;
	//为空返回 true(1) ，不为空返回 false(0)
	bool bl = v.empty();
	std::cout << bl << std::endl;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	print_vector(v);
	//容量是大于或等于大小的
	std::cout << "容器的容量为：" << v.capacity() << std::endl;
	std::cout << "容器的大小为：" << v.size() << std::endl;

	//使用resize()函数可重新指定容器的大小，如果比原长度小，自动删除多余的 如果大，则使用默认值 0 补全
	v.resize(5);
	print_vector(v);
	/*v.resize(15);
	print_vector(v);*/

	//resize()函数的重载版本，可以将默认值换为用户指定的数
	v.resize(15, 6);
	print_vector(v);
}

//vector容器的插入和删除
void test02()
{
	std::cout << std::endl<< "插入：" << std::endl;
	std::vector<int> v;
	//最常见的push_back()函数，这里就不多说了
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i*2-1);
	}
	std::cout << "原数据：" << std::endl;
	print_vector(v);

	//我们可以使用intsert(迭代器，元素)  重载版本，可以多次插入相同的数据 insert(const_iterator，int count,ele)
	//v.insert(v.begin() + 3,666);
	
	//注意：插入并不是将原数据删除后插入，而是将原数据向后移
	v.insert(v.begin()+3, 3,666);
	print_vector(v);

	std::cout << std::endl << "删除：" << std::endl;

	std::cout << "删除后：" << std::endl;
	//pop_back() 删除最后一个元素
	v.pop_back();
	print_vector(v);

	//erase(迭代器，元素)  重载版本，可以删除指定区间内的所有元素 erase(const_iterator start，const_iterator end)
	//v.erase(v.begin()+2);
	v.erase(v.begin()+3, v.begin()+6);
	print_vector(v);

	//清空容器里所有的数据
	v.clear();
	if (v.empty()==1) { std::cout << "数据为空" << std::endl; }
	else { std::cout << "数据不为空" << std::endl; }
}

//vector容器的存取
void test03()
{
	std::cout << std::endl << "存取：" << std::endl;
	std::vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back( (i+1) * 3 );
	}
	//这里的[]和at()函数和string容器基本一致 就不实例了
	print_vector(v);
	//获取第一个元素
	std::cout << "第一个元素：" << v.front() << std::endl;
	//获取最后一个元素
	std::cout << "最后一个元素：" << v.back() << std::endl;

}
int main()
{
	test01();
	test02();
	test03();
	system("pause");
	return 0;
}