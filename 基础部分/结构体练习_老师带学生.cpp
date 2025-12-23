#include<iostream>
#include<string>
#include<ctime>
using namespace std;
//学生的结构体
struct student {
	string s_name;
	double score;
};
//老师的结构体（包含学生的数组）
struct teacher {
	string t_name;
	struct student stu[5];
};
void print(struct teacher t[], int len) {
	string tn = "ABCDE";//老师和学生的名字，用字母代替
	for (int i = 0; i < len; i++)
	{
		t[i].t_name = "teacher_";
		t[i].t_name += tn[i];//字符串相加组成一个新的字符串
		for (int j = 0; j < 5; j++) {
			t[i].stu[j].s_name = "student_";//注意学生的结构体是在老师的结构体里建的
			t[i].stu[j].s_name += tn[j];//所以要带老师的数组前缀
			int x = rand() % 101;//成绩采用随机数
			t[i].stu[j].score = x;
		}
	}
}
void print2(struct teacher t[], int len) {
	for (int i = 0; i < len; i++)
	{
		cout << t[i].t_name << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << t[i].stu[j].s_name << ' ' << t[i].stu[j].score << endl;
		}
		std::cout << std::endl;
	}
}
int main() {
	srand((unsigned int)time(NULL));//每次运行都有不重复的随机数
	struct teacher t[3];
	int len = sizeof(t) / sizeof(t[0]);//计算数组长度
	print(t,len);
	print2(t, len);
	system("pause");
	return 0;
}