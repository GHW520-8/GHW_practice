#include<iostream>					//全局函数做友元
#include<string>
class building
{
	friend void goodgay(building* m_building);//在函数声明前加"friend" 就做了友元，此时就能访问私有权限里面的内容
public:
	building()						//定义默认构造函数给成员变量赋值
	{
		sittingroom = "客厅";
		bedroom = "卧室";
	}
public:
	std::string sittingroom;
private:
	std::string bedroom;
};

void goodgay(building* m_building)	//定义goodgay函数接收对象并进行输出
{
	std::cout << "好基友正在访问你的：" <<m_building->sittingroom<< std::endl;
	std::cout << "好基友正在访问你的：" <<m_building->bedroom<<std::endl;
}
void test()
{
	building m_building;	//定义一个对象并将地址传给goodgay函数
	goodgay(&m_building);
}
int main()
{
	test();
	system("pause");
	return 0;
}