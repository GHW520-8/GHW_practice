#pragma once
#include<iostream>
#include"worker.h"
class boss :public worker							//总裁类，输出总裁的信息
{
public:
	//使用构造函数给成员变量赋值
	boss(int id, std::string name, int deptid);

	//重写显示函数和岗位名称函数
	virtual void show_info();

	virtual std::string get_postname();
};