#pragma once			//防止头文件重复包含
#include<iostream>
#include"Point.h"
class Circle {			//圆类
public:
	//设置半径
	void set_r(int r); //{ C_r = r; }
	//设置圆心   注意：这里是对象成员，参考结构体嵌套   引用：Point &cneter=center
	void set_center(Point& center); //{ C_center = center; }
	//获得半径
	int get_r(); //{ return C_r; }
	//获得圆心  
	Point get_center(); //{ return C_center; }//在类中可以让另一个类作为本类的成员
private:
	int C_r;
	Point C_center;
};
