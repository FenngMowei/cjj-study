//
// Created by $vf on 2022/5/31.
// Desc:
//

#include "Boss.h"
void Boss::showInfo() {
    cout << "ְ����ţ� " << this->id
         << " \tְ�������� " << this->name
         << " \t��λ��" << this->getDeptName()
         << " \t��λְ�𣺹���˾��������" << endl;

}

string Boss::getDeptName() {
    return string("�ϰ�");
}

Boss::Boss(int id, string name, int did) : Worker(id, name, did) {
    this->did = did;
    this->name = name;
    this->id = id;
}