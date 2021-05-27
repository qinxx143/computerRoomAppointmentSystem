//
// Created by Yaobin Qin on 2021/5/26.
//

#pragma once
#include <iostream>
#include <fstream>
#include "globalFile.h"
#include "Identity.h"
#include "Student.h"
#include "Teacher.h"
#include "Manager.h"

class MenuInterface{
public:
    MenuInterface();

    void studentMenu(Identity* student);

    void TeacherMenu(Identity * &teacher);

    void managerMenu(Identity* manager);

    void login(string fileName, int type);
};