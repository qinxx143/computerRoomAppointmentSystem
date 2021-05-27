#include <iostream>
#include <fstream>
#include "globalFile.h"
#include "Identity.h"
#include "Student.h"
#include "Teacher.h"
#include "Manager.h"

using namespace std;

//学生界面菜单
void studentMenu(Identity* student){
    Student* stu = (Student*) student;

    while(true){
        student->operMenu();

        Student* stu = (Student*)student;
        int select = 0;

        cin >> select;

        if (select == 1) //申请预约
        {
            stu->applyOrder();
        }
        else if (select == 2) //查看自身预约
        {
            stu->showOrder();
        }
        else if (select == 3) //查看所有预约
        {
            stu->showAllOrder();
        }
        else if (select == 4) //取消预约
        {
            stu->cancelOrder();
        }
        else
        {
            delete stu;
            cout << "注销成功" << endl;
            system("read -p '按任意键退出...' var");
            system("clear");
            return;
        }
    }
}

//老师界面菜单
void TeacherMenu(Identity * &teacher){
    Teacher* tea = (Teacher*) teacher;

    while(true){
        tea->operMenu();
        int select = 0;

        cin >> select;

        if (select == 1)
        {
            //查看所有预约
            tea->showAllOrder();
        }
        else if (select == 2)
        {
            //审核预约
            tea->validOrder();
        }
        else
        {
            delete tea;
            cout << "注销成功" << endl;
            system("read -p '按任意键退出...' var");
            system("clear");
            return;
        }
    }
}
//管理员界面菜单
void managerMenu(Identity* manager){
    //测试&的作用
    //cout << "manager: " << manager << endl;

    //展示菜单 为了调用 manager的子函数 进行强转
    Manager* man = (Manager*)manager;

    while(true){
        man->operMenu();

        //接收使用者的选择
        int select = 0;
        cin >> select;

        if (select == 1)  //添加账号
        {
            cout << "添加账号" << endl;
            man->addPerson();
        }
        else if (select == 2) //查看账号
        {
            cout << "查看账号" << endl;
            man->showPerson();
        }
        else if (select == 3) //查看机房
        {
            cout << "查看机房" << endl;
            man->showComputer();
        }
        else if (select == 4) //清空预约
        {
            cout << "清空预约" << endl;
            man->clearFile();
        }
        else
        {
            //delete manager;
            delete man;
            cout << "注销成功" << endl;
            system("read -p '按任意键退出...' var");
            system("clear");
            return;
        }
    }
}

//登录功能， 文件名， 人员类型
void login(string fileName, int type){

    Identity *person = NULL; //多态，设计到定义父类指针，指向子类对象

    //读入相应文件
    ifstream ifs;
    ifs.open(fileName, ios::in);
    if(!ifs.is_open()){
        cout << "文件不存在" << endl;
        return;
    }

    //让相应用户输入资料
    string name;
    int id;
    string pwd;

    //管理员没有id
    if(type == 1){
        cout << "请输入你的学号" << endl;
        cin >> id;
    }
    else if(type == 2){
        cout << "请输入你的职工号" << endl;
        cin >> id;
    }else{
        //管理员
    }

    cout << "请输入用户名：" << endl;
    cin >> name;

    cout << "请输入密码： " << endl;
    cin >> pwd;

    //对输入进行验证
    if(type == 1){
        //学生登录验证
        string f_name;
        int f_id;
        string f_pwd;

        while(ifs>>f_id && ifs>>f_name && ifs>>f_pwd){
            if(f_id==id && f_name==name && f_pwd==pwd){
                cout << "学生验证登录成功!" << endl;
                system("read -p '按任意键退出...' var");
                system("clear");
                person = new Student(id, name, pwd);
                studentMenu(person);
                return;
            }
        }

        ifs.close();
    }
    else if(type == 2){
        //老师登录验证
        string f_name;
        int f_id;
        string f_pwd;

        while(ifs>>f_id && ifs>>f_name && ifs>>f_pwd){
            if(f_id==id && f_name==name && f_pwd==pwd){
                cout << "老师验证登录成功!" << endl;
                system("read -p '按任意键退出...' var");
                system("clear");
                person = new Teacher(id, name, pwd);
                TeacherMenu(person);
                return;
            }
        }
        ifs.close();
    }else{
        //管理员登录验证
        string f_name;
        string f_pwd;

        while(ifs>>f_name && ifs>>f_pwd){
            if(f_name==name && f_pwd==pwd){
                cout << "管理员验证登录成功!" << endl;
                system("read -p '按任意键退出...' var");
                system("clear");
                person = new Manager(id, name, pwd);
                managerMenu(person);
                return;
            }
        }
        ifs.close();
        ifs.close();
    }

    ifs.close();
    cout << "验证登录失败" << endl;
    system("read -p '按任意键退出...' var");
    system("clear");
}

int main() {

	int select = 0;

	while (true)
	{

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
		    login(STUDENT_FILE, 1);
			break;
		case 2:  //老师身份
            login(TEACHER_FILE, 2);
			break;
		case 3:  //管理员身份
            login(ADMIN_FILE, 3);
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
