#include<iostream>
class person {
	friend std::ostream& operator<<(std::ostream& my_cout, const person& p);
public:
	person(int age) {
		m_age = new int(age); //在堆区开辟一块内存
	}
	//赋值运算符重载,使用const 可以防止意外修改源对象
	person& operator=(const person& p) {
		//防止自赋值，检查this指向地址和形参地址是否相同
		if (this == &p) {
			//相同则直接返回
			return *this;
		}
	    //为了防止重复释放，需要先判断堆区里的数据是否已经释放
		if (m_age != nullptr) {
			delete m_age;
			m_age = nullptr;
		}
		//深拷贝解决浅拷贝问题 注意：*(p.m_age)
		m_age = new int(*p.m_age);	
		return *this; //返回对象本身的数据
	}
	//手动释放
	~person() {
		if (m_age != nullptr) {
			delete m_age;
			m_age = nullptr;
		}
	}
private:
	int* m_age;	//使用指针类型来接收堆区数据
};
std::ostream& operator<<(std::ostream& my_cout, const person& p) {
	my_cout << "m_age= " << *p.m_age;
	return my_cout;
}
void test01() {
	person p1(14);
	person p2(16);
	//p2.operator=(p1);
	p2 = p1;	//对象之间本身不能使用=直接赋值，赋值运算符重载实现了...
	std::cout << "p1." << p1 << std::endl;
	std::cout << "p2." << p2 << std::endl;
	person p3(12);
	//p1.operator=(p2.operator=(p3));
	p1 = p2 = p3;
	std::cout << "p1." << p1 << std::endl;
	std::cout << "p2." << p2 << std::endl;
	std::cout << "p3." << p3 << std::endl;
}
int main() {
	test01();
	return 0;
}