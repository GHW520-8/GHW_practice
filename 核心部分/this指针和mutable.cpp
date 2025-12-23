#include<iostream>
class person {
public:
	person()
	{
		std::cout << "person的默认构造函数" << std::endl;
	}
	person(int age)
	{
		this->m_age = age;		//this指针可用于形参和成员变量重名时 
								//指向被调用成员函数所属的对象 这里也就是指向p1
	}
	person(const person& p)
	{
		std::cout << "person的拷贝构造函数" << std::endl;
	}
	person& add_age(person &p)	//这里函数使用的引用，目的是使返回值为一个引用，从而达到修改值
	{							//否则它会使用拷贝构造函数赋一个新值，返回的就不是它自身
		this->m_age += p.m_age;
		return *this;			//this指向的是被调用成员函数所属的对象，这里是p2
								//加上"*"也就是解引用，使this指针指向对象的本体,返回的就是p2，实现累加
	}

	void nullptr_0()			//可以发现空指针可以正常调用这个成员函数 因为他内部与空指针一点关系都没有哈哈哈哈
	{
		std::cout << "nullptr_0 " << std::endl;
	}
	void nullptr_1()			//这里就没有输出值，因为空指针无法访问成员变量的值
	{
		if (this == NULL)		//为了防止出错，可以增加一个判断
		{
			return;
		}
		std::cout << "nullptr_1->age: " <<this->m_age<< std::endl;
	}
	
	//常函数相当于使this指针的值也不可修改，也就是常量指针常量(const person * const this)
	void show_person()const		//常函数可以被任意对象调用
	{
		//this = NULL;			//this指针的指向不能被修改，因为this指针本质是一个指针常量(person * const this)
		//this->m_a = 15;		//常函数里的值不能被修改
		this->m_b = 16;			//特殊存在
	}
	int m_age;
	int m_a;
	mutable int m_b;			//使用mutable使这个成员变量成为一个特殊的存在，常函数和常对象都可以正常使用
};
//this指针第一种用法  区分成员变量和形参
void test0() 
{
	person p1(13);
	std::cout << "p1.age= " << p1.m_age << std::endl;
}
//this指针的第二种用法	在类的非静态成员函数返回对象本身 (return *this)
void test1()
{
	person p1(10);
	person p2(10);
	p2.add_age(p1).add_age(p1).add_age(p1).add_age(p1);	//链式编程思维
	std::cout << "p2.age= " << p2.m_age << std::endl;
}
//空指针与this指针
void test2() 
{
	person* p1=NULL;
	p1->nullptr_0();
	p1->nullptr_1();
}
//常函数和常对象以及"mutable"的作用
void test3()
{
	const person p1;		
	//p1.nullptr_0();		//常量对象只能调用常量函数
	p1.show_person();
	//p1.m_a = 18;			//它的值也不能修改
	p1.m_b = 18;			//使用mutable后的特殊存在
}
int main()
{
	test0();
	test1();
	test2();
	test3();
	system("pause");
	return 0;
}