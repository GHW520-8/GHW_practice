#include<iostream>
class animal { //变为虚基类
public:
	int m_age;
};
//虚继承
class sheep : virtual public animal {};
class tuo : virtual public animal {};
//最终派生类
class sheep_tuo : public sheep, public tuo {};
void test01() {
	sheep_tuo st;
	st.sheep::m_age = 10;
	st.tuo::m_age = 12;
	std::cout << "sheep的m_age = " << st.sheep::m_age << std::endl;
	std::cout << "tuo的m_age = " << st.tuo::m_age << std::endl;
	std::cout << "sheep_tuo的m_age = " << st.m_age << std::endl;
}
int main() {
	test01();
	return 0;
}