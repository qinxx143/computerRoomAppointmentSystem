//
// Created by Yaobin Qin on 2021/5/25.
//

#include "Teacher.h"
#include "OrderFile.h"
#include <vector>

Teacher::Teacher(){

};

//constructor with parameters
Teacher::Teacher(int id, string name, string pwd){
    this->empId = id;
    this->name = name;
    this->password = pwd;
}

//重载==
bool Teacher::operator==(const Teacher &teacher){
    if(this->empId != teacher.empId){
        return false;
    }
    return true;
}

//menu interface
void Teacher::operMenu(){
    cout << "欢迎教师：" << this->name << "登录！" << endl;
    cout << "\t\t ----------------------------------\n";
    cout << "\t\t|                                  |\n";
    cout << "\t\t|          1.查看所有预约            |\n";
    cout << "\t\t|                                  |\n";
    cout << "\t\t|          2.审核预约                |\n";
    cout << "\t\t|                                  |\n";
    cout << "\t\t|          0.注销登录                |\n";
    cout << "\t\t|                                  |\n";
    cout << "\t\t ----------------------------------\n";
    cout << "请选择您的操作： " << endl;

};

//show all order
void Teacher::showAllOrder(){
    OrderFile of;
    if(of.size==0){
        cout << "您没有预约记录" << endl;
        system("read -p '按任意键退出...' var");
        system("clear");
        return;
    }

    cout << "所有的预约记录如下：" << endl;
    for(int i=0; i<of.size;i++){
        cout << i+1 << "：";
        cout << "姓名：" << of.orderData[i]["stuName"] << " ";
        cout << "日期：" << of.orderData[i]["date"] << " ";
        cout << "时段：" << (of.orderData[i]["interval"] == "1" ? "上午":"下午") << " ";
        cout << "机房：" << of.orderData[i]["roomId"] << " ";
        string status = "状态："; // 0 取消的预约   1 审核中   2 已预约 -1 预约失败
        if(of.orderData[i]["status"] == "1"){
            status += "审核中";
        }
        else if(of.orderData[i]["status"] == "2"){
            status += "已预约";
        }
        else if(of.orderData[i]["status"] == "-1"){
            status += "预约失败";
        }else{
            status += "取消的预约";
        }
        cout << status;
        cout << endl;

    }
    system("read -p '按任意键退出...' var");
    system("clear");
};

//valid order
void Teacher::validOrder(){
    OrderFile of;
    if(of.size==0){
        cout << "您没有预约记录" << endl;
        system("read -p '按任意键退出...' var");
        system("clear");
        return;
    }

    vector<int> valid_num;
    cout << "审核状态中的预约记录如下：" << endl;
    for(int i=0; i<of.size;i++){
        if(of.orderData[i]["status"] == "1"){
            valid_num.push_back(i);
            cout << "编号：" << i << " ";
            cout << "姓名：" << of.orderData[i]["stuName"] << " ";
            cout << "日期：" << of.orderData[i]["date"] << " ";
            cout << "时段：" << (of.orderData[i]["interval"] == "1" ? "上午":"下午") << " ";
            cout << "机房：" << of.orderData[i]["roomId"] << " ";
            string status = "状态："; // 0 取消的预约   1 审核中   2 已预约 -1 预约失败
            if(of.orderData[i]["status"] == "1"){
                status += "审核中";
            }
            else if(of.orderData[i]["status"] == "2"){
                status += "已预约";
            }
            else if(of.orderData[i]["status"] == "-1"){
                status += "预约失败";
            }else{
                status += "取消的预约";
            }
            cout << status;
            cout << endl;
        }
    }

    cout << endl;
    cout << "请输入需要审核的预约编号：";
    int my_num = 0;
    int pass = 0;
    cin >> my_num;
    vector<int>::iterator ret = find(valid_num.begin(),valid_num.end(),my_num);
    if(ret != valid_num.end()){
        cout << "请输入审核结果" << endl;
        cout << "1、通过" << endl;
        cout << "2、不通过" << endl;
        cin >> pass;
        if(pass == 1){
            of.orderData[my_num]["status"] = "2";
            of.updateOrder();
            cout << "审核完毕" << endl;
        }else{
            of.orderData[my_num]["status"] = "-1";
            of.updateOrder();
            cout << "审核完毕" << endl;
        }
    }else{
        cout << "输入编号不存在" << endl;
    }
    system("read -p '按任意键退出...' var");
    system("clear");

};