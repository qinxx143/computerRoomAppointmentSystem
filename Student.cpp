//
// Created by Yaobin Qin on 2021/5/25.
//

#include "Student.h"
#include <fstream>
#include "globalFile.h"
#include "ComputerRoom.h"
#include "OrderFile.h"
Student::Student(){

};

//constructor with parameters
Student::Student(int id, string name, string pwd){
    this->id = id;
    this->name = name;
    this->password = pwd;
    this->init_computerRoom_vector();
}

void Student::init_computerRoom_vector(){
    this->v_computerRoom.clear();

    ifstream ifs;
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

//重载==
bool Student::operator==(const Student &student){
    if(this->id == student.id){
        return true;
    }
    return false;
}

//menu interface
void Student::operMenu(){
    cout << "欢迎学生代表：" << this->name << "登录！" << endl;
    cout << "\t\t ----------------------------------\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          1.申请预约              |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          2.查看我的预约          |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          3.查看所有预约          |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          4.取消预约              |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          0.注销登录              |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t ----------------------------------\n";
    cout << "请选择您的操作： " << endl;
};

//apply order
void Student::applyOrder(){
    int date = 0;
    int interval = 0;
    int room = 0;

    //预约日期
    cout << "机房开放时间为周一至周五！" << endl;
    cout << "请输入申请预约的时间：" << endl;
    cout << "1、周一" << endl;
    cout << "2、周二" << endl;
    cout << "3、周三" << endl;
    cout << "4、周四" << endl;
    cout << "5、周五" << endl;
    while(true){
        cin >> date;
        if(date>0 && date<6){
            break;
        }
        cout << "输入错误，请重新输入" << endl;
    }

    //预约interval
    cout << "请输入申请预约的时间段：" << endl;
    cout << "1、上午" << endl;
    cout << "2、下午" << endl;
    while(true){
        cin >> interval;
        if(interval>0 && interval<3){
            break;
        }
        cout << "输入错误，请重新输入" << endl;
    }

    //预约room
    cout << "请选择机房：" << endl;
    for(int i=0; i<this->v_computerRoom.size(); i++){
        cout << i+1 <<"号机房容量：" << v_computerRoom[i].max_size << endl;
    }
    while(true){
        cin >> room;
        if(room>0 && room<4){
            break;
        }
        cout << "输入错误，请重新输入" << endl;
    }
    cout << "预约成功！审核中" << endl;

    ofstream ofs(ORDER_FILE, ios::app);
    ofs << "date:" << date << " ";
    ofs << "interval:" << interval << " ";
    ofs << "stuId:" << this->id << " ";
    ofs << "stuName:" << this->name << " ";
    ofs << "roomId:" << room << " ";
    ofs << "status:" << 1 << endl;

    ofs.close();
    system("read -p '按任意键退出...' var");
    system("clear");
};

//show my order
void Student::showOrder(){

};

//show all order
void Student::showAllOrder(){
    OrderFile of;
};

//cancel order
void Student::cancelOrder(){

};