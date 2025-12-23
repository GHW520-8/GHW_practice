#pragma once
#include<iostream>
class Point {		//点类
public:
	//设置横坐标
	void set_x(int x);// { P_x = x; }
	//设置纵坐标
	void set_y(int y);// { P_y = y; }
	//获得横坐标
	int get_x();// { return P_x; }
	//获得纵坐标
	int get_y();// { return P_y; }
private:
	int P_x;
	int P_y;
};
