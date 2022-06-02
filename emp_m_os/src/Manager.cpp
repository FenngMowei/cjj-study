//
// Created by $vf on 2022/5/31.
// Desc:
//

#include "Manager.h"
void Manager::showInfo() {
    cout << "职工编号： " << this->id
         << " \t职工姓名： " << this->name
         << " \t岗位：" << this->getDeptName()
         << " \t岗位职责：完成老板交给的任务,并下发任务给员工" << endl;

}

string Manager::getDeptName() {
    return string("经理");
}

Manager::Manager(int id, string name, int did) : Worker(id, name, did) {
    this->did = did;
    this->name = name;
    this->id = id;
}