#pragma once
#include<iostream>
#include<string>
class doctor_info {
public:
	//医生办公室编号
	std::string office_id;
	//医生姓名
	std::string doctor_name;
	//号源上限
	int max_order;
	//挂号费用
	std::string money;
};
class doctor_office {
public:
	//科室代号
	int office_name;
	//负责医生信息
	doctor_info info;
};