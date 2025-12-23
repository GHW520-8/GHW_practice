#include<iostream>   //使用虚函数实现多态,使代码可读性，清晰性高，有利于后期扩展和维护
class abs_calculater {
public:
	virtual int get_result() {
			return 0;
	}
	int m_num1;
	int m_num2;
};
//加法计算器
class add_calculater :public abs_calculater {
public:
	int get_result() {
		return m_num1 + m_num2;			
	}
};
//减法计算器
class sub_calculater :public abs_calculater {
public:
	int get_result() {
		return m_num1 - m_num2;
	}
};
//乘法计算器
class mul_calculater :public abs_calculater {
public:
	int get_result() {
		return m_num1 * m_num2;
	}
};
//除法计算器
class div_calculater :public abs_calculater {
public:
	int get_result() {
		return m_num1 / m_num2;
	}
};
void test01() {
	abs_calculater* abs = new add_calculater;	//因为堆区里的数据需要定义指针来接收，
	abs->m_num1 = 100;							//所以这里也就相当于基类的指针指向派生类的对象
	abs->m_num2 = 100;							//new 类名 就相当于在堆区里创建了一个派生类的对象
	std::cout << "加法实现：" << std::endl;
	std::cout << abs->m_num1 << " + "<< abs->m_num2<<" = "<<abs->get_result() << std::endl;
	delete abs;									//堆区里的数据一定要记得手动释放，否则会造成内存泄露

	abs = new sub_calculater;					//因为创建过父类的对象，所以在堆区释放后可以接着开辟
	abs->m_num1 = 100;
	abs->m_num2 = 20;
	std::cout <<std::endl<< "减法实现：" << std::endl;
	std::cout << abs->m_num1 << " - " << abs->m_num2 << " = " << abs->get_result() << std::endl;
	delete abs;

	abs = new mul_calculater;
	abs->m_num1 = 10;
	abs->m_num2 = 20;
	std::cout << std::endl << "乘法实现：" << std::endl;
	std::cout << abs->m_num1 << " * " << abs->m_num2 << " = " << abs->get_result() << std::endl;
	delete abs;

	abs = new div_calculater;
	abs->m_num1 = 100;
	abs->m_num2 = 10;
	std::cout << std::endl << "除法实现：" << std::endl;
	std::cout << abs->m_num1 << " / " << abs->m_num2 << " = " << abs->get_result() << std::endl;
	delete abs;
}
int main() {
	test01();
	return 0;
}