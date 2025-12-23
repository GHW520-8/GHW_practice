#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<vector>
//打印输出
void print(std::vector<std::string>& pr_name) {
	for (std::vector<std::string>::iterator it = pr_name.begin(); it != pr_name.end(); it++){
		std::cout << *it << std::endl;
	}
}
std::string rand_name() {
	//姓氏
	std::vector<std::string> last_name{
		"王","李","张","刘" ,"陈" ,"杨" ,"赵" ,"黄" ,"周" ,"吴" ,
		"徐","孙" ,"胡" ,"朱" ,"高" ,"林" ,"何" ,"郭" ,"马" ,"罗" };

	//第二个名 当为两个字的姓名时 只需要将 last_name和first_name 组合成名字就行
	std::vector<std::string> first_name{
		"云","明","飞","雨","羽","薇","亮","华","暧","文","风","凤",
		"峰","洪","武","鸿","丽","书","树","剑","舒","巳","玉","立" };

	//第三个名 当为三个字的姓名时先随机将两个名组合 再和姓组合
	std::vector<std::string> double_first_name{
		"昭","寒","励","昊","冠","洋","昌","炎","玚","璟","璥","瑜",
		"生","琸","瑎","玚","璟","璥","溯","湔","书","树","剑","立" };
	//随机获取姓
	int sur_last = rand() % last_name.size();
	std::string temp_name = last_name[sur_last];
	//第二个字作为公用
	int sur_first = rand() % first_name.size();
	std::string temp_first = first_name[sur_first];
	//第三个字
	int sur_dou_first = rand() % double_first_name.size();
	std::string temp_dou_first = double_first_name[sur_dou_first];
	//三目运算符 返回拼接后的姓名
	return rand() % 2 ? temp_name + temp_first : temp_name + temp_first + temp_dou_first;
}
void test01() {
	std::string name;
	std::vector<std::string> person;
	for (int i = 0; i < 10; i++) {
		name = rand_name();
		person.push_back(name);
	}
	print(person);
}
int main() {
	//初始化随机种子
	srand((unsigned int)time(nullptr));
	test01();
	return 0;
}