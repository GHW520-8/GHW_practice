#include<iostream>						//第一个练习项目，看了思路一天就写好啦嘿嘿嘿开心
#include<string>						//完结撒花！！！ 2025.10.18
#include<limits>						//清空缓存区代码需包含此头文件					
										//控制台好丑，想学 qt 的心更重了
#include<conio.h>//无缓冲键盘输入,应用在清空通讯录函数(_kbhit(),_getch())
using namespace std;
#define mad 1000//最多记录1000条
//定义一个全局变量存储纪录数
int TEMP = 0;

//联系人结构体
struct person_record {
	string t_name;//姓名
	int t_sex;//性别
	int t_age;//年龄
	string t_phone;//电话号码
	string t_add;//地址
};

//通讯录结构体
struct address_book {

	struct person_record person_array[mad];//结构体嵌套，定义数组方便存储记录
	int t_size;//数组的下标
};


//菜单界面
void show_menu()
{
	cout << "****欢迎使用通讯录管理系统****" << endl;
	for (int i = 1; i < 9; i++)
	{
		for (int k = 0; k <= 9 - i; k++)
		{
			cout << ' ';
		}
		for (int j = 1; j < i * 2; j++)//输出等腰三角形
		{
			cout << '*';
		}
		for (int x = 1; x < 9 - i; x++)
		{
			cout << '#';
		}
		for (int y = 1; y < i; y++)//两个三角形合成一个平行四边形
		{
			cout << '#';
		}
		cout << endl;
	}
	cout << " **** (1) 添加联系人 ####" << endl;//输出菜单，面向结果编程哈哈哈
	cout << " **** (2) 显示联系人 ####" << endl;
	cout << " **** (3) 删除联系人 **##" << endl;
	cout << " **** (4) 查找联系人 ***#" << endl;
	cout << " **** (5) 修改联系人 ****" << endl;
	cout << " **** (6) 清空通讯录 ****" << endl;
	cout << " **** (7) 恢复通讯录 ****" << endl;
	cout << " **** (0) 退出通讯录 ****" << endl;
	cout << " ************************" << endl;
	cout << " ************************" << endl;
}


