#include<iostream>
#include<string>
using namespace std;
struct student {
	string name;
	int age;
	double score;
};
int main() {
	struct student arr[3] = {               //定义结构体数组可以顺便赋值
		{"张三",14,100.0},
		{"李四",15,98.5},
		{"王五",16,89.5}
	};
	//若要修改定义好的数组里的值，直接访问具体的数组元素修改，使用"."+变量名
	arr[2].name = "赵六";
	arr[2].age= 17;
	arr[2].score = 99.5;
	for (int i = 0; i < 3; i++)//遍历数组
	{
		cout << arr[i].name << '\t' << arr[i].age << '\t' << arr[i].score << endl;
	}
	system("pause");
	return 0;
}