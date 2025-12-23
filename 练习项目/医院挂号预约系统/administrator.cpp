#include<iostream>
#include"administrator.h"
#include"patient.h"
#include"doctor.h"
#include"main_func.h"
//默认构造函数
administrator::administrator() {}

//有参构造函数
administrator::administrator(std::string admi_name, std::string id, std::string password) {
	this->user_name = admi_name;
	this->administrator_num = id;
	this->user_password = password;
	//初始化成员容器
	this->init_member();
	//初始化判断变量
	this->pat_is_exist = false;
	this->doc_is_exist = false;
}

//显示管理员菜单
void administrator::show_admi_menu() {
	std::cout << "\t+";
	for (int i = 0; i < 15; i++) std::cout << " -";
	std::cout << " +" << std::endl;
	std::cout << "\t|   你好，管理员小登(￣(工)￣)  | " << std::endl;
	std::cout << "\t+";
	for (int i = 0; i < 15; i++) std::cout << " -";
	std::cout << " +" << std::endl;
	std::cout << "\n请输入选择：" << std::endl << std::endl;
	for (int i = 0; i < 2; i++) {
		std::cout << '\t';
		for (int j = 0; j < 31; j++) {
			std::cout << "=";
		}
		std::cout << std::endl;
	}
	std::cout << "\t[ [\t[1] 添 加 账 号     ] ]" << std::endl;
	std::cout << "\t[ [\t                    ] ]" << std::endl;
	std::cout << "\t[ [\t[2] 查 看 账 号     ] ]" << std::endl;
	std::cout << "\t[ [\t                    ] ]" << std::endl;
	std::cout << "\t[ [\t[3] 管 理 科 室     ] ]" << std::endl;
	std::cout << "\t[ [\t                    ] ]" << std::endl;
	std::cout << "\t[ [\t[4] 清 空 预 约     ] ]" << std::endl;
	std::cout << "\t[ [\t                    ] ]" << std::endl;
	std::cout << "\t[ [\t[0] 注 销 登 录     ] ]" << std::endl;
	std::cout << "        ===============================" << std::endl;
	std::cout << "       =================================" << std::endl;
}

//管理员控制菜单
void administrator::control_menu() {
	//新选择来咯
	int admi_select;
	while (true) {
		//显示管理员菜单
		this->show_admi_menu();
		admi_select = 0;
		std::cin >> admi_select;
		switch (admi_select) {
			//注销登录
		case 0:
			std::cout << "成功注销登录" << std::endl << std::endl;
			std::cout << "慢走不送￣へ￣" << std::endl << std::endl;
			return;
			break;
			//添加账号
		case 1:
			this->add_person();
			break;
			//查看账号
		case 2:
			this->show_person();
			break;
			//管理科室
		case 3:
			this->manage_massage();
			break;
			//清空预约
		case 4:
			this->clean_file();
			break;
		default:
			std::cout << "输入有误，请重新选择!!!" << std::endl;
			system("pause");
			system("cls");
		}
	}
}

//初始化成员容器
void administrator::init_member() {
	//先清空容器，防止重复
	v_pat.clear();
	v_doc.clear();
	std::ifstream pat_ifs(file_config::PATI_FILE, std::ios::in);
	if (!pat_ifs.is_open()) {
		std::cout << "文件打开失败..." << std::endl;
		return;
	}
	//读取到成员变量里
	patient pat;
	while (pat_ifs >> pat.user_name >> pat.phone_num >> pat.user_password) {
		//将对象放入容器
		v_pat.emplace_back(pat);
	}
	pat_ifs.close();

	//类似操作
	std::ifstream doc_ifs(file_config::DOCT_FILE, std::ios::in);
	if (!doc_ifs.is_open()) {
		std::cout << "文件打开失败..." << std::endl;
		return;
	}
	doctor doc;
	while (doc_ifs >> doc.user_name >> doc.employee_num >> doc.user_password) {
		v_doc.emplace_back(doc);
	}
	doc_ifs.close();
}

//检测重复
bool administrator::check_repeat(std::string id, int type) {
	//根据电话号码/工号判断是否重复
	switch (type) {
		//患者
	case 0:
		//遍历容器
		for (const auto& pat_it : v_pat) {
			if (id == pat_it.phone_num) {
				return true;
			}
		}
		return false;
		//医生
	case 1:
		for (const auto& doc_it : v_doc) {
			if (id == doc_it.employee_num) {
				return true;
			}
		}
		return false;
	default:
		return false;
	}
}

