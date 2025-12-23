#include<iostream>
//基类
class Animal {		//实现运行时绑定，也就是"晚绑定"
public:
	virtual void speak() {}
};
//派生类 Cat
class Cat : public Animal {
	virtual void speak() {}
};
//派生类 Dog
class Dog : public Animal {
	virtual void speak() {}
};
void do_speak(Animal& animal) {
	animal.speak();  //未定义虚函数前 1
	std::cout << "基类字节：" << sizeof(animal);
}
void test01() {
	Cat cat;
	Dog dog;
	do_speak(cat);
}
int main() {
	test01();
	return 0;
}
