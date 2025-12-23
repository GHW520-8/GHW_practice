#include<iostream>		//对组(pair)就是包含两个元素的数据结构  可以将两个值组合成一个单一对象，这两个值可以是不同的数据类型
#include<string>		//支持拷贝 赋值 比较等操作
#include<utility>  //pair对组的头文件 其实大多数头文件都包含了它 不过有可能不稳定 最好写显式出来
void test01()
{
	//pair对组的格式：pair<type,type> 变量名
	//第一种创建方式 相当于调用有参构造函数
	std::pair<int, int> num(10, 12);
	std::cout << num.first << '\t' << num.second << std::endl;

	//第二种创建方式  使用make_pair(值1，值2) 创建
	std::pair<std::string, int> p = std::make_pair("小亮", 14);
	std::cout << p.first << '\t' << p.second << std::endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}