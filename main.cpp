#include <iostream>
#include "globalFile.h"
#include "MenuInterface.h"
using namespace std;

int main() {

	int select = 0;

	while (true)
	{
        MenuInterface MI;
		cout << "======================  欢迎来到传智播客机房预约系统  =====================" << endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.学生代表             |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.老   师             |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.管 理 员            |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.退   出             |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "输入您的选择: ";

		cin >> select; //接受用户选择

		switch (select)
		{
		case 1:  //学生身份
		    MI.login(STUDENT_FILE, 1);
			break;
		case 2:  //老师身份
            MI.login(TEACHER_FILE, 2);
			break;
		case 3:  //管理员身份
            MI.login(ADMIN_FILE, 3);
			break;
		case 0:  //退出系统
		    cout << "欢迎下次使用！" << endl;
		    system("read -p '按任意键退出...' var");
		    exit(0);
			break;
		default:
		    cout << "输入有误，请重新选择！" << endl;
		    system("read -p '按任意键退出...' var");
		    system("clear");
		    break;
		}

	}
	system("pause");
	return 0;
}
