#pragma once
#include<iostream>
#include"identity.h" //医生派生类
class doctor : public identity {
public:
	//默认构造
	doctor();

	//有参构造赋值
	doctor(std::string name, std::string emp_id, std::string password);

	//显示医生菜单
	void show_doc_menu();

	//医生控制菜单
	virtual void control_menu();

	//查看科室挂号队列
	void show_all_order();

	//开始就诊
	void start_diagnose();

	//工号
	std::string employee_num;
};