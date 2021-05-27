//
// Created by Yaobin Qin on 2021/5/26.
//

#include "MenuInterface.h"

MenuInterface::MenuInterface(){

}

void MenuInterface::studentMenu(Identity* student){
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

void MenuInterface::TeacherMenu(Identity * &teacher){
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

void MenuInterface::managerMenu(Identity* manager){
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

void MenuInterface::login(string fileName, int type){
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