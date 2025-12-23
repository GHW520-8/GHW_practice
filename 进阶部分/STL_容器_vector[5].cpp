#include<iostream>									//vector互换容器
#include<vector>									//vector预留空间
//互换容器的具体用处(收缩内存)
void test01()
{
	std::vector<int> v;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
	}
	std::cout << "容量：" << v.capacity() << std::endl;
	std::cout << "大小：" << v.size() << std::endl;

	std::cout << "未收缩：" << std::endl;
	//如果容器里的数据过多，并且重新指定了大小，那么多余的内存会浪费
	v.resize(3);
	std::cout << "容量：" << v.capacity() << std::endl;
	std::cout << "大小：" << v.size() << std::endl;

	std::cout << "swap()收缩后：" << std::endl;
	//我们可以使用匿名对象进行容器互换解决内存浪费的问题
	std::vector<int>(v).swap(v); //这里相当于创建了匿名对象，调用了拷贝构造函数拷贝数据，然后与原容器互换
	//因为匿名对象用完就释放，系统就自动释放了原内存
	std::cout << "容量：" << v.capacity() << std::endl;
	std::cout << "大小：" << v.size() << std::endl;
}

void test02()
{
	std::vector<int> v;
	//记录扩展次数
	int num = 0;
	//因为vector容器的成员函数没有重载！=，所以定义一个指针判断
	int* p = NULL;
	//如果我们使用reserve()函数预留了空间，那么就不用多次扩展内存了
	v.reserve(100000);
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
		//如果不指向首地址，那么内存就扩展了，因为扩展后会更新指向
		if (p != &v[0])
		{
			p = &v[0];
			num++;
		}
	}
	//输出扩展次数
	std::cout << "扩展次数："<< num << std::endl;
}
int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}