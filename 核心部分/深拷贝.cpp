#include<iostream>
class student {
public:
	student(int id, double score) {
		stu_id = id;
		//开辟堆区内存
		stu_score = new double(score);
	}
	//如果开辟了堆区，一定要自己写拷贝构造函数，否则浅拷贝会报错	
	student(const student& s) {
		stu_id = s.stu_id;
		//报错，默认浅拷贝导致重复释放
		//stu_score = s.stu_score;  
		//深拷贝，开辟堆区内存，不同对象之间互不干扰
		stu_score = new double(*s.stu_score);
	}
	//一定要手动释放分配的内存，否则会导致内存泄漏
	~student() {
		//如果值不为空就清理
		if (stu_score != nullptr){
			delete stu_score;
		}
		//为了防止野指针的情况，最好再将值置空
		stu_score = nullptr;
	}
	int stu_id;
	double* stu_score;
};
void test01(){
	student s1(1001, 70.5);
	student s2(s1);
	std::cout << s1.stu_id << ' ' << *s1.stu_score << std::endl;
	std::cout << s2.stu_id << ' ' << *s2.stu_score << std::endl;
}
int main()
{
	test01();
	return 0;
}