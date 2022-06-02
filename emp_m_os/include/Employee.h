//
// Created by $vf on 2022/5/31.
// Desc:
//

#ifndef EMP_M_OS_EMPLOYEE_H
#define EMP_M_OS_EMPLOYEE_H
#pragma once
#include "Worker.h"
class Employee: public Worker{
public:
    Employee(int id,string name,int did);

    virtual void showInfo() override;

    virtual string getDeptName() override;
};
#endif //EMP_M_OS_EMPLOYEE_H
