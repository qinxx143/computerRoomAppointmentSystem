//
// Created by Yaobin Qin on 2021/5/25.
//

#pragma once
#include <iostream>
#include "Identity.h"

using namespace std;


class Teacher:public Identity{
public:
//default constructor
Teacher();

//constructor with parameters
Teacher(int empId, string name, string pwd);

//重载==
bool operator==(const Teacher &teacher);

//menu interface
virtual void operMenu();

//show all order
void showAllOrder();

//valid order
void validOrder();

public:
//Emp ID
int empId;

};

