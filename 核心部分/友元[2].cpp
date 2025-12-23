#include<iostream>							//类做友元
#include<string>							//类外实现成员函数或析构函数初始化
class Building;			//先声明Building类，让系统认识一下，防止出错
class GoodGay 
{
public:		
	GoodGay();			//可以类内声明，类外实现
public:
	void visit();		//定义一个访问函数，后续访问building的属性
	Building* building;	//将Building类作为本类的成员，并定义为指针类型
};

class Building
{
	friend class GoodGay;//类做友元的声明方式
public:
	Building();
public:
	std::string m_sittingroom;
private:
	std::string m_bedroom;
};

Building::Building()	//使用默认构造函数进行赋值,注意类外初始化成员函数的方法 "类名::"
{
	m_sittingroom = "客厅";
	m_bedroom = "卧室";
}
GoodGay::GoodGay()
{						//开辟一个堆区存放Building对象，保证代码的健壮性
	building = new Building;
}
void GoodGay::visit()	//输出结果
{
	std::cout << "好基友正在访问你的：" << building->m_sittingroom << std::endl;
	std::cout << "好基友正在访问你的：" << building->m_bedroom << std::endl;
}
void test()				
{
	GoodGay gy;			//定义好基友类的对象
	gy.visit();			//调用访问函数
}
int main(void)
{
	test();
	system("pause");
	return 0;
}