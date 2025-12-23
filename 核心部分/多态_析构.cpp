#include<iostream>
#include<string>
class Animal						//虚析构函数和虚函数写法一致，只需要加上"virtual"
{									//而纯虚析构函数不光要写声明，也必须要类外实现，记得作用域
public:								//一个类里虚析构和纯虚析构只能存在一个，只要存在纯虚析构函数这个类就叫抽象类
	Animal()						//它们的存在主要是为了解决父类指针释放子类对象的问题
	{								//因为原本的子类的析构函数是调用不到的，只有使用虚析构函数创造接口后才可以 
		std::cout << "Animal的构造函数调用" << std::endl;
	}
	void virtual speak() = 0;

	/*virtual  ~Animal()			//虚析构函数
	{
		std::cout << "Animal的析构函数调用" << std::endl;
	}*/
	virtual  ~Animal() = 0;			//纯虚析构函数的声明
};

Animal::~Animal()					//纯虚析构函数的实现
{
	std::cout << "Animal的析构函数调用" << std::endl;
}
class Cat :public Animal
{
public:
	Cat(std::string name)			//创建一个有参构造函数给成员变量赋值
	{
		c_name = new std::string(name);	//开辟堆区
		std::cout << "Cat的构造函数调用" << std::endl;
	}
	virtual void speak()
	{
		std::cout <<*c_name<< "猫在说话" << std::endl;
	}
	~Cat()
	{								
		if (c_name != NULL)			//使用析构函数释放堆区内存，这里释放的是“m_name”
		{
			std::cout << "Cat的析构函数调用" << std::endl;
			delete c_name;
			c_name = NULL;
		}
	}
	std::string* c_name;
};
void do_speak(Animal* animal)		//两种写法都可，本质上都是向上强制转换：Animal* animal=new Cat("Tom")
{
	animal->speak();
	delete animal;
}
void test01()
{
	/*Animal* animal = new Cat("Tom");
	animal->speak();
	delete animal;*/
	do_speak(new Cat("Tom"));
}
int main()
{
	test01();
	system("pause");
	return 0;
}