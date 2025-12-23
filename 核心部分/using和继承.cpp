#include<iostream>
class dad {
public:
	int m_a;
protected:
	int m_b;
private:
	int m_c;
};
class son : protected dad {
public:
	using dad::m_b;
protected:
	using dad::m_a;
public:
	//using dad::m_c;
};
void test01() {
	son s;
	//s.m_a = 10;
	s.m_b = 10;
	//s.m_c = 10;
}
int main() {
	test01();
	return 0;
}