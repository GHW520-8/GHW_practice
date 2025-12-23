#pragma once
#include<iostream>
#include<string>			//抽象身份类，成为基类提供接口
class identity {
public:
	//操作菜单界面
	virtual void control_menu() = 0;
	//用户名
	std::string user_name;
	//用户密码
	std::string user_password;
	//虚析构函数
	virtual ~identity() = default;
};