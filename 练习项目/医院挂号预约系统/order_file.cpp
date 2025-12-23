#include<iostream>
#include"order_file.h"

//构造函数初始化
order_file::order_file() {
	this->order_size = 0;
	this->read_order();
}
//读取预约挂号信息
void order_file::read_order() {
	//读取的方式打开预约文件
	std::ifstream ord_ifs(file_config::ORDER_FILE, std::ios::in);
	if (!ord_ifs.is_open()) {
		std::cout << "文件打开失败..." << std::endl;
		this->order_size = 0;
		return;
	}
	//使用lambda表达式实现截取字符
	auto key_and_value = [](const std::string& str) ->std::pair<std::string, std::string> {
		//find()返回的是 size_t 类型的数据
		size_t pos = str.find(":");
		//nops 判断比 -1 更精准
		if (pos == std::string::npos) { return { "","" }; } //返回空对组
		std::string key = str.substr(0, pos);
		std::string value = str.substr(pos + 1); //substr如果没有第二个参数默认截取到末尾
		return { key,value };
		};

	//临时存储预约信息
	std::vector<std::string> v_temp;
	//预先分配空间，防止越界
	v_temp.resize(6);
	while (ord_ifs >> v_temp[0] >> v_temp[1] >> v_temp[2] >> v_temp[3] >> v_temp[4] >> v_temp[5] ) {
		std::map<std::string, std::string> m_swap;
		//每次一条数据读取完就插入临时的 map 容器
		for (int i = 0; i < 6; i++) {
			m_swap.insert(key_and_value(v_temp[i]));
		}
		//最后统一插入大容器
		this->m_save.insert(std::make_pair(order_size, m_swap));
		this->order_size++;
	}
	ord_ifs.close();
	//测试代码
	/*for (const auto& big_it : this->m_save) {
		std::cout << big_it.first << std::endl;
		for (const auto& small_it : big_it.second) {
			std::cout << small_it.first << " " << small_it.second << " ";
		}
		std::cout << std::endl;
	}
	system("pause");
	system("cls");*/
}

//更新预约挂号信息
void order_file::update_order() {
	if (this->order_size = 0) return;
	std::ofstream ord_ofs(file_config::ORDER_FILE, std::ios::trunc);
	for (int i = 0; i < this->order_size; i++) {
		ord_ofs << "date:" << this->m_save[i]["date"] << " ";
		ord_ofs << "intraval:" << this->m_save[i]["intraval"] << " ";
		ord_ofs << "office_num:" << this->m_save[i]["office_num"] << " ";
		ord_ofs << "select_doctor:" << this->m_save[i]["select_doctor"] << " ";
		ord_ofs << "status:" << this->m_save[i]["status"] << std::endl;
	}
	ord_ofs.close();
}