#pragma once
#include<iostream>							
#include<string>							//第三个项目 校园歌唱比赛流程管理系统  还好哈哈哈
#include<vector>							//完结撒花！！！  2025.11.15 写了四五天才能弄完	
#include<map>								//用了一些 C++11新特性   随机姓名生成器最好玩
#include<deque>								//写博客复习去了,芜湖
#include"Singer.h"							
#include<random>							
#include<algorithm>
#include<numeric>
#include<iomanip>  //使用固定浮点型的小数位数必须包含此头文件
#include<fstream>
#include<conio.h> //控制台交互非标准头文件 主要实现键盘的交互
class sing_manager {				//歌唱管理类
public:
	//构造函数
	sing_manager();

	//显示菜单
	void show_menu();

	//退出管理系统
	void exit_system();

	//初始化容器和成员变量
	void init_sing();

	//初始化创建100名选手
	void create_singer();

	//随机姓名生成器
	std::string random_name();

	//开始比赛
	void start_match();

	//抽签
	void random_draw();

	//显示抽签结果
	void show_draw(const std::vector<int>& show_v) const;

	//比赛中
	void sing_match();

	//评委打分
	double judge_score();

	//显示晋级选手
	void show_score();

	//保存到文件里
	void save_record();

	//判断两个文件是否为空
	bool is_singer(const int& select);

	//显示往届记录
	void show_record();

	//读取文件里面的数据
	void read_file(const int& select);

	//清空文件里所有记录
	void clear_record();

	//析构函数
	~sing_manager();

	//存放参加海选的人 100人
	std::vector<int> v1;

	//第一轮为海选晋级 50人
	std::vector<int> v2;

	//第二轮为晋级十佳 10人
	std::vector<int> v3;

	//第三轮为三强 3人
	std::vector<int> v_victory;

	//存放选手的编号和具体选手信息
	std::map<int, singer> m_singer;

	//记录比赛轮数
	int s_count;

	//判断文件是否为空
	bool file_empty_ten;
	bool file_empty_victory;

	//存放读取到的往届记录 
	std::map<int, std::vector<std::string>> ten_record;
	std::map<int, std::vector<std::string>> victory_record;
};