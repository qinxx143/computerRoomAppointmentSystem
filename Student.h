//
// Created by Yaobin Qin on 2021/5/25.
//

#pragma once
#include <iostream>
#include "Identity.h"
#include "ComputerRoom.h"
#include <vector>
using namespace std;


class Student:public Identity{
public:
    //default constructor
    Student();

    //constructor with parameters
    Student(int id, string name, string pwd);

    void init_computerRoom_vector();

    //重载==
    bool operator==(const Student &student);

    //menu interface
    void operMenu();

    //apply order
    void applyOrder();

    //show my order
    void showOrder();

    //show all order
    void showAllOrder();

    //cancel order
    void cancelOrder();

public:
    //student ID
    int id;
    vector<ComputerRoom> v_computerRoom;
};
