#include<iostream>
#include<string>						//2025.12.20 这是最后一个项目  涉及得很广 正在完善...
#include"main_func.h"
#include"global_file.h"
int main()
{
	//用户的选项
	int select = 0;
	while (true) {
		//调用主菜单函数
		mfc::show_main_menu();
		select = 0;
		std::cin >> select;
		switch (select) {
			//退出系统
		case 0:
			mfc::exit_system();
			return 0;
			break;
			//患者
		case 1:
			mfc::log_in(file_config::PATI_FILE, select);
			break;
			//医生
		case 2:
			mfc::log_in(file_config::DOCT_FILE, select);
			break;
			//管理员
		case 3:
			mfc::log_in(file_config::ADMI_FILE, select);
			break;
		default:
			std::cout << "输入有误，请重新选择!!!" << std::endl;
			system("pause");
			system("cls");
		}
	}
}