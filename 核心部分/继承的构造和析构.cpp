#include<iostream>
class dad {
public:
	dad() {
		std::cout << "基类的构造函数调用" << std::endl;
	}
	~dad() {
		std::cout << "基类的析构函数调用" << std::endl;
	}
};
class son : public dad {
public:
	son() {
		std::cout << "派生类的构造函数调用" << std::endl;
	}
	~son() {
		std::cout << "派生类的析构函数调用" << std::endl;
	}
};
void test() {
	//dad d;
	son s;
}
int main() {
	test();
	return 0;
}