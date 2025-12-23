#pragma once
#include<iostream>
#include<vector>
#include<array>
#include"identity.h"  
#include"main_func.h"
#include"order_file.h"
class patient : public identity{  //患者派生类
public:
	//默认构造函数
	patient();

	//有参构造函数赋值
	patient(std::string name, std::string p_num, std::string password);

	//显示患者菜单
	void show_pat_menu();

	//患者控制菜单
	virtual void control_menu();

	//预约挂号
	void apply_order();

	//挂号详情
	void public_show();
	
	//查看挂号详情
	void show_Myorder();

	//取消预约
	void cancel_order();

	//电话号码
	std::string phone_num;
};