//
// Created by $vf on 2022/5/31.
// Desc:
//

#include "Manager.h"
void Manager::showInfo() {
    cout << "ְ����ţ� " << this->id
         << " \tְ�������� " << this->name
         << " \t��λ��" << this->getDeptName()
         << " \t��λְ������ϰ彻��������,���·������Ա��" << endl;

}

string Manager::getDeptName() {
    return string("����");
}

Manager::Manager(int id, string name, int did) : Worker(id, name, did) {
    this->did = did;
    this->name = name;
    this->id = id;
}