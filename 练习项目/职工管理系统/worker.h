#pragma once
#include<iostream>
#include<string>
class worker			//基类：职工抽象类
{
public:
	
	// 显示职工信息（纯虚）
	virtual void show_info() = 0;
	// 获取岗位名称（纯虚）
	virtual std::string get_postname() = 0;
	// 虚析构函数，防止通过基类指针删除派生类时未定义行为
	// C++11的默认方式
	virtual ~worker() = default;
	// 职工编号
	int m_id;
	// 职工姓名
	std::string m_name;
	// 部门编号/岗位代号
	int m_deptid;
};