//添加联系人
void add_person(address_book* abs) {
	if (abs->t_size == mad) {//最多1000条记录
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	while (true) {
		cout << "输入联系人的信息,按[0]可退出添加流程" << endl;
		//输入姓名
		string name;
		cout << "姓名：" << endl;
		cin >> name;
		if (name == "0")
		{
			cout << "已退出添加流程" << endl;
			break;
		}
		abs->person_array[abs->t_size].t_name = name;
		//输入性别
		int sex;
		while (true) {
			cout << "性别：(1)男 (2)女：" << endl;
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->person_array[abs->t_size].t_sex = sex;
				break;
			}
			else {
				cout << "输入有误,只能输入1或2 " << endl;
				cin.clear();
				//清空输入缓存区，忽略当行所有记录，直到'\n'，防止陷入死循环
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
		//输入年龄
		int age;
		cout << "年龄：" << endl;
		cin >> age;
		abs->person_array[abs->t_size].t_age = age;

		//输入电话号码
		string phone="";
		cout << "电话号码：" << endl;
		cin >> phone;
		abs->person_array[abs->t_size].t_phone = phone;
		cin.clear();

		//输入家庭住址
		string add;
		cout << "家庭住址：" << endl;
		cin >> add;
		abs->person_array[abs->t_size].t_add = add;
		cin.clear();
		//清空输入缓存区，忽略当行所有记录，直到'\n'，防止陷入死循环
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		abs->t_size++;
	}
	system("pause");
	system("cls");//清空页面
}

//显示联系人
void show_person(address_book* abs) {
	if (abs->t_size == 0)
	{
		cout << "记录为空！" << endl;
	}
	else {
		cout << "姓名" << '\t';
		cout << "性别" << '\t';
		cout << "年龄" << '\t';
		cout << "电话号码" << '\t';
		cout << "家庭住址" << endl;
		for (int i = 0; i < abs->t_size; i++)
		{
			cout << abs->person_array[i].t_name << '\t';
			cout << (abs->person_array[i].t_sex == 1 ? "男" : "女") << '\t';//三目运算符，注意括号
			cout << abs->person_array[i].t_age << '\t';
			cout << abs->person_array[i].t_phone << '\t';
			cout << abs->person_array[i].t_add << endl;
		}
	}
	system("pause");
	system("cls");
}

//检测联系人是否存在   方便后续函数调用
int isexist(address_book* abs,string name) {
	for (int i = 0; i <abs->t_size; i++)	
	{										
		if (abs->person_array[i].t_name == name)//找到联系人返回下标的位置
		{
			return i;
		}
	}
	return -1;
}

//删除联系人
void delete_person(address_book* abs) {
	string name;
	cout << "请输入你要删除联系人的名字" << endl;
	cin >> name;
	int temp = isexist(abs, name);
		if (temp==-1)
		{
			cout << "查无此人" << endl;
		}
		else
		{
			//数组长度 -1 防止越界
			for (int i = temp; i < abs->t_size - 1; i++)
			{ 
				//直接后值覆盖前值
				abs->person_array[i] = abs->person_array[i + 1];
			}			
			//删除后记得下标-1
			abs->t_size--;
			cout << "删除成功！" << endl;
		}
		system("pause");
		system("cls");
}

//查找联系人
void find_person(address_book* abs) {
	string name;
	cout << "请输入你要查找的联系人：" << endl;
	cin >> name;
	int temp = isexist(abs, name);
	if (temp == -1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		cout << "找到啦!" << endl;
		cout << "姓名：" << abs->person_array[temp].t_name << '\t';
		cout << "性别："<<(abs->person_array[temp].t_sex == 1 ? "男" : "女") << '\t';
		cout << "年龄：" << abs->person_array[temp].t_age << '\t';
		cout << "电话号码：" << abs->person_array[temp].t_phone << '\t';
		cout << "家庭地址：" << abs->person_array[temp].t_add <<endl;
	}
	system("pause");
	system("cls");
}

//修改联系人
void renew_person(address_book* abs) {
	cout << "请输入你要修改的联系人名字：" << endl;//跟添加一个原理
	string name;
	cin >> name;
	int t_new = isexist(abs, name);
	if (t_new == -1)
	{
		cout << "查无此人" << endl;
	}
	else {
		cout << "正在修改中..." << endl;
		cout << "请输入修改的联系人信息：" << endl;
		//修改姓名
		cout << "姓名：" << endl;
		cin >> name;
		abs->person_array[t_new].t_name = name;
		//修改性别，只能输入1或2
		int sex;
		while (true) {
			cout << "性别：(1)男 (2)女：" << endl;
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->person_array[t_new].t_sex = sex;
				break;
			}
			else {
				cout << "输入有误,只能输入1或2 " << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
		//修改年龄
		int age;
		cout << "年龄：" << endl;
		cin >> age;
		abs->person_array[t_new].t_age = age;

		//修改电话号码
		string phone = "";
		cout << "电话号码：" << endl;
		cin >> phone;
		abs->person_array[t_new].t_phone = phone;
	
		//修改家庭住址
		string add;
		cout << "家庭住址：" << endl;
		cin >> add;
		abs->person_array[t_new].t_add = add;
	}
	cout << "修改成功！" << endl;
	system("pause");
	system("cls");
}

//清空通讯录
void clean_person(address_book* abs) {
	cout << "你确定要清空所有记录吗？" << endl;
	cout << "输入[1]确定，按任意键取消返回" << endl;
	TEMP = abs->t_size;			//先将下标存储，方便后续的恢复功能
	while (true) {
		if (_kbhit())//这个函数是判断是否按下键位
		{
			int key = _getch();		//按下键位后会产生相应的返回值
			if (key == 0 || key == 0xE0) {//功能键和方向键会返回0或0xE0
				cout << "下次看好再来噢 >_< ！" << endl;
				break;
			}
			if (key == '1')			//这里再判断是否继续删除
			{
				abs->t_size = 0;	
				cout << "通讯录已清空！" << endl;
				break;
			}
			else                    //其他字符
			{
				cout << "下次看好再来噢 >_< ！" << endl;
				break;
			}
		}
	}
	system("pause");
	system("cls");
}

//恢复通讯录
void return_person(address_book* abs){
	abs->t_size = TEMP;				//直接赋值就完了
	cout << "恢复成功！" << endl;
	system("pause");
	system("cls");
}
//主函数
int main()
{
	int num=0;				//用户输入的代号
	address_book abs;		//定义结构体变量
	abs.t_size = 0;			//给下标初始化，不能写在循环和自定义函数里面
	while (true)
	{
		show_menu();		//先输出菜单栏
		cout << "请输入功能的对应代号：" << endl;
		cin >> num;
		switch (num)
		{
		case 1:
			add_person(&abs);
			break;
		case 2:
			show_person(&abs);
			break;
		case 3:
			delete_person(&abs);
			break;
		case 4:
			find_person(&abs);
			break;
		case 5:
			renew_person(&abs);
			break;
		case 6:
			clean_person(&abs);
			break;
		case 7:
			return_person(&abs);
			break;
		case 0:cout << "欢迎下次使用！" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入错误，请重新输入" << endl;
			system("cls");
		}
	}
}