//添加账号
void administrator::add_person() {
	std::cout << "请选择添加账号类型" << std::endl;
	std::cout << "[0] 患者账号     [1] 医生账号" << std::endl;
	//用户选项
	int choice = 0;
	std::cin >> choice;
	//根据选项判断应使用的文件
	std::string file_name;
	choice ? file_name = file_config::DOCT_FILE : file_name = file_config::PATI_FILE;
	//追加方式写入
	std::ofstream ofs(file_name, std::ios::out | std::ios::app);
	if (!ofs.is_open()) {
		std::cout << "文件打开失败..." << std::endl;
		return;
	}
	//使用公用的输入类成员
	mfc::input_info input;
	//错误信息
	std::string error_info = "重复了，重新输入吧(￣_,￣ )";
	//用于获取检测重复函数的返回值
	bool ret = false;
	switch (choice) {
	case 0:
		while (true) {
			std::cout << "请输入患者的姓名：" << std::endl;
			std::cin >> input.input_name;

			std::cout << "请输入患者的联系电话：" << std::endl;
			std::cin >> input.input_id;

			std::cout << "请输入患者的账号密码：" << std::endl;
			std::cin >> input.input_password;
			//检测是否重复
			ret = this->check_repeat(input.input_id, choice);
			if (ret) {
				//重复显示错误信息继续输入
				std::cout << error_info << std::endl;
				system("pause");
				system("cls");
			}
			else {
				//更新判断变量
				this->pat_is_exist = false;
				break;
			}
		}
		break;
	case 1:
		while (true) {
			std::cout << "请输入医生的姓名：" << std::endl;
			std::cin >> input.input_name;

			std::cout << "请输入医生的工号：" << std::endl;
			std::cin >> input.input_id;

			std::cout << "请输入医生的账号密码：" << std::endl;
			std::cin >> input.input_password;
			//检测是否重复
			ret = this->check_repeat(input.input_id, choice);
			if (ret) {
				//重复显示错误信息继续输入
				std::cout << error_info << std::endl;
				system("pause");
				system("cls");
			}
			else {
				//更新判断变量
				this->doc_is_exist = false;
				break;
			}
		}
		break;
	}
	//最后再将数据写入文件
	ofs << input.input_name << " " << input.input_id << " " << input.input_password << " " << std::endl;
	std::cout << "添加成功(～￣▽￣)～" << std::endl;
	ofs.close();
	//及时更新容器里的数据
	this->init_member();
	system("pause");
	system("cls");
}

//查看账号信息
void administrator::show_person() {
	
	std::cout << "请选择查看的内容：" << std::endl;
	std::cout << "[1] 查看所有患者" << std::endl;
	std::cout << "[2] 查看所有医生" << std::endl;
	//用户选项
	int choice = 0;
	std::cin >> choice;
	switch (choice) {
		//患者
	case 1:
		if (this->pat_is_exist) {
			std::cout << "患者账号信息为空..." << std::endl;
			break;
		}
		std::cout << "以下是所有患者的信息：\n" << std::endl;
		std::cout << "姓名\t" << "电话号码\t" << "密码" << std::endl;
		//使用遍历算法并使用lambda表达式简化书写
		std::for_each(v_pat.begin(), v_pat.end(), [](const patient& pat) {
			std::cout << pat.user_name << "\t" << pat.phone_num << "\t" << pat.user_password << std::endl;
			});
		break;
		//医生
	case 2:
		if (this->doc_is_exist) {
			std::cout << "医生账号信息为空..." << std::endl;
			break;
		}
		std::cout << "以下是所有医生的信息：\n" << std::endl;
		std::cout << "姓名\t" << "工号\t" << "密码" << std::endl;
		//使用遍历算法并使用lambda表达式简化书写
		std::for_each(v_doc.begin(), v_doc.end(), [](const doctor& doc) {
			std::cout << doc.user_name << "\t" << doc.employee_num << "\t" << doc.user_password << std::endl;
			});
		break;
	}
	system("pause");
	system("cls");
}

//管理科室信息
void administrator::manage_massage() {
	system("cls");
	std::cout << "即将进入子菜单...\n" << std::endl;
	std::cout << "再等一小会噢o((>ω< ))o...\n" << std::endl;
	system("pause");
	system("cls");

	//用户选择
	int select = 0;
	//创建对象调用
	man::manage_massage manage;
	while (true) {
		//显示菜单
		manage.show_massage_menu();
		std::cin >> select;
		switch (select) {
			//返回上级菜单
		case 0:
			std::cout << "\n即将返回上级菜单..." << std::endl << std::endl;
			std::cout << "慢走不送 ┑(￣Д ￣)┍..." << std::endl << std::endl;
			system("pause");
			system("cls");
			return;
			//添加科室信息
		case 1:
			manage.add_massage();
			break;
			//删除科室信息
		case 2:
			manage.delete_massage();
			break;
			//显示科室信息
		case 3:
			manage.show_massage();
			break;
			//修改科室信息
		case 4:
			manage.modifi_massage();
			break;
		default:
			std::cout << "输入有误，请重新选择!!!" << std::endl;
			system("pause");
			system("cls");
		}
	}
}

//清空预约记录
void administrator::clean_file() {
	std::ofstream ord_ofs(file_config::ORDER_FILE, std::ios::trunc);
	ord_ofs.close();
	std::cout << "清空成功" << std::endl;
	system("pause");
	system("cls");
}
