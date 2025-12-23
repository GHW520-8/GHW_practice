#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<utility>  //pair对组的头文件
#include"main_func.h"
#include"global_file.h"
class order_file {
public:
	//构造函数初始化
	order_file();
	//读取预约挂号信息
	void read_order();
	//更新预约挂号信息
	void update_order();
	//预约数量
	int order_size;
	//保存文件里的记录
	std::map<int, std::map<std::string, std::string>> m_save;
};
//重载右移运算符，直接通过它实现文件流的读取
template<typename T>
std::istream& operator>>(std::istream& ifs, std::vector<T>& vec) {
	T val;
	ifs >> val;
	if (ifs) vec.emplace_back(val);
	return ifs;
}
