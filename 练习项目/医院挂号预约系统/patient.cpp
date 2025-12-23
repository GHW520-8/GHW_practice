#include<iostream>
#include"patient.h"
//默认构造函数
patient::patient() {

}

//有参构造函数赋值
patient::patient(std::string name, std::string p_num, std::string password) {
	this->user_name = name;
	this->phone_num = p_num;
	this->user_password = password;
}

//显示患者菜单
void patient::show_pat_menu() {
	std::cout << "\t+";
	for (int i = 0; i < 15; i++) std::cout << " -";
	std::cout << " +" << std::endl;
	std::cout << "\t|  您好先生/女士，祝您早日康复  | " << std::endl;
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
	std::cout << "\t[ [\t[1] 预 约 挂 号     ] ]" << std::endl;
	std::cout << "\t[ [\t                    ] ]" << std::endl;
	std::cout << "\t[ [\t[2] 挂 号 详 情     ] ]" << std::endl;
	std::cout << "\t[ [\t                    ] ]" << std::endl;
	std::cout << "\t[ [\t[3] 取 消 挂 号     ] ]" << std::endl;
	std::cout << "\t[ [\t                    ] ]" << std::endl;
	std::cout << "\t[ [\t[0] 注 销 登 录     ] ]" << std::endl;
	std::cout << "        ===============================" << std::endl;
	std::cout << "       =================================" << std::endl;
}

//患者控制菜单
void patient::control_menu() {
	//新选择来咯
	int pat_select;
	while (true) {
		//显示患者菜单
		this->show_pat_menu();
		pat_select = 0;
		std::cin >> pat_select;
		switch (pat_select) {
			//注销登录
		case 0:
			std::cout << "成功注销登录" << std::endl << std::endl;
			std::cout << "多注意注意身体哦`(*>﹏<*)′" << std::endl << std::endl;
			return;
			//预约挂号
		case 1:
			this->apply_order();
			break;
			//挂号详情
		case 2:
			this->show_Myorder();
			break;
			//取消挂号
		case 3:
			this->cancel_order();
			break;
		default:
			std::cout << "输入有误，请重新选择!!!" << std::endl;
			system("pause");
			system("cls");
		}
	}


}

//预约挂号
void patient::apply_order() {
	std::cout << "医院工作时间为周一至周五→_→\n" << std::endl;
	std::cout << "请输入预约挂号日期：" << std::endl;
	std::cout << "[1] 周一" << std::endl;
	std::cout << "[2] 周二" << std::endl;
	std::cout << "[3] 周三" << std::endl;
	std::cout << "[4] 周四" << std::endl;
	std::cout << "[5] 周五" << std::endl;
	//输入预约挂号日期
	int date = 0;
	while (true) {
		std::cin >> date;
		if (date >= 1 && date <= 5) {
			break;
		}
		std::cout << "这也能输错 ？重来 ←_←" << std::endl;
	}

	//输入预约时间段
	int intraval = 0;
	std::cout << "请输入预约时间段：\n" << std::endl;
	std::cout << "[1] 上午" << std::endl;
	std::cout << "[2] 下午" << std::endl;
	while (true) {
		std::cin >> intraval;
		if (intraval >= 1 && intraval <= 2) {
			break;
		}
		std::cout << "拜托，还来 ？回去重输(￣_￣|||)" << std::endl;
	}

	//输入挂号科室
	int office_num = 0;
	std::cout << "请选择科室：\n" << std::endl;
	std::cout << "[1] 外科\t[2] 内科\t[3] 儿科 " << std::endl;
	std::cout << "[4] 妇产科\t[5] 精神科" << std::endl;
	while (true) {
		std::cin >> office_num;
		if (office_num >= 1 && office_num <= 5) {
			break;
		}
		std::cout << "回家吧孩子，回家吧━━(￣ー￣*|||━━" << std::endl;
	}

	//将医生姓名单独读取出来
	std::ifstream doc_ifs(file_config::DOCT_FILE, std::ios::in);
	if (!doc_ifs.is_open()) {
		std::cout << "文件打开失败..." << std::endl;
		return;
	}
	mfc::input_info temp;
	std::vector<std::string> v_temp;
	while (doc_ifs >> temp.input_name >> temp.input_id >> temp.input_password) {
		v_temp.emplace_back(temp.input_name);
	}
	doc_ifs.close();

	//输入挂号医生
	int select_doctor = 0;
	while (true) {
		std::cout << "请选择医生：\n" << std::endl;
		int i = 0;
		for (const auto& temp_it : v_temp) {
			std::cout << "[" << i << "] " << temp_it << std::endl;
			i++;
		}
		std::cin >> select_doctor;
		if (select_doctor >= 0 && select_doctor <= v_temp.size() - 1) break;
		std::cout << "下次不要输错了!!!...( ＿ ＿)ノ｜" << std::endl;
		system("pause");
		system("cls");
	}

	//统一写入文件
	std::ofstream or_ofs(file_config::ORDER_FILE, std::ios::out | std::ios::app);
	or_ofs <<"date:"<< date << " " << "intraval:"<<intraval << " " <<"office_num:"<< office_num << " " 
		<< "select_doctor:" << select_doctor << " " << "phone_number:" << this->phone_num << " " << "status:" << 1 << std::endl;
	or_ofs.close();

	std::cout << "预约成功!!!正在审核..." << std::endl;
	system("pause");
	system("cls");
	order_file ord;
}

