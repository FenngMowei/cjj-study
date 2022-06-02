//
// Created by $vf on 2022/5/30.
// Desc:
//

#ifndef EMP_M_OS_WORKMANAGER_H
#define EMP_M_OS_WORKMANAGER_H

#pragma once  //防止头文件重复包含

#include "iostream"
#include "Boss.h"
#include "Employee.h"
#include "Manager.h"
#include "fstream"
#include "string"

#define FILENAME  "worker.txt"
using namespace std;

class WorkManager {
private:
    bool isFileEmpty;
    int num;
    Worker **pWorkerArray;
public:
    WorkManager();

    ~WorkManager();

    void showMenu();

    void exitSystem();

    void addEmp();

    void save(int begin,ofstream &ofs);

    int getFileNum();

    void fileReadInit();

    void showEmployee();

    /**
     * 根据id 判断一个员工是否存在
     */
    int isExist(int id);

    void deleteEmp();

    void modifyEmp();

    int findEmp();
    int findByName(string name);

    void mergeSort(Worker **pWorker, int left, int right,bool isUp);

    void merge(Worker **pWorker, int left, int right, int mid,bool isUp);

    void sort();

    void destroyEmp();
};


#endif //EMP_M_OS_WORKMANAGER_H
