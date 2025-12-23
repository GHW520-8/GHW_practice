#include<iostream>						//第二个练习项目  比第一个难好多嘤嘤嘤  2025.10.26
#include<string>						
#include"worker_manage.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
int main(void)
{	//测试代码
	/*worker* w_worker = NULL;
	w_worker = new employee(1001, "小光", 18);
	w_worker->show_info();
	delete w_worker;

	w_worker = new manager(1002, "小李", 20);
	w_worker->show_info();
	delete w_worker;

	w_worker = new boss(1003, "小王", 25);
	w_worker->show_info();
	delete w_worker;*/

	w_manage wm;
	int select=0;	//存放用户的选择
	while (true)
	{
		wm.show_menu();
		std::cout << "请输入功能的对应编号：" << std::endl;
		std::cin >> select;
		switch (select)
		{
		case 0:		//退出
			wm.exit_system();
			break;
		case 1:		//添加
			wm.addinfo();
			break;
		case 2:		//显示
			wm.show_emp();
			break;
		case 3:		//删除
			wm.del_emp();
			break;
		case 4:		//查找
			wm.find_emp();
			break;
		case 5:		//修改
			wm.mod_emp();
			break;
		case 6:		//排序
			wm.sort_emp();
			break;
		case 7:		//清空
			wm.clean_file();
			break;
		case 8:		//恢复
			wm.renew_file();
			break;
		default:
			std::cout << "输入错误，请重新输入!" << std::endl;
			system("cls");
			break;
		}
		
	}
	system("pause");
	return 0;
}