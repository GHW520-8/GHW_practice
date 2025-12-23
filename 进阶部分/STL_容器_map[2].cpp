#include<iostream>							  //map容器的插入 删除 查找 计数
#include<map>

//打印输出
void print_map(std::map<int, int>& m)
{
	for (const auto& it : m)
	{
		std::cout << it.first << ' ' << it.second << std::endl;
	}
	std::cout << std::endl;
}

//插入和删除
void test01()
{
	//插入
	std::map<int, int> m1;
	//[1]insert()插入 因为是对组所以必须声明
	m1.insert(std::pair < int, int>(2, 40));

	//[2]insert(make_pair()) 插入
	m1.insert(std::make_pair(4, 40));

	//[3]insert(std::map<type1,type2>::value_type())插入 (不推荐)
	m1.insert(std::map< int, int>::value_type(3, 50));

	//[4]利用"[]"重载插入
	m1[1] = 40;

	//c++11标准的新插入方法(推荐)
	//他们都是模板方法 会自动推导参数类型 不需要声明对组类型
	m1.emplace(5, 40);
	//这里第一个参数是提示位置迭代器 第二和第三个参数是键和值 因为会自动排序，所以在哪插入都一样
	m1.emplace_hint(m1.begin()++, 6,20);
	std::cout << "原数据：" << std::endl << std::endl;
	print_map(m1);

	//删除  
	//map的删除和其他容器的接口基本一致
	std::cout << "删除后数据：" << std::endl;
	auto it = m1.begin();
	//删除第二个位置元素 并返回下一个元素的迭代器
	it = m1.erase(++it);
	print_map(m1);
	std::cout << "返回迭代器："<< (*it).first << ' ' << (*it).second << std::endl;

	//删除指定区间的元素 返回下一个元素的迭代器
	it = m1.erase(++++m1.begin(),m1.end());
	print_map(m1);
	//因为删除后下一个元素没有了 会返回end()迭代器 所以会报错
	//std::cout << "返回迭代器：" << (*it).first << ' ' << (*it).second << std::endl;

	//删除指定key值的元素 无返回
	m1.erase(3);
	print_map(m1);

	//清空
	m1.clear();
	print_map(m1);
}

//查找和统计
void test02()
{
	std::map<int,int> m1{ {1,10},{2,20},{3,30} };
	auto pos = m1.find(2);
	//查找 find(key) 找到返回元素的迭代器 没找到返回end()
	if (pos != m1.end())
	{
		std::cout << "找到了，key是：" << (*pos).first << " value是："<< (*pos).second << std::endl;
	}
	else {
		std::cout << "没找到" << std::endl;
	}

	//计数 count(key) 因为map容器不会有重复值 所以他的返回结果只有 0或1 multimap可以重复 正常返回
	std::cout << m1.count(1) << std::endl;
}
int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}