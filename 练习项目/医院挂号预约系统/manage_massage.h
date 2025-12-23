#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<conio.h> //控制台交互非标准头文件 主要实现键盘的交互
#include<limits>  //清空缓存区代码需包含此头文件					
#include"identity.h" 
#include"global_file.h"
#include"main_func.h"
// 不在头文件中包含 main_func.h / patient.h / doctor.h，以避免循环包含
#include"doctor_office.h"
class administrator;
namespace man {
	class manage_massage {
	public:
		////默认构造函数
		//manage_massage();

		//构造函数初始化
		manage_massage();

		//初始化科室容器
		void init_office();

		//显示科室管理菜单
		void show_massage_menu();

		//添加科室信息
		void add_massage();

		//检测科室是否存在
		doctor_office is_exist(const std::string& off_id);

		//重载bool运算符实现判断
		//explicit operator bool() const;

		//重载==运算符做判断
		//bool operator==(const doctor_office& other) const;

		//删除科室信息
		void delete_massage();

		//显示科室信息
		void show_massage();

		//修改科室信息
		void modifi_massage();
	
		//清空科室信息
		void clear_office();

		//判断文件是否存在
		bool is_empty;

		static const doctor_office EMPTY_DOCTOR_OFFICE;

		//挂号费用
		//外科
		static const std::string IM ;
		//内科
		static const std::string SG;
		//儿科
		static const std::string PD;
		//妇产科
		static const std::string GO;
		//精神科
		static const std::string PS;
	};
	const doctor_office EMPTY_DOCTOR_OFFICE{ 0,{"","",0,""} };
	//外科
	const std::string IM = "17_元";
	//内科
	const std::string SG = "15_元";
	//儿科
	const std::string PD = "19_元";
	//妇产科
	const std::string GO = "20_元";
	//精神科
	const std::string PS = "22_元";
}

