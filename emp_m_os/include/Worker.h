//
// Created by $vf on 2022/5/31.
// Desc:
//

#ifndef EMP_M_OS_WORK_H
#define EMP_M_OS_WORK_H
#pragma once
#include "iostream"
#include "string"
using namespace std;
class Worker{
public:
    int id;
    string name;
    int did;
public:
    Worker(int id, string name, int did):id(id), name(name),did(did){

    }
    virtual void showInfo() = 0;
    virtual string getDeptName() = 0;

};
#endif //EMP_M_OS_WORK_H
