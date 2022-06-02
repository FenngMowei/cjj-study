//
// Created by $vf on 2022/5/29.
// Desc:
//

#ifndef CJJCORE_FRIEND_H
#define CJJCORE_FRIEND_H

#include "iostream"
#include "string"

using namespace std;

class Person;

class AnotherFriend;

class Friend {
private:
    Person *person;
public:
    Friend();

    void visit();

    void see();
};

class Person {
    friend AnotherFriend;

    friend void friendLyFun(Person *p);

    friend void Friend::visit();

private:
    string room;
public:
    int num;

    Person() = default; //c++11 默认构造函数
    explicit Person(const string &room) {
        this->room = room;
    }

    explicit Person(const string &room, int num) {
        this->room = room;
        this->num = num;
    }
};

void friendLyFun(Person *p) {
    cout << p->room << endl;
}

Friend::Friend() {
    this->person = new Person("卧室", 101);
}

void Friend::visit() {
    cout << "visit person's house" << person->num << endl;
    cout << "visit person's house" << person->room << endl;
}

void Friend::see() {
    cout << "see some person" << endl;
    cout << "visit person's house" << person->num << endl;
//    cout << "visit person's house"<< person->room << endl;
}

class AnotherFriend {
private:
    Person *person;
public:
    AnotherFriend() {
        this->person = new Person("大卧室", 143);
    }
    void visit() {
        cout << person->room << "门牌号：" << person->num << endl;
    }
};


#endif //CJJCORE_FRIEND_H
