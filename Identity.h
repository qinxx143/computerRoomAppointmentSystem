//
// Created by Yaobin Qin on 2021/5/25.
//

//抽象类(virtual class), 不能给实例化为对象，得有virtual, (=0) 纯虚函数。
//将学生，老师，管理员， 抽象为一个virtual function, 实现polymorphism

#pragma once
#include <iostream>
using namespace std;

class Identity{
public:
    //操作菜单
    virtual void operMenu() = 0;

public:
    //用户名
    string name;
    //密码
    string password;
};