//查看挂号详情
void patient::show_Myorder() {
	order_file ord_f;
	if (ord_f.order_size == 0) {
		std::cout << "没有预约记录噢" << std::endl;
		system("pause");
		system("cls");
		return;
	}
	//更新医生姓名
	mfc::get_doctor_name();
	//日期
	auto day = [](const int& index) {
		std::array<std::string, 5> arr{ "一","二","三","四","五" };
		return arr[index-1];
		};
	//时间段
	auto office = [](const int& index) {
		std::array<std::string, 5> arr{ "外科","内科","儿科","妇产科","精神科" };
		return arr[index - 1];
		};
	//医生姓名
	auto doc_name = [](const int& index) {
		return mfc::v_doctor_name[index];
		};
	//状态
	auto status = [](const int& index) {
		std::array<std::string, 4> arr{ "预约失败","审核中","已预约","预约已被取消" };
		return arr[index];
		};
	//标题
	std::cout << "\t\t\t\t挂 号 单\n" << std::endl;
	std::cout << "预约日期\t" << "时间段\t\t" << "科室\t\t" << "医生\t\t" << "状态\n" << std::endl;
	for (int i = 0; i < ord_f.order_size; i++) {
		//这里判断中的类型转换是多余操作，但为了展示atoi 和c_str就强行写了...
		if (atoi(ord_f.m_save[i]["phone_number"].c_str()) == stoi(this->phone_num)) {
			//预约日期
			std::cout << "星期" << day(stoi(ord_f.m_save[i]["date"])) << "\t\t";
			//预约时间段
			std::cout << (ord_f.m_save[i]["intraval"] == "1" ? "上午" : "下午") << "\t\t";
			//科室
			std::cout << office(stoi(ord_f.m_save[i]["office_num"])) << "\t\t";
			//预约医生
			std::cout << doc_name(stoi(ord_f.m_save[i]["select_doctor"])) << "\t\t";
			//预约状态
			std::cout << status(stoi(ord_f.m_save[i]["status"])) << std::endl << std::endl;
		}
	}
	system("pause");
	system("cls");
}

//取消预约
void patient::cancel_order() {
	order_file c_order;
	if (c_order.order_size == 0) {
		std::cout << "没有预约记录噢" << std::endl;
		system("pause");
		system("cls");
		return;
	}

	std::cout << "只有审核中或预约成功的记录才可以取消噢{{{(>_<)}}}\n" << std::endl;
	for (int i = 0; i < c_order.order_size; i++) {
		if (c_order.m_save[i]["phone_number"] == this->phone_num) {
			if (c_order.m_save[i]["status"] == "1" || c_order.m_save[i]["status"] == "2") {

			}
		}
	}
}