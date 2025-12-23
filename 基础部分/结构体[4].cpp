#include<iostream>
#include<string>
using namespace std;
struct student {
	string name;
	int age;
	double score;
};
void print1(struct student stu){
	stu.age = 100;
	cout << "子函数值传递： "<<stu.name << '\t' << stu.age << '\t' << stu.score << endl;
}
void print2(/*const*/ struct student* stu) {//注意地址不变，值变
	stu->age = 200;//在形参前使用const可以使值不可修改，使用指针时可以减少出错
	cout <<"子函数地址传递： " <<stu->name << '\t' << stu->age << '\t' << stu->score << endl;
}

int main() {
	struct student stu { "李四", 15, 89.5 };
	print1(stu);
	cout << "原函数1： " << stu.name << '\t' << stu.age << '\t' << stu.score << endl;//不变
	print2(&stu);
	cout <<"原函数2： "<<stu.name << '\t' << stu.age << '\t' << stu.score << endl;//改变
}
