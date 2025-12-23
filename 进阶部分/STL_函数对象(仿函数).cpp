#include<iostream>										//函数对象(仿函数)
#include<string>			//函数对象就是一个类的对象 因为内部重载了调用运算符 使对象使用重载的()时行为类似函数 所以也叫仿函数
							//他可以有自己的状态 普通类有的他都有 一样可以继承 多态 还可以将函数对象作为参数传递
class my_test {
public:
	my_test():count(0){}
	//实现加法的()重载
	int operator()(int num1, int num2) const
	{
		return num1 + num2;
	}

	//实现字符串打印的()重载
	void operator()(std::string str)
	{
		std::cout << str << std::endl;
		count++;
	}
	//仿函数的内部可以定义自己的状态 也就是成员变量 构造函数 其他成员函数等
	//能够灵活的实现 因为它本质上是一个类 拥有正常类的所有功能
	int count;
};
//声明函数
void do_print(my_test& t, std::string str);
void test01()
{
	my_test test;
	//这里就相当于 test.operator()(11,21)
	std::cout << test(11, 21) << std::endl;

	//这里相当于 test.operator().("Hello world")
	test("Hello world");
	test("Hello world");
	test("Hello world");
	test("Hello world");
	test("Hello world");
	std::cout << "执行次数：" << test.count << std::endl;
	
	//函数对象可以作为参数传递
	do_print(test,"Hello C嘎嘎");

}
void do_print(my_test& t, std::string str)
{
	//全局函数里还可以用函数对象去调用 重载的调用运算符
	//t.operator()(test)
	t(str);
}
int main()
{
	test01();
	system("pause");
	return 0;
}