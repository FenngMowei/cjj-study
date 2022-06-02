//
// Created by $vf on 2022/5/31.
// Desc:
//

#include "Boss.h"
void Boss::showInfo() {
    cout << "职工编号： " << this->id
         << " \t职工姓名： " << this->name
         << " \t岗位：" << this->getDeptName()
         << " \t岗位职责：管理公司所有事务" << endl;

}

string Boss::getDeptName() {
    return string("老板");
}

Boss::Boss(int id, string name, int did) : Worker(id, name, did) {
    this->did = did;
    this->name = name;
    this->id = id;
}