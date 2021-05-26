//
// Created by Yaobin Qin on 2021/5/25.
//

#include "Teacher.h"
#include "OrderFile.h"

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

};

//show all order
void Teacher::showAllOrder(){
};

//valid order
void Teacher::validOrder(){

};