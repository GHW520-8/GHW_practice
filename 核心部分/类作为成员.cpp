#include<iostream>
#include<string>
//学生类
class student {
public:
	std::string s_name;
	double s_score;
};
//老师类
class teacher {
public:
	//显示
	void show(){
		std::cout << "老师工号：" << t_id << std::endl;
		std::cout << "带的学生：" << stu.s_name << std::endl;
		std::cout << "学生分数：" << stu.s_score << std::endl;
	}

	std::string t_id;
	//使用类作为成员不用加关键字 class
	student stu;
};
int main()
{
	teacher t1;
	//初始化成员
	t1.t_id = "H1001";
	t1.stu.s_name = "小光";
	t1.stu.s_score = 89.5;
	//显示
	t1.show();
	return 0;
}