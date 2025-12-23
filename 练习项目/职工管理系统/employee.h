#pragma once
#include<iostream>
#include"worker.h"
class employee :public worker				//普通职工类，输出普通职工的信息
{
public:
	//使用构造函数给成员变量赋值
	employee(int id, std::string name, int deptid);

	//重写显示函数和岗位名称函数
	virtual void show_info();

	virtual std::string get_postname();
};