#include<iostream>			
class person {
public:				//拷贝 > 有参 > 无参，定义了高一级的构造函数，系统就不会存在低级的构造函数
	person() 
	{ 
		std::cout << "peroson的默认构造函数" << std::endl; 
	}
	person(int p,int high)
	{
		m_age = p;
		m_high = new int(high);
		std::cout << "person的有参构造函数" << std::endl;
	}
	person(const person& p)	
	{
		m_age = p.m_age;		//只要使用了拷贝构造，不管写不写函数，系统都会拷贝 ( 有参没有 )
		std::cout << "person的拷贝构造函数" << std::endl;
	}

	person(const person &p) 
	{									//如果开辟了堆区，一定要自己写拷贝构造函数，否则浅拷贝会报错
		std::cout << "person的拷贝构造函数" << std::endl;
		m_age = p.m_age;
		m_high = new int (*p.m_high);	//使用了深拷贝，相当于给新对象开辟了块堆区内存，这样就不会发生重复释放、同步修改...		
	}

	//一定要手动释放分配的内存，否则会导致内存泄漏
	~person() {
		if (m_high != NULL) {//如果值不为空就清理
			delete m_high;
		}
		//为了防止野指针的情况，最好再将值置空
		m_high = NULL;
		std::cout << "person的析构函数" << std::endl;
	}
	int m_age;
	int* m_high;
};
//[1]使用创建好的对象来初始化
void test0()
{
	person p1(10,169);
	person p2(p1);
	std::cout << "p1= " << p1.m_age << std::endl;
	std::cout << "p2= " << p2.m_age << std::endl ;
}
//[2]值传递
void t_k(person p_0)		//值传递的过程相当于拷贝了一份数据给他  相当于 person p_0=p;
{
	std::cout << "p=" << p_0.m_age << std::endl;
}
void test1()
{
	std::cout << std::endl;
	person p(10,166);
	t_k(p);
}
//[3]值方式返回局部对象
person t_w()
{
	person p1;				//声明一个对象，局部用完就释放，所以会出现析构
	std::cout << (int*)&p1 << std::endl;
	return person(p1);		//注意这里返回的不是值本身，而是拷贝了一份返回
}
void test2()
{
	std::cout << std::endl;
	person p = t_w();		
	std::cout << (int*)&p << std::endl;
}
void test3()
{
	std::cout << std::endl;
	person p1(14, 170);
	person p2(p1);
	std::cout << "p1.age= " << p1.m_age << "p1.high= " << *p1.m_high<<std::endl;
	std::cout << "p2.age= " << p2.m_age << "p2.high= " << *p2.m_high<<std::endl;
}
int main()
{
	test0();
	test1();
	test2();
	//test3();
	system("pause");
	return 0;
}