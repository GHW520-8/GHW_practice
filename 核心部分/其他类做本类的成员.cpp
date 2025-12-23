#include<iostream>
#include<string>
class phone {
public:
	phone(std::string m_name) : m_pName(m_name)		//初始化列表，加":"写在形参后，可以直接给类内成员变量赋值
	{
		std::cout << "phone的构造函数调用" << std::endl;
	}

	~phone() { std::cout << "phone的析构函数调用" << std::endl; }
	std::string m_pName;
};

class person {
public:
	person(std::string person_name, std::string phone_name):p_name(person_name), m_phone(phone_name)
	{
		std::cout << "person的构造函数调用" << std::endl;
	}
	

	~person(){ std::cout << "person的析构函数调用" << std::endl; }
	std::string p_name;
	phone m_phone;		//当其他类的对象成为本类的成员时，先调用其他类的构造函数,析构时相反
};
						
void test0()
{
	person p1("小光", "16promax");
	std::cout << "p1.name= " << p1.p_name << "  p1.phone= " << p1.m_phone.m_pName << std::endl;
}

int main()
{
	test0();
	system("pause");
	return 0;
}