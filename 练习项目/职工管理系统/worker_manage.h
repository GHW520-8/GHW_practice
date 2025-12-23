#pragma once
#include<iostream>
#include<fstream>
#include<conio.h>//无缓冲键盘输入,应用在清空函数(_kbhit(),_getch())
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
class w_manage			//职工管理类，负责主要功能的实现
{
public:
	//构造函数
	w_manage();

	//显示菜单
	void show_menu();

	//退出程序
	void exit_system();

	//以文件形式保存
	void save();

	//统计人数
	int get_num();

	//初始化职工(将文件中的记录读取到数组里)
	void w_init();

	//添加职工信息
	void addinfo();

	//显示职工信息
	void show_emp();

	//删除职工
	void del_emp();

	//查找职工
	void find_emp();
	
	//修改职工记录
	void mod_emp();

	//给记录排序
	void sort_emp();

	//清空记录
	void clean_file();
	void clean_file2();
	void clean_file3();

	//恢复记录
	void renew_file();

	//判断职工是否存在
	int is_exist(int id);

	//释放数据
	void delete_file();

	//记录职工的人数
	int w_num;
	//创建一个二级指针，使用数组存放指向子类对象的父类指针
	worker** w_array;
	//定义一个 bool类型判断文件是否为空
	bool file_empty;

	//析构函数
	~w_manage();
};