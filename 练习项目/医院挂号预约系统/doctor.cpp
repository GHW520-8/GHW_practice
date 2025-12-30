#include<iostream>
#include"doctor.h"
#include"order_file.h"
#include"main_func.h"
//默认构造
doctor::doctor() {

}

//有参构造赋值
doctor::doctor(std::string name, std::string emp_id, std::string password) {
	this->user_name = name;
	this->employee_num = emp_id;
	this->user_password = password;
}

//显示医生菜单
void doctor::show_doc_menu() {
	std::cout << "\t+";
	for (int i = 0; i < 15; i++) std::cout << " -";
	std::cout << " +" << std::endl;
	std::cout << "\t|   尊敬的医生您好，注意休息噢  | " << std::endl;
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
	std::cout << "\t[ [\t[1] 挂 号 情 况     ] ]" << std::endl;
	std::cout << "\t[ [\t                    ] ]" << std::endl;
	std::cout << "\t[ [\t[2] 审 核 预 约     ] ]" << std::endl;
	std::cout << "\t[ [\t                    ] ]" << std::endl;
	std::cout << "\t[ [\t[0] 注 销 登 录     ] ]" << std::endl;

	std::cout << "        ===============================" << std::endl;
	std::cout << "       =================================" << std::endl;
}

//医生控制菜单
void doctor::control_menu() {
	
	//新选择来咯
	int doc_select;
	while (true) {
		//显示患者菜单
		this->show_doc_menu();
		doc_select = 0;
		std::cin >> doc_select;
		switch (doc_select) {
			//注销登录
		case 0:
			std::cout << "成功注销登录" << std::endl << std::endl;
			std::cout << "出去走走吧，外面世界很美的ヾ(≧▽≦*)o" << std::endl << std::endl;
			return;
			break;
		case 1:
			this->show_all_order();
			break;
		case 2:
			this->vaild_order();
			break;
		default:
			std::cout << "输入有误，请重新选择!!!" << std::endl;
			system("pause");
			system("cls");
		}
	}
	system("pause");
	system("cls");
}

//查看科室挂号队列
void doctor::show_all_order() {
	order_file d_or;
	if (d_or.order_size == 0) {
		std::cout << "记录不存在..." << std::endl;
		system("pause");
		system("cls");
		return;
	}
	//更新医生姓名
	mfc::get_doctor_name();

	//标题
	std::cout << "\t\t\t    挂 号 队 列\n" << std::endl;
	std::cout << "预约日期\t" << "时间段\t\t" << "科室\t\t" << "医生\t\t" << "状态\n" << std::endl;
	for (int i = 0; i < d_or.order_size; i++) {
		//预约日期
		std::cout << "星期" << lam::day(stoi(d_or.m_save[i]["date"])) << "\t\t";
		//预约时间段
		std::cout << (d_or.m_save[i]["intraval"] == "1" ? "上午" : "下午") << "\t\t";
		//科室
		std::cout << lam::office(stoi(d_or.m_save[i]["office_num"])) << "\t\t";
		//预约医生
		std::cout << lam::doc_name(stoi(d_or.m_save[i]["select_doctor"])) << "\t\t";
		//预约状态
		std::cout << lam::status(stoi(d_or.m_save[i]["status"])) << std::endl << std::endl;
	}
	system("pause");
	system("cls");
}

//审核预约
void doctor::vaild_order() {
	order_file d_or;
	if (d_or.order_size == 0) {
		std::cout << "没有预约记录噢" << std::endl;
		system("pause");
		system("cls");
		return;
	}
	//更新医生姓名
	mfc::get_doctor_name();
	using namespace lam;

	std::cout << "    预约日期\t\t" << "时间段\t\t" << "科室\t\t" << "医生\t\t" << "状态\n" << std::endl;
	for (int i = 0, j = 1; i < d_or.order_size; i++) {
		if (d_or.m_save[i]["status"] == "1") {
			//预约日期
			std::cout << "[" << j << "] " << "星期" << day(stoi(d_or.m_save[i]["date"])) << "\t\t";
			//预约时间段
			std::cout << (d_or.m_save[i]["intraval"] == "1" ? "上午" : "下午") << "\t\t";
			//科室
			std::cout << office(stoi(d_or.m_save[i]["office_num"])) << "\t\t";
			//预约医生
			std::cout << doc_name(stoi(d_or.m_save[i]["select_doctor"])) << "\t\t";
			//电话
			std::cout << d_or.m_save[i]["phone_number"] << "\t\t";
			//预约状态
			std::cout << status(stoi(d_or.m_save[i]["status"])) << std::endl << std::endl;
			j++;
		}
		else {
			std::cout << "没有预约需要审核...\n" << std::endl;
			system("pause");
			system("cls");
			return;
		}
	}
	std::cout << "请选择预约记录：" << std::endl;
	while (true) {
		int select_0 = 0;
		std::cin >> select_0;
		if (select_0 >= 0 && select_0 <= d_or.order_size) {
			break;
		}
		else {
			std::cout << "不能超出范围！！！" << std::endl;
		}
	}
		std::cout << "请审核预约: [1] 通过 [2] 拒绝 [0] 返回\n" << std::endl;
		int select_1 = 0;
		while (true) {
			std::cin >> select_1;
			if (select_1 >= 0 && select_1 <= d_or.order_size) {
				if (select_1 == 0) {
					break;
				}
				else if (select_1 == 1) {
					d_or.m_save[select_1 - 1]["status"] = "2";
					d_or.update_order();
					std::cout << "该审核通过...\n" << std::endl;
					break;
				}
				else if (select_1 == 2) {
					d_or.m_save[select_1 - 1]["status"] = "0";
					d_or.update_order();
					std::cout << "该审核不通过...\n" << std::endl;
					break;
				}
			}
			std::cout << "输入错误！！！" << std::endl;
		}
	system("pause");
	system("cls");
}