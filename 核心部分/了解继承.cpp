#include<iostream>
#include<string>
//基类，提供公有接口
class animal {
public:
	//初始化
	animal(std::string name):m_name(name){}
	void eat() {
		std::cout << this->m_name << "在吃饭" << std::endl;
	}
	void sleep() {
		std::cout << this->m_name << "在睡觉" << std::endl;
	}
	std::string m_name;
};
//派生类cat
class cat : public animal {
public:
	//构造函数不能继承
	//初始化列表创建匿名对象传参
	cat(std::string c_name) : animal(c_name){}
	//添加独有的特性
	void meow() {
		std::cout << "喵~喵喵~" << std::endl;
	}
};
//派生类dog
class dog : public animal {
public:
	dog(std::string d_name) : animal(d_name) {}
	//修改继承的成员函数
	void eat() {
		std::cout << this->m_name << "在啃骨头" << std::endl;
	}
};
void test() {
	cat c_cat("汤姆");
	c_cat.meow();
	c_cat.sleep();
	
	dog m_dog("哈巴狗");
	m_dog.eat();

}
int main() {
	test();
	return 0;
}