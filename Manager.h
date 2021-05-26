//
// Created by Yaobin Qin on 2021/5/25.
//

#pragma once
#include <iostream>
#include "Identity.h"
#include <vector>
#include "Student.h"
#include "Teacher.h"
#include "ComputerRoom.h"

using namespace std;


class Manager:public Identity{
public:
    //default constructor
    Manager();

    //constructor with parameters
    Manager(int id, string name, string pwd);

    //menu interface
    virtual void operMenu();

    //add person
    void addPerson();

    //show person
    void showPerson();

    //show computer
    void showComputer();

    //clear file
    void clearFile();

    //为了去重
    void init_vector();

    vector<Teacher> v_teacher;
    vector<Student> v_student;

    //机房
    vector<ComputerRoom> v_computerRoom;

};
