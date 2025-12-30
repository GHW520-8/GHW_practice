#pragma once
#include<string>
#include<vector>
#include"doctor_office.h"
// 不在头文件中包含 main_func.h / patient.h / doctor.h，以避免循环包含
// 管理科室头：保留必需 STL 头，避免依赖 missing common.h

class administrator;
namespace man {
	class manage_massage {
	public:
		//构造函数初始化
		manage_massage();

		//初始化科室容器
		void init_office();

		//显示科室管理菜单
		void show_massage_menu();

		//添加科室信息
		void add_massage();

		//检测科室是否存在
		std::vector<doctor_office>::iterator is_exist(const std::string& off_id);

		//删除科室信息
		void delete_massage();

		//显示科室信息
		void show_massage();

		//更新科室文件
		void update_doof();

		//修改科室信息
		void modifi_massage();
	
		//科室排序
		void my_sort();

		//清空科室信息
		void clear_office();

		//判断文件是否存在
		bool is_empty;

		//科室总数
		int doof_size;

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

