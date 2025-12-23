#include<iostream>
#include"doctor.h"
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
	std::cout << "\t[ [\t[2] 开 始 接 诊     ] ]" << std::endl;
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
		default:
			std::cout << "输入有误，请重新选择!!!" << std::endl;
			system("pause");
			system("cls");
		}
	}

}

//查看科室挂号队列
void doctor::show_all_order() {

}

//开始就诊
void doctor::start_diagnose() {

}
