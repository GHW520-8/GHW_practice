#include<iostream>
#include"Sing_manager.h"
#include"Singer.h"
int main()
{
	//用户的选项
	int select = 0;
	//创建歌唱管理类对象
	sing_manager manage;

	//测试代码
	/*std::cout << "编号\t" << "姓名\t" << "分数" << std::endl;
	for (const auto& it : manage.m_singer)
	{
		std::cout << it.first << '\t';
		std::cout << it.second.s_name << '\t';
		std::cout << it.second.s_score[0] << std::endl;
	}*/
	while (true)
	{
		//显示菜单
		manage.show_menu();
		std::cout << "请输入编号：" << std::endl;
		std::cin >> select;
		switch (select)
		{
			//退出系统
		case 0:
			manage.exit_system();
			break;

			//开始歌唱比赛
		case 1:
			manage.start_match();
			system("cls");
			break;

			//查看往届比赛结果
		case 2:
			manage.show_record();
			break;
			//清空所有比赛记录
		case 3:
			manage.clear_record();
			break;
		default: 
			std::cout << "输入有误，请重新输入!!!" << std::endl;
			system("pause");
			system("cls");
		}
	}
	system("pause");
	return 0;
}