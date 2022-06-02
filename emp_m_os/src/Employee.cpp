//
// Created by $vf on 2022/5/31.
// Desc:
//

#include "Employee.h"
void Employee::showInfo() {
    cout << "职工编号： " << this->id
         << " \t职工姓名： " << this->name
         << " \t岗位：" << this->getDeptName()
         << " \t岗位职责：完成经理交给的任务" << endl;
}

string Employee::getDeptName() {
    return string("员工");
}

Employee::Employee(int id, string name, int did) : Worker(id, name, did) {
    this->did = did;
    this->name = name;
    this->id = id;
}
