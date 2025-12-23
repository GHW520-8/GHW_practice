#include<iostream>							//成员函数做友元
#include<string>							
class Building;			
class GoodGay
{
public:
	GoodGay();			
public:
	void visit();			//可以访问
	void visit2();			//不可以访问
	Building* building;	
};

class Building
{
	friend void GoodGay::visit();	//其他类成员函数的友元，此时可以访问私有权限的内容
public:
	Building();
public:
	std::string m_sittingroom;
private:
	std::string m_bedroom;
};

Building::Building()	
{
	m_sittingroom = "客厅";
	m_bedroom = "卧室";
}
GoodGay::GoodGay()
{						//开辟一个堆区存放Building对象，保证代码的健壮性
	building = new Building;
}
void GoodGay::visit()	//可以正常访问
{
	std::cout << "visit 好基友正在访问你的：" << building->m_sittingroom << std::endl;
	std::cout << "visit 好基友正在访问你的：" << building->m_bedroom << std::endl;
}
void GoodGay::visit2()	//他不能访问，因为没有做友元
{
	std::cout << "visit2 好基友正在访问你的：" << building->m_sittingroom << std::endl;
	//std::cout << "visit2 好基友正在访问你的：" << building->m_bedroom << std::endl;
}
void test()
{
	GoodGay gy;			//定义好基友类的对象
	gy.visit();			//调用访问函数
	gy.visit2();
}
int main(void)
{
	test();
	system("pause");
	return 0;
}