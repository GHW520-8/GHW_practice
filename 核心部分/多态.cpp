#include<iostream>	//实现动态多态，需要定义一个虚函数，提供公有接口
//基类
class Animal {		//实现运行时绑定，也就是"晚绑定"
public:
	virtual void speak() {
		std::cout << "动物在说话 " << std::endl;
	}
};
//派生类 Cat
class Cat : public Animal {
	virtual void speak() { //注意重写需要 类型 函数名 形参等全部一致才可以
		std::cout << "小猫在说话 " << std::endl;
	}
};
//派生类 Dog
class Dog : public Animal {
	void speak() { //子类可以不用写 virtual关键字,其仍是虚函数
		std::cout << "小狗在说话 " << std::endl;
	}
};									
void do_speak(Animal& animal) { //这里相当于：Animal& animal = cat/dog 做了向上类型转换
	animal.speak();				//同时也可以写成：Animal* animal = &cat/&dog
}								//父类的指针或者引用指向子类的对象 (向上类型转换) 也是实现动态多态的条件之一
void test01() {
	Cat cat;					
	do_speak(cat);				
}
void test02() {		//运行时系统就会根据实参类型来判断调用哪个类的虚函数
	Dog dog;	
	do_speak(dog);
}
int main() {
	test01();
	test02();
	return 0;
}