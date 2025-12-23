#include<iostream>
class Animal {
public:
	virtual ~Animal() = 0;
};
Animal::~Animal() {
	std::cout << "基类的析构函数调用" << std::endl;
}

class Cat : public Animal {
public:
	 ~Cat() { //派生类可以不写关键字 virtual
		std::cout << "派生类的析构函数调用" << std::endl; 
	}
};
void delete_animal(Animal* animal) {
	delete animal;
}
void test01() {
	delete_animal(new Cat);
}
int main() {
	test01();
	return 0;
}