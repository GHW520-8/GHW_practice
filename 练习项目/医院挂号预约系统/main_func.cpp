#include"main_func.h"

namespace mfc {
	//临时容器存储文件数据  公用容器
	std::vector<temp_storage> temp_vec;
	//临时存储科室信息   公用容器
	std::vector<doctor_office> v_doof;
	//临时存储医生姓名
	std::vector<std::string> v_doctor_name;

//退出系统
	void exit_system() {
		std::cout << "欢迎下次使用 >_< " << std::endl;
		system("pause");
		exit(0);
	}

//显示主菜单
	void show_main_menu() {
		std::cout << "\t+";
		for (int i = 0; i < 15; i++) std::cout << " -";
		std::cout << " +" << std::endl;
		std::cout << "\t|   欢迎使用医院挂号预约系统    | " << std::endl;
		std::cout << "\t+";
		for (int i = 0; i < 15; i++) std::cout << " -";
		std::cout << " +" << std::endl;
		std::cout << "\n请选择你的登录身份：" << std::endl << std::endl;
		for (int i = 0; i < 2; i++) {
			std::cout << '\t';
			for (int j = 0; j < 27; j++) {
				std::cout << "=";
			}
			std::cout << std::endl;
		}
	std::cout << "\t[ [\t[1] 患 者\t] ]" << std::endl;
	std::cout << "\t[ [\t[2] 医 生\t] ]" << std::endl;
	std::cout << "\t[ [\t[3] 管 理 员\t] ]" << std::endl;
	std::cout << "\t[ [\t[0] 退出系统\t] ]" << std::endl;
	std::cout << "        ===========================" << std::endl;
	std::cout << "       =============================" << std::endl;
}

//验证登录
	bool verify(const std::vector<temp_storage>& vec, const input_info& input){
		//遍历容器比较
		for (const auto& user : vec) {
			//存储结果
			bool is_win = (user.file_user_name == input.input_name && user.union_id == input.input_id && user.file_password == input.input_password);
			//相同则继续
			if (is_win) {
				//为了实现多态
				identity* person = nullptr;
				switch (input.select) {
					//利用多态分别初始化
				case 1:
					std::cout << "患者验证登录成功!!!" << std::endl;
					person = new patient(input.input_name, input.input_id, input.input_password);
					break;
				case 2:
					std::cout << "医生验证登录成功!!!" << std::endl;
					person = new doctor(input.input_name, input.input_id, input.input_password);
					break;
				case 3:
					std::cout << "管理员验证登录成功!!!" << std::endl;
					person = new administrator(input.input_name, input.input_id, input.input_password);
					break;
				}
				if (person != nullptr) {
					system("pause");
					system("cls");
					std::cout << "即将进入菜单..." << std::endl;
					std::cout << "请稍作等待..." << std::endl << std::endl;
					system("pause");
					system("cls");
					//登录成功后应进入对应角色的菜单再 delete
					person->control_menu();
					delete person;
					return true;
				}
			}
		}
		//失败返回假
		return false;
	}

//登录主函数
	void log_in(const std::string& file_name, int type) {
		//每次登录前清空，避免重复累加
		temp_vec.clear();
		//创建文件流对象并打开文件
		std::ifstream ifs(file_name, std::ios::in);
		if (!ifs.is_open()) {
			std::cout << "文件不存在！" << std::endl; 
			ifs.close();
			return;
		} 
		//使用类来封装简化代码
		temp_storage tse;    //先将记录读取到容器里
		while (ifs >> tse.file_user_name >> tse.union_id >> tse.file_password) {
			temp_vec.emplace_back(tse);
		}
		ifs.close();

		//测试代码
		//for (const auto& t : temp_vec) std::cout << "加载: " << t.union_id << ' ' << t.file_user_name << ' ' << t.file_password << std::endl;

		//封装的输入类，来存储用户输入的信息
		input_info input;
		input.select = type;
		//存储验证结果
		bool log_in_ok = false;
		//外层循环控制持续输入，直到主动跳出
		while (true) {
			std::cout << "请输入用户名：" << std::endl;
			std::cin >> input.input_name;

			switch (type) {
				//患者
			case 1:
				std::cout << "请输入你的手机号：" << std::endl;
				std::cin >> input.input_id;
				
				std::cout << "请输入你的密码：" << std::endl;
				std::cin >> input.input_password;
				{ patient pat(input.input_name, input.input_id, input.input_password); }
				//检测登录
				log_in_ok = verify(temp_vec, input);
				break;
				//医生
			case 2:
				std::cout << "请输入你的工号：" << std::endl;
				std::cin >> input.input_id;

				std::cout << "请输入员工密码：" << std::endl;
				std::cin >> input.input_password;
				//检测登录
				log_in_ok = verify(temp_vec, input);
				break;
				//管理员
			case 3:
				std::cout << "请输入管理员账号：" << std::endl;
				std::cin >> input.input_id;

				std::cout << "请输入管理员密码：" << std::endl;
				std::cin >> input.input_password;
				//检测登录
				log_in_ok = verify(temp_vec, input);
				break;
			}
			//失败处理
			if (!log_in_ok) {
				std::cout << "验证登录失败 -_-" << std::endl;
				std::cout << "是否重新输入？\n" << std::endl;
				std::cout << "输入[0]返回上级菜单   按任意键重新输入\n" << std::endl;
				//外层循环的结束条件
				bool is_quit = false;
				while (true) {
					if (_kbhit()) { //判断是否按下键位
						int key = _getch();		//按下键位后会产生相应的返回值
						if (key == 0 || key == 0xE0) {//功能键和方向键会返回0或0xE0
							system("pause");
							system("cls");
							continue;
						}
						//只有为 0 才能返回菜单
						if (key == '0') { 
							is_quit = true;
							break; 
						}
						//其他字符
						else { break; }
					}
				}
				if (is_quit) {
					// 返回上级菜单：退出登录循环
					break;
				}
				else {
					// 清空输入缓存区，忽略当行所有记录，直到'\n'，防止陷入死循环
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					system("pause");
					system("cls");
					continue;
				}
			}
			//成功登录直接跳出
			else {
				break;
			}
		}
		system("pause");
		system("cls");
	}

//获取医生姓名
	void get_doctor_name() {
		mfc::v_doctor_name.clear();
		//将医生姓名单独读取出来
		mfc::input_info temp;
		
		std::ifstream doc_ifs(file_config::DOCT_FILE, std::ios::in);
		if (!doc_ifs.is_open()) {
			std::cout << "文件打开失败..." << std::endl;
			return;
		}
		while (doc_ifs >> temp.input_name >> temp.input_id >> temp.input_password) {
			v_doctor_name.emplace_back(temp.input_name);
		}
		doc_ifs.close();
	}

//清理工作
	void clear_info() {

	}
}

