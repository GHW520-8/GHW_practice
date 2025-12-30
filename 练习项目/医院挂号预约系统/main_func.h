#pragma once
#include<string>
#include<vector>
#include<array>
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

//获取名称的lambda表达式
namespace lam {
	//日期
	static auto day = [](const int& index) {
		std::array<std::string, 5> arr{ "一","二","三","四","五" };
		return arr[index - 1];
		};
	//时间段
	static auto office = [](const int& index) {
		std::array<std::string, 5> arr{ "外科","内科","儿科","妇产科","精神科" };
		return arr[index - 1];
		};
	//医生姓名
	static auto doc_name = [](const int& index) {
		return mfc::v_doctor_name[index];
		};
	//状态
	static auto status = [](const int& index) {
		std::array<std::string, 4> arr{ "预约失败","审核中","已预约","预约已取消" };
		return arr[index];
		};
}

