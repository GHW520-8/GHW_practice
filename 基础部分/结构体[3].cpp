#include<iostream>
#include<string>
using namespace std;
struct student {
	string name;
	int age;
	double score;
};
struct teacher {
	string name;
	int id;
	int age;
	struct student stu;
};
int main() {
	student s1 ={ "张三",14,100.0 };
	student * p = &s1;
	cout << p->name << '\t' << p->age << '\t' << p->score <<endl;//结构体指针使用"->"访问结构体变量

					//结构体嵌套
	teacher t{ "老王",25000,55 };
		t.stu.name = "李四";//将第一个结构体中的嵌套结构体进行赋值
		t.stu.age = 20;
		t.stu.score = 88.5;
	cout << t.name << '\t' << t.age << '\t' << t.id << endl//输出
		<< t.stu.name << '\t' << t.stu.age << '\t' << t.stu.score << endl;
					system("pause");
					return 0;
}
	