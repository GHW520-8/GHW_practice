#pragma once
#include<iostream>
#include<string>
#include<array>
//选手类
class singer {
public:
	std::string s_name;
	//3轮得分   使用array是因为他比内置数组更安全
	std::array<double, 3> s_score{ 0.0 };
};