#include<iostream>//设计一个圆形(Circle)类和点(Point)类,计算点和圆的关系
#include"Point.h"
#include"Circle.h"
/*class Point {		//点类
public:
	//设置横坐标
	void set_x(int x) { P_x = x; }
	//设置纵坐标
	void set_y(int y) { P_y = y; }
	//获得横坐标
	int get_x() { return P_x; }
	//获得纵坐标
	int get_y() { return P_y; }
private:
	int P_x;
	int P_y;
};

class Circle {			//圆类
public:
	//设置半径
	void set_r(int r) { C_r = r; }
	//设置圆心   注意：这里是对象成员，参考结构体嵌套   引用：Point &cneter=center
	void set_center(Point& center) { C_center = center; }
	//获得半径
	int get_r() { return C_r; }
	//获得圆心  
	Point get_center() { return C_center; }//在类中可以让另一个类作为本类的成员
private:
	int C_r;
	Point C_center;
};*/

//定义一个全局函数判断位置关系
void ralation(Circle &c1,Point &p1) 
{
	//计算半径
	int s_r = c1.get_r() * c1.get_r();
	//计算点到圆心的距离		注意对象成员的调用
	int s_p=(p1.get_x() - c1.get_center().get_x()) * (p1.get_x() - c1.get_center().get_x()) +
			(p1.get_y() - c1.get_center().get_y()) * (p1.get_y() - c1.get_center().get_y());
	if (s_p == s_r)
	{
		std::cout << "这个点在圆上" << std::endl;
	}
	else if (s_p < s_r)
	{
		std::cout << "这个点在圆内" << std::endl;
	}
	else 
		std::cout << "这个点在圆外" << std::endl;
}
int main() 
{
	//创建圆
	Circle c1;
	c1.set_r(5);
	Point center;
	center.set_x(0);
	center.set_y(0);
	c1.set_center(center);

	//创建点
	Point p1;
	p1.set_x(0);
	p1.set_y(5);

	//判断位置关系
	ralation(c1, p1);
	return 0;
}