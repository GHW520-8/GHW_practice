#include<iostream>			
//立方体类
class cube {
public:

	void set_l(double lon) { m_l = lon; }//设置长

	void set_w(double wide) { m_w = wide; }//设置宽

	void set_h(double high) { m_h = high; }//设置高
	//长宽高设为了 private，利用成员函数返回
	double get_l() { return m_l; }//获得长

	double get_w() { return m_w; }//获得宽

	double get_h() { return m_h; }//获得高
	//计算面积返回
	double print_area() {
		return 2 * (m_l * m_w + m_l * m_h + m_w * m_h);
	}
	//计算体积返回
	double print_volume() {
		return m_l * m_w * m_h;
	}
	//成员函数可以类内访问私有权限
	//只需要将传递对象对比
	bool issame_class(cube& c)
	{
		//长宽高相等返回 真
		if (c.get_l() == m_l && c.get_w() == m_w && c.get_h() == m_h) {
			return true;
		}
		else {	//否则为 假
			return false;
		}
	}
	//定义长宽高，设为私有权限
private:
	double m_l;
	double m_w;
	double m_h;
};
//定义全局函数判断是否相等
//这里使用了引用传递，其实就是创建别名
bool isSame(cube& c1, cube& c2)
{
	//将两个对象的长宽高做对比
	if (c1.get_l() == c2.get_l() && c1.get_w() == c2.get_w() && c1.get_h() == c2.get_h()) {
		return true;
	}
	else {
		return false;
	}
}
int main()
{
	//创建第一个立方体类对象
	cube c1;
	//设置长宽高
	c1.set_l(10);
	c1.set_w(11);
	c1.set_h(10);
	std::cout << "面积为：" << c1.print_area() << std::endl;
	std::cout << "体积为：" << c1.print_volume() << std::endl;

	//创建第二个立方体类对象
	cube c2;
	//设置长宽高
	c2.set_l(11);
	c2.set_w(11);
	c2.set_h(10);
	bool ret = isSame(c1, c2);
	std::cout << "全局函数判断：";
	if (ret)
	{
		std::cout << "两个立方体相等" << std::endl;
	}
	else
	{
		std::cout << "两个立方体不相等" << std::endl;
	}

	//使用成员函数判断
	//注意这里调用的是c1，那么对比就需要把c2传入成员函数
	ret = c1.issame_class(c2);		
	std::cout << "成员函数判断：";
	if (ret)
	{
		std::cout << "两个立方体相等" << std::endl;
	}
	else
	{
		std::cout << "两个立方体不相等" << std::endl;
	}
	return 0;
}