#include<iostream>
#include<string>
using namespace std;
struct hero {//定义英雄结构体
	string name;
	int age;
	string sex;
};
void bubble_sort(struct hero hero_array[], int len) {
	for (int i = 0; i < len-1; i++)	//冒泡排序
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (hero_array[j].age > hero_array[j + 1].age)//判断英雄数组中的年龄
			{
				struct hero temp =hero_array[j];//定义一个临时结构体变量用来存储英雄数组
				hero_array[j] = hero_array[j + 1];
				hero_array[j + 1]= temp;
			}
		}
	}
}
void print_hero(struct hero hero_array[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << hero_array[i].name << '\t' << hero_array[i].age << '\t'//进行输出
			<< hero_array[i].sex << endl;
	}
}
int main() {
	struct hero hero_array[5] = { //赋值
			{ "刘备",23,"男"},
			{"关羽",22,"男"}, 
			{"张飞",20,"男"}, 
			{"赵云",21,"男"}, 
			{"貂蝉",19,"女"}
	};
	int len = sizeof(hero_array) / sizeof(hero_array[0]);//计算长度
	for (int i = 0; i < len; i++)//先输出初始数组，以作对比
	{
		cout << hero_array[i].name << '\t' << hero_array[i].age << '\t'
			<< hero_array[i].sex << endl;
	}
	cout << endl << endl;
	bubble_sort(hero_array, len);
	print_hero(hero_array, len);
	system("pause");
	return 0;
}