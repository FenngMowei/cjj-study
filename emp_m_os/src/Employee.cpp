//
// Created by $vf on 2022/5/31.
// Desc:
//

#include "Employee.h"
void Employee::showInfo() {
    cout << "ְ����ţ� " << this->id
         << " \tְ�������� " << this->name
         << " \t��λ��" << this->getDeptName()
         << " \t��λְ����ɾ�����������" << endl;
}

string Employee::getDeptName() {
    return string("Ա��");
}

Employee::Employee(int id, string name, int did) : Worker(id, name, did) {
    this->did = did;
    this->name = name;
    this->id = id;
}
