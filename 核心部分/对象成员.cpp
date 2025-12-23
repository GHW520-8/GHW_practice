#include<iostream>
class student {
public:
	student(double score): s_score(score){
		std::cout << "student的构造函数" << std::endl; 
	}
	~student() { std::cout << "student的析构函数" << std::endl; }
	double s_score;
};
class teacher {
public:
	//隐式转换法：student stu = score
	teacher(int id,double score): t_id(id),stu(score){ 
		std::cout << "teacher的构造函数" << std::endl; 
	}
	~teacher(){ std::cout << "teacher的析构函数" << std::endl; }
	int t_id;
	student stu;
};
void test01() {
	teacher t(1001, 66.5);
	std::cout << "老师工号：" << t.t_id 
	<< "  学生分数：" << t.stu.s_score << std::endl;
}
int main()
{
	test01();
	return 0;
}