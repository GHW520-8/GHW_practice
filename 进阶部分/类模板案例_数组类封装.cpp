#include<iostream>
#include<string>
#include"数组类模板的分文件.hpp"
//打印输出
void print_array(my_array<int> &arr)  //调用时传入的是对象
{
	for (int i = 0; i < arr.get_size(); i++)
	{
		std::cout << arr[i] << std::endl;
	}
}
void test01()
{
	//先向数组里存入五个元素,使用尾插法
	my_array<int>arr1(5);
	for (int i = 0; i < arr1.get_capacity(); i++)
	{
		arr1.push_back(i);		//调用尾插函数存入数据
	}
	std::cout << "arr1: " << std::endl;
	print_array(arr1);
	//输出容量
	std::cout << "capacity: " << arr1.get_capacity() << std::endl;
	//输出大小
	std::cout << "size: " << arr1.get_size() << std::endl;

	std::cout << std::endl<< "arr2: " << std::endl ;
	//调用拷贝构造函数
	my_array<int>arr2(arr1);
	print_array(arr1);

	//尾删
	arr2.pop_back();
	//输出容量
	std::cout << "尾删后："<<std::endl;
	std::cout << "capacity: " << arr2.get_capacity() << std::endl;
	//输出大小
	std::cout << "size: " << arr2.get_size() << std::endl;

	/*my_array<int> arr3(100); //测试赋值运算符重载
	arr3 = arr1;*/
}

//测试自定义类型
class person
{
public:
	person(){}		//默认构造函数空实现，因为使用了有参构造函数，系统不会自动调用
	person(std::string name,int age):m_name(name),m_age(age){}
	std::string m_name;
	int m_age;
};

//打印输出             这里是定义了一个my_array类的对象arr，因为my_array是类模板，所以显式指定了person类类型
void print_personArray(my_array<person>& arr)
{
	//打印输出姓名年龄
	std::cout << std::endl << "姓名\t" << "年龄" << std::endl;
	for (int i = 0; i < arr.get_size(); i++)
	{
		std::cout << arr[i].m_name << '\t' << arr[i].m_age << std::endl;
	}
}

void test02()
{
	//指定容量为10
	my_array<person> arr(10); //因为有五个对象，每个对象有两个数据，所以开辟10个内存空间存储
	//创建person 类的对象并初始化
	person p1("小李", 14);
	person p2("小光", 13);
	person p3("小亮", 15);
	person p4("小王", 16);
	person p5("小周", 18);
	
	//将数据存入数组
	arr.push_back(p1);
	arr.push_back(p2);
	arr.push_back(p3);
	arr.push_back(p4);
	arr.push_back(p5);

	//打印数组
	print_personArray(arr);
	//输出容量
	std::cout << "capacity: " << arr.get_capacity() << std::endl;
	//输出大小
	std::cout << "size: " << arr.get_size() << std::endl;
}

int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}