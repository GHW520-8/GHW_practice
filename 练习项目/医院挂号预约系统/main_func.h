#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<conio.h> //控制台交互非标准头文件 主要实现键盘的交互
#include<limits>  //清空缓存区代码需包含此头文件					
#include"identity.h"
#include"patient.h"
#include"doctor.h"
#include"administrator.h"
#include"global_file.h"
#include"doctor_office.h"
//使用命名空间...
namespace mfc {
	class temp_storage;
	class input_info;

//退出系统
	void exit_system();

//显示主菜单
	void show_main_menu();

//验证登录
	bool verify(const std::vector<temp_storage>& vec, const input_info& input);

//登录主函数
	void log_in(const std::string& file_name, int type);

//命名空间内嵌套类
	class temp_storage {
	public:
		std::string union_id;
		std::string file_user_name;
		std::string file_password;
	};

//存储输入的信息
	class input_info {
	public:
		std::string input_id;
		std::string input_name;
		std::string input_password;
		int select = 0;
	};

//获取医生姓名
	void get_doctor_name();

//清理工作
	void clear_info();

//临时容器存储文件数据
	extern std::vector<temp_storage> temp_vec;

//临时存储科室信息
	extern std::vector<doctor_office> v_doof;

//临时存储医生姓名
	extern std::vector<std::string> v_doctor_name;
}
