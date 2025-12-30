#include<iostream>
#include<fstream>
#include<conio.h>
#include<algorithm>
#include"global_file.h"
#include"manage_massage.h"
#include"main_func.h"
namespace man {
	////默认构造函数
	//manage_massage::manage_massage() {
	// 
	//}

	manage_massage::manage_massage() {
		this->init_office();
		this->is_empty = false;
	}

//初始化科室容器
	void manage_massage::init_office() {
		//先清空公用科室容器
		mfc::v_doof.clear();
		std::ifstream doof_ifs(file_config::DOOF_FILE, std::ios::in);
		if (!doof_ifs.is_open()) {
			std::cout << "文件打开失败..." << std::endl;
			this->is_empty = true;
			return;
		}

		//读取到成员变量里再将对象放入公用容器
		doctor_office doof;
		while (doof_ifs >> doof.office_name >> doof.info.office_id >> doof.info.doctor_name >> doof.info.max_order >> doof.info.money) {
			mfc::v_doof.emplace_back(doof);
		}
		doof_ifs.close();
	}

//显示科室管理菜单
	void manage_massage::show_massage_menu() {
		for (int i = 0; i < 2; i++) {
			std::cout << '\t';
			for (int j = 0; j < 31; j++) {
				std::cout << "=";
			}
			std::cout << std::endl;
		}
		std::cout << "\t[ [  [1] 添 加 科 室 信 息  ] ]" << std::endl;
		std::cout << "\t[ [\t                    ] ]" << std::endl;
		std::cout << "\t[ [  [2] 删 除 科 室 信 息  ] ]" << std::endl;
		std::cout << "\t[ [\t                    ] ]" << std::endl;
		std::cout << "\t[ [  [3] 显 示 科 室 信 息  ] ]" << std::endl;
		std::cout << "\t[ [\t                    ] ]" << std::endl;
		std::cout << "\t[ [  [4] 修 改 科 室 信 息  ] ]" << std::endl;
		std::cout << "\t[ [\t                    ] ]" << std::endl;
		std::cout << "\t[ [  [5] 科 室 信 息 排 序  ] ]" << std::endl;
		std::cout << "\t[ [\t                    ] ]" << std::endl;
		std::cout << "\t[ [  [0] 返 回 上 级 菜 单  ] ]" << std::endl;
		std::cout << "        ===============================" << std::endl;
		std::cout << "       =================================\n" << std::endl;
		std::cout << "请输入选项：\n" << std::endl;
	}

//添加科室信息
	void manage_massage::add_massage() {
	
		doctor_office input;
		while (true) {
			std::cout << "请输入要添加的科室代号：\n" << std::endl;
			std::cout << "[1] 外科\t[2] 内科\t[3] 儿科 " << std::endl;
			std::cout << "[4] 妇产科\t[5] 精神科" << std::endl;
			std::cin >> input.office_name;
			if (input.office_name >= 1 && input.office_name <= 5) break;
			std::cout << "只能输入这几个!(*￣(￣　*)" << std::endl;
		}
		

		std::cout << "请输入科室编号：" << std::endl;
		std::cin >> input.info.office_id;

		int index = 0;
		mfc::get_doctor_name();
		while (true) {
			std::cout << "请选择医生：\n" << std::endl;
			int i = 0;
			for (const auto& temp_it : mfc::v_doctor_name) {
				std::cout << "[" << i << "] " << temp_it << std::endl;
				i++;
			}
			std::cin >> index;
			if (index >= 0 && index <= mfc::v_doctor_name.size() - 1) break;
			std::cout << "下次不要输错了!!!...( ＿ ＿)ノ｜" << std::endl;
			system("pause");
			system("cls");
		}
	
		input.info.doctor_name = mfc::v_doctor_name[index];
	
		std::cout << "请设置号源上限(不得超过20)" << std::endl;
		while (true) {
			std::cin >> input.info.max_order;
			if (input.info.max_order >= 0 && input.info.max_order <= 20) break;
			std::cout << "都说了不能超过!!!!!!" << std::endl;
		}
	
		std::ofstream doof_ofs(file_config::DOOF_FILE, std::ios::out | std::ios::app);
		if (!doof_ofs.is_open()) {
			std::cout << "文件打开失败..." << std::endl;
			this->is_empty = true;
			return;
		}

		doof_ofs << input.office_name << " " << input.info.office_id << " " << input.info.doctor_name << " " <<input.info.max_order<<" ";

		switch (input.office_name) {
			//外科
		case 1:
			doof_ofs << man::IM;
			break;
			//内科
		case 2:
			doof_ofs << man::SG;
			break;
			//儿科
		case 3:
			doof_ofs << man::PD;
			break;
			//妇产科
		case 4:
			doof_ofs << man::GO;
			break;
			//精神科
		case 5:
			doof_ofs << man::PS;
			break;
		}
		doof_ofs << std::endl;
		doof_ofs.close();
		std::cout << "祝贺你，终于添加完成了||ヽ(*￣▽￣*)ノミ|Ю\n" << std::endl;
		this->init_office();
		this->is_empty = false;
		system("pause");
		system("cls");
	}

//检测科室是否存在
	std::vector<doctor_office>::iterator manage_massage::is_exist(const std::string& off_id) {
		for (std::vector<doctor_office>::iterator is_it = mfc::v_doof.begin(); is_it != mfc::v_doof.end(); is_it++) {
			if ((*is_it).info.office_id == off_id) {
				return is_it;
			}
		}
		return mfc::v_doof.end();
	}

//删除科室信息
	void manage_massage::delete_massage() {
		std::cout << "请输入要删除的科室编号：\n" << std::endl;
		this->show_massage();
		std::string id;
		std::cin >> id;

		std::vector<doctor_office>::iterator ret = is_exist(id);
		if (ret == mfc::v_doof.end()) {
			std::cout << "科室不存在...回去重新看看？..." << std::endl;
		}
		else {
			mfc::v_doof.erase(ret);
			std::cout << "删除成功..." << std::endl;
			this->update_doof();
		}
		system("pause");
		system("cls");
	}

//显示科室信息
	void manage_massage::show_massage() {
		if (this->is_empty) {
			std::cout << "记录为空..." << std::endl;
			return;
		}
		std::cout << "科室信息如下：\n" << std::endl;
		std::cout << "科室\t\t" << "负责医生\t" << "号源上限\t" << "挂号费用\n" << std::endl;
		for (const auto& doof : mfc::v_doof) {
			switch (doof.office_name) {
			case 1:
				std::cout << "外科" << doof.info.office_id << "\t\t";
				break;
			case 2:
				std::cout << "内科" << doof.info.office_id << "\t\t";
				break;
			case 3:
				std::cout << "儿科" << doof.info.office_id << "\t\t";
				break;
			case 4:
				std::cout << "妇产科" << doof.info.office_id << "\t";
				break;
			case 5:
				std::cout << "精神科" << doof.info.office_id << "\t";
				break;
			}
			std::cout << doof.info.doctor_name << "\t\t" << doof.info.max_order << "\t\t";
			std::cout << doof.info.money << std::endl << std::endl;
		}
		system("pause");
		system("cls");
	}

//更新科室文件
	void manage_massage::update_doof() {
		std::ofstream doof_ofs(file_config::DOOF_FILE, std::ios::trunc | std::ios::out);
		if (!doof_ofs.is_open()) {
			std::cout << "文件打开失败..." << std::endl;
			this->is_empty = true;
			return;
		}
	
		for(const auto& doof_it:mfc::v_doof){
			doof_ofs << doof_it.office_name << " " << doof_it.info.office_id << " " 
				<< doof_it.info.doctor_name << " " << doof_it.info.max_order << " " << doof_it.info.money << std::endl;
		}
		doof_ofs.close();
	}

//修改科室信息
	void manage_massage::modifi_massage() {
		std::cout << "请输入你要修改的科室编号\n" << std::endl;
		this->show_massage();
		std::string id;
		std::cin >> id;
		std::vector<doctor_office>::iterator ret = is_exist(id);
		if (ret == mfc::v_doof.end()) {
			std::cout << "科室不存在...回去重新看看？..." << std::endl;
		}
		else {
			system("cls");
			doctor_office input;
			while (true) {
				std::cout << "请输入修改的科室名称：\n" << std::endl;
				std::cout << "[1] 外科\t[2] 内科\t[3] 儿科 " << std::endl;
				std::cout << "[4] 妇产科\t[5] 精神科" << std::endl;
				std::cin >> input.office_name;
				if (input.office_name >= 1 && input.office_name <= 5) break;
				std::cout << "只能输入这几个!(*￣(￣　*)" << std::endl;
			}


			std::cout << "请输入修改的科室编号：" << std::endl;
			std::cin >> input.info.office_id;

			int index = 0;
			mfc::get_doctor_name();
			while (true) {
				std::cout << "请选择医生：\n" << std::endl;
				int i = 0;
				for (const auto& temp_it : mfc::v_doctor_name) {
					std::cout << "[" << i << "] " << temp_it << std::endl;
					i++;
				}
				std::cin >> index;
				if (index >= 0 && index <= mfc::v_doctor_name.size() - 1) break;
				std::cout << "下次不要输错了!!!...( ＿ ＿)ノ｜" << std::endl;
				system("pause");
				system("cls");
			}

			input.info.doctor_name = mfc::v_doctor_name[index];

			std::cout << "请设置号源上限(不得超过20)" << std::endl;
			while (true) {
				std::cin >> input.info.max_order;
				if (input.info.max_order >= 0 && input.info.max_order <= 20) break;
				std::cout << "都说了不能超过!!!!!!" << std::endl;
			}

			switch (input.office_name) {
				//外科
			case 1:
				input.info.money = man::IM;
				break;
				//内科
			case 2:
				input.info.money = man::SG;
				break;
				//儿科
			case 3:
				input.info.money = man::PD;
				break;
				//妇产科
			case 4:
				input.info.money = man::GO;
				break;
				//精神科
			case 5:
				input.info.money = man::PS;
				break;
			}
			
			mfc::v_doof.emplace_back(input);
			std::cout << "修改完成||ヽ(*￣▽￣*)ノミ|Ю\n" << std::endl;
			this->update_doof();
			}
		system("pause");
		system("cls");
	}

//科室排序
	void manage_massage::my_sort() {
		std::cout << "请选择你要排序的方式：[1] 升序 [2] 降序" << std::endl;
		int select = 0;
		std::cin >> select;
		if (select == 1) {
			std::sort(mfc::v_doof.begin(),mfc::v_doof.end(), [](const doctor_office& doc_1, const doctor_office& doc_2) {
				return doc_1 < doc_2;
				});
			this->update_doof();
			this->show_massage();
		}
		else if (select == 2) {
			std::sort(mfc::v_doof.begin(), mfc::v_doof.end(), [](const doctor_office& doc_1, const doctor_office& doc_2) {
				return doc_1 > doc_2;
				});
			this->update_doof();
			this->show_massage();
		}
		else {
			std::cout << "输入错误..." << std::endl;
		}
	}
	 
//清空科室信息x
	void manage_massage::clear_office() {
		std::cout << "真的要清空吗(〃＞目＜)" << std::endl;
		std::cout << " 输入[0]清空科室信息    按任意键返回...\n" << std::endl;
		while (true) {
			if (_kbhit()) { //判断是否按下键位
				int key = _getch();		//按下键位后会产生相应的返回值
				if (key == 0 || key == 0xE0) {//功能键和方向键会返回0或0xE0
					std::cout << "下次注意噢(〃＞目＜)" << std::endl;
					break;
				}
				//只有为 0 才能返回菜单
				if (key == '0') {
					std::ifstream off_ifs(file_config::DOOF_FILE, std::ios::trunc);
					off_ifs.close();
					this->is_empty = true;
					std::cout << "信息已清空" << std::endl;
					std::cout << "他一定有他的道理...┗|｀O′|┛" << std::endl;
					break;
				}
				//其他字符
				else break;
			}
		}
		system("pause");
		system("cls");
	}
}
