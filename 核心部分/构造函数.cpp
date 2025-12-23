#include<iostream>			//构造函数：按类型分为普通构造函数和拷贝构造函数
class person {
	public:			//普通构造函数：通过参数来看可分为两类，无参构造函数(默认构造函数),有参构造函数
		//默认构造函数
		person() { std::cout << "person的默认构造函数" << std::endl; }

		//有参构造函数
		person(int p) 
		{ 
			m_age = p;
			std::cout << "person的有参构造函数" << std::endl; 
		}

		//拷贝构造函数
		person(const person &p)//拷贝构造函数会将所有属性(成员变量)拷贝，方法(成员函数)是共享的，不属于单个对象，不需要拷贝
		{ 
			m_age = p.m_age;  //将传入的信息拷贝到另一个变量
			std::cout << "person的拷贝构造函数" << std::endl; 
		}

		//析构函数：对象销毁前自动调用，执行一些清理工作
		~person() { std::cout << "person的析构函数" << std::endl; }

		int m_age;
};
void test0()
{
	////调用构造函数的方式：[1]括号法
	//person p1();  //注意这种写法是错误的，默认函数不能加括号，否则系统会认为是声明了一个函数		
	//person p1;		//默认构造函数调用
	//person p2(11);	//有参构造函数调用
	//person p3(p2);	//拷贝构造函数调用
	//std::cout << "p2= " << p2.m_age << std::endl;
	//std::cout << "p3= " << p3.m_age << std::endl;

	//[2]显示法
	/*person p1 = person();
	person p2 = person(12);
	person p3 = person(p2);
	std::cout << "p2= " << p2.m_age << std::endl;
	std::cout << "p3= " << p3.m_age << std::endl;*/

	person (10);	//匿名对象,当行执行完后，系统会立即回收匿名对象
	person{ 20 };
	person p3(11);
	//person (p3);  不要使用拷贝构造函数初始化匿名对象，
	//否则编译器认为这是一个对象声明，等同于person p3;
	//但是可以使用列表初始化
	person{ p3 };
	std::cout<<"------------------"<<std::endl;

	//[3]隐式转换法
	//person p4 = 10;		//等同于 person p4 = person(10);
	//person p5 = p4;		//等同于 person p5 = person(p4)

}
int main() 
{
	test0();
	return 0;
}