#include<iostream>
#include<string>
class person {
public:
	person(std::string name) :m_name(name){}
	//"=="关系运行算符重载
	bool operator==(const person &p) const {
		if (this->m_name == p.m_name) {
			return true;
		}
		return false;
	}
	//"!="关系运算符重载
	bool operator!=(const person &p) const {
		if (this->m_name == p.m_name) {
			return false;
		}
		return true;
	}
	std::string m_name;
};
void test01() {
	person p1("小亮");
	person p2("小亮");
	if (p1==p2) { //本质：p1.operator==(p2)
		std::cout << "p1==p2" << std::endl;
	}
	else {
		std::cout << "p1!=p2" << std::endl;
	}
}
void test02() {
	person p1("小亮");
	person p2("小光");
	if (p1!=p2) { //本质：p1.operator!=(p2)
		std::cout << "p1!=p2" << std::endl;
	}
	else {
		std::cout << "p1==p2" << std::endl;
	}
}
int main() {
	test01();
	test02();
	return 0;
}