#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include"identity.h" 
#include"global_file.h"
#include"manage_massage.h"
// 不在头文件中包含 main_func.h / patient.h / doctor.h，以避免循环包含
#include"doctor_office.h"

// 前向声明，避免在头文件中引入循环依赖
class patient;
class doctor;

class administrator : public identity {   //管理员派生类
public:
	//默认构造函数
	administrator();

	//有参构造函数
	administrator(std::string admi_name, std::string id,std::string password);

	//显示管理员菜单
	void show_admi_menu();

	//管理员控制菜单
	virtual void control_menu();

	//初始化成员容器
	void init_member();

	//检测重复
	bool check_repeat(std::string id, int type);

	//添加账号
	void add_person();

	//查看账号信息
	void show_person();

	//管理科室信息
	void manage_massage();

	//清空预约记录
	void clean_file();

	//医生工号
	std::string administrator_num;

	//临时存储患者信息
	std::vector<patient> v_pat;

	//临时存储医生信息
	std::vector<doctor> v_doc;

	//判断信息是否存在
	bool pat_is_exist;
	bool doc_is_exist;
};