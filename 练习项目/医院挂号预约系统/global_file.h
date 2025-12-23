#pragma once
#include<iostream>
#include<string>		//使用类封装全局文件，替代宏的方案
class file_config {
public:
	//患者文件
	static const std::string PATI_FILE;
	//医生文件
	static const std::string DOCT_FILE;
	//管理员文件
	static const std::string ADMI_FILE;
	//科室信息文件
	static const std::string DOOF_FILE;
	//预约文件
	static const std::string ORDER_FILE;
};