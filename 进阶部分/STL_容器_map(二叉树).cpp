#include<iostream>							//map/multimap容器 他们中所有的元素都是pair(对组)
#include<map>					//pair第一个元素为key(键)起索引作用  第二个元素为value(值)   他们插入时会自动排序(升序)
								//他们都是关联式容器map key不允许重复 multimap可以  底层都是红黑树
								//根据 key 可以快速找到 value  key的类型可以是任意可以比较的
//打印输出
void print_map(std::map<int,int>& m)
{
	for (std::map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		std::cout << (*it).first << '\t'<<(*it).second<<std::endl;
	}
	std::cout << std::endl;
}
//map容器的构造函数与赋值
void test01()
{
	//默认构造
	std::map<int, int> m1;
	//普通插入 因为是对组所以必须声明
	m1.insert(std::pair < int, int>(2, 40));
	m1.insert(std::pair < int, int>(4, 40));
	m1.insert(std::pair < int, int>(3, 50));
	m1.insert(std::pair < int, int>(1, 40));

	//c++11标准的新插入方法(推荐)
	m1.emplace(2, 20);
	m1.emplace(4, 40);
	m1.emplace(3, 50);
	m1.emplace(1, 40);
	print_map(m1);

	//拷贝构造
	std::map<int, int> m2(m1);
	print_map(m2);

	//"="赋值
	std::map<int, int> m3=m2;
	print_map(m3);

}

//map的大小与交换
void test02()
{
	std::map<int, int> m1;
	m1.emplace(2, 20);
	m1.emplace(4, 30);
	m1.emplace(3, 50);
	m1.emplace(1, 40);
	print_map(m1);

	//判断是否空和返回大小
	if (m1.empty())
	{
		std::cout << "容器为空" << std::endl;
	}
	else {
		std::cout << "容器不为空" << std::endl;
		std::cout << "大小为：" << m1.size() << std::endl;
	}

	//交换容器  初始化列表
	std::map<int, int> m2{ {3,66},{4,55},{2,22},{1,33} };
	m2.swap(m1);
	std::cout << "交换后m1：" << std::endl;
	print_map(m1);
	std::cout << "交换后m2：" << std::endl;
	print_map(m2);
}
int main()
{
	test01();
	/*test02();*/
	system("pause");
	return 0;
}