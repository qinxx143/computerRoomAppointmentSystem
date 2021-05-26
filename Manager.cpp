//
// Created by Yaobin Qin on 2021/5/25.
//

#include "Manager.h"
#include <fstream>
#include "globalFile.h"
#include <algorithm>
#include "ComputerRoom.h"

//default constructor
Manager::Manager(){

}

//constructor with parameters
Manager::Manager(int id, string name, string pwd){
    this->name = name;
    this->password = pwd;
    this->init_vector();
}

//menu interface
void Manager::operMenu(){
    cout << "欢迎管理员："<<this->name << "登录！" << endl;
    cout << "\t\t ---------------------------------\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          1.添加账号              |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          2.查看账号              |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          3.查看机房              |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          4.清空预约              |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          0.注销登录              |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t ---------------------------------\n";
    cout << "请选择您的操作： " << endl;
}

//add person
void Manager::addPerson(){

    int select = 0;

    string fileName;
    string tip;
    ofstream ofs;
    string errorTip;
    while(true){
        cout << "请输入添加的类型：" << endl;
        cout << "1. 学生" << endl;
        cout << "2. 老师" << endl;
        cin >> select;
        if(select == 1){
            //输入学生
            fileName = STUDENT_FILE;
            tip = "请输入学号： ";
            errorTip = "errorTip = 学生编号重复，请重新输入：";
            break;
        }
        else if(select == 2){
            //输入老师
            fileName = TEACHER_FILE;
            tip = "请输入职工编号：";
            errorTip = "errorTip = 老师编号重复，请重新输入：";
            break;
        }
        else{
            cout << endl;
            cout << "输入错误，重新输入：" << endl;
        }
    }

    int id;
    string name;
    string pwd1 = "0";
    string pwd2 = "1";

    cout << tip <<endl;

    //根据编号查重
    while(true){
        //查重
        cin >> id;
        if(select == 1){
            cout << "输入的id为: " << id << endl;
            Student temp(id, name, pwd1);
            vector<Student>::iterator ret = find(this->v_student.begin(),this->v_student.end(), temp);
            if(ret == this->v_student.end()){
                cout << "没有重复！" <<endl;
                break;
            }
        }
        else if(select == 2){
            Teacher temp(id, name, pwd1);
            vector<Teacher>::iterator ret = find(this->v_teacher.begin(),this->v_teacher.end(), temp);
            if(ret == this->v_teacher.end()){
                break;
            }
        }
        cout << errorTip << endl;
    }

    cout << "请输入你的名字：" << endl;
    cin >> name;

    while(pwd1 != pwd2){
        cout << "请设置你的密码：" << endl;
        cin >> pwd1;

        cout << "请再输入你的密码：" << endl;
        cin >> pwd2;

        if(pwd1 != pwd2){
            cout << endl;
            cout << "密码不匹配，请重新输入：" << endl;
        }
    }


    ofs.open(fileName, ios::out|ios::app);
    ofs << id << " " << name << " " << pwd1 << " " << endl;
    cout << "添加成功" << endl;
    system("read -p '按任意键退出...' var");
    system("clear");
    ofs.close();

    //加了person,之后，马上初始化，将容器更新
    this->init_vector();
}

//printPerson
void printStudent(Student &s){
    cout << "学号： " << s.id << " 姓名： " << s.name << " 密码：" << s.password << endl;
}

void printTeacher(Teacher & t)
{
    cout << "职工号： " << t.empId << " 姓名： " << t.name << " 密码：" << t.password << endl;
}

//show person
void Manager::showPerson(){
    cout << "请选择查看内容：" << endl;
    cout << "1、查看所有学生" << endl;
    cout << "2、查看所有老师" << endl;
    int select = 0;
    cin >> select;

    if(select == 1){
        //学生
        cout << "所有学生信息如下： " << endl;
        for_each(this->v_student.begin(),this->v_student.end(),printStudent);

    }
    else if(select == 2){
        //老师
        cout << "所有老师信息如下： " << endl;
        for_each(this->v_teacher.begin(),this->v_teacher.end(), printTeacher);
    }
    system("read -p '按任意键退出...' var");
    system("clear");
}


//print computer room
void printComputerRoom(ComputerRoom &c){
    cout << "机房编号： " << c.computerId << " 机房最大容量： " << c.max_size << endl;
}

//show computer
void Manager::showComputer(){
    cout << "机房信息如下： " << endl;
    for_each(this->v_computerRoom.begin(),this->v_computerRoom.end(), printComputerRoom);
    system("read -p '按任意键退出...' var");
    system("clear");
}

//clear file
void Manager::clearFile(){
    ofstream ofs;
    ofs.open(ORDER_FILE, ios::out|ios::trunc);

    cout << "清空成功！" << endl;
    system("read -p '按任意键退出...' var");
    system("clear");
}

void Manager::init_vector(){
    //清空容器
    this->v_student.clear();
    this->v_teacher.clear();
    this->v_computerRoom.clear();

    //将学生和老师的数据读到vector中
    //student
    ifstream ifs;
    ifs.open(STUDENT_FILE, ios::in);

    if (!ifs.is_open())
    {
        cout << "文件读取失败" << endl;
        return;
    }

    Student s;
    while (ifs >> s.id && ifs >> s.name &&  ifs >> s.password)
    {
        this->v_student.push_back(s);
    }
    cout << "当前学生数量为： " << v_student.size() << endl;
    ifs.close(); //学生初始化

    //teacher
    ifs.open(TEACHER_FILE, ios::in);

    if (!ifs.is_open())
    {
        cout << "文件读取失败" << endl;
        return;
    }

    Teacher t;
    while (ifs >> t.empId && ifs >> t.name &&  ifs >> t.password)
    {
        this->v_teacher.push_back(t);
    }
    cout << "当前老师数量为： " << this->v_teacher.size() << endl;
    ifs.close(); //学生初始化

    //computer room
    ifs.open(COMPUTER_FILE, ios::in);

    if (!ifs.is_open())
    {
        cout << "文件读取失败" << endl;
        return;
    }

    ComputerRoom c;
    while (ifs >> c.computerId && ifs >> c.max_size)
    {
        this->v_computerRoom.push_back(c);
    }
    cout << "当前电脑数量： " << this->v_computerRoom.size() << endl;
    ifs.close();


}