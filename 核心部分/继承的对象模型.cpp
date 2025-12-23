#include<iostream>
class dad {
public:
	int m_a;
protected:
	int m_b;
private:
	int m_c;
};
class son : public dad {
public:
	int m_d;
};
void test01() {
	son s;
	std::cout << sizeof(s) << std::endl;
}
int main() {
	test01();
	return 0;
}