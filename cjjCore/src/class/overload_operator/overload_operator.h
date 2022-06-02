//
// Created by $vf on 2022/5/29.
// Desc:
//

#ifndef CJJCORE_OVERLOAD_OPERATOR_H
#define CJJCORE_OVERLOAD_OPERATOR_H

#include <utility>

#include "string"
#include "iostream"

using namespace std;

class Person;

Person operator+(const Person &person, const Person &person1);

class Person {
    friend Person operator+(const Person &person, const Person &person1);

    friend ostream &operator<<(ostream &cout, const Person &p);

private:
    int age;
    string name;
public:
    Person() = default;

    Person(int age, const string &name) : age(age) {
        this->name = name;
    }

    Person operator+(const Person &person) {
        cout << "执行了成员函数 运算符重载" << endl;
        Person temp;
        temp.age = this->age + person.age;
        temp.name = this->name + person.name;
        return temp;
    }

    Person operator+(int val) { //左操作数默认自己 //只能接受一个形参
        Person temp;
        temp.age = this->age + val;
        temp.name = this->name;
        return temp;
    }

//    ostream &operator<<(ostream &out) { // 只能这样调用person2 << cout，期望cout在左侧
//        out << "姓名： " << name << "年龄： " << age;
//        return out;
//    }
};

Person operator+(const Person &person, const Person &person1) { //友元函数运算符重载
    cout << "执行了友元函数 运算符重载" << endl;
    Person temp;
    temp.age = person.age + person1.age;
    temp.name = person.name + person1.name;
    return temp;
}

ostream &operator<<(ostream &cout, const Person &p) {
    cout << "姓名： " << p.name << "年龄： " << p.age;
    return cout;
}

class MyInt {
    friend ostream &operator<<(ostream &out, const MyInt &myInt);

private:
    int mInt;
public:
    MyInt() = default;

    explicit MyInt(int mInt) : mInt(mInt) {
    }

    /**
     * 前置递增运算符
     * @return
     */
    MyInt &operator++() {
        this->mInt++;
        return *this;
    }

    MyInt operator++(int) { //使用占位符占位， int是由++规定的
        MyInt temp = *this;
        this->mInt++;
        return temp;
    }
};

ostream &operator<<(ostream &out, const MyInt &myInt) {
    out << myInt.mInt;
    return out;
}

class Dog {
    friend ostream &operator<<(ostream &out, const Dog &dog);

private:
    int *p_age;
public:
    Dog(int age) {
        p_age = new int(age);
    }

    ~Dog() {
        if (p_age != nullptr) {
            delete p_age;
            p_age = nullptr;
        }
    }

    Dog &operator=(const Dog &dog) {
        if (p_age == nullptr) {
            p_age = new int(*dog.p_age);
            return *this;
        }
        *p_age = *dog.p_age;
        return *this;
    }
};

ostream &operator<<(ostream &out, const Dog &dog) {
    out << dog.p_age;
    return out;
}

class Cat {
private:
    string name;
    int age;
public:
    Cat(string name, int age) : name(name), age(age) {

    }
    bool operator==(const Cat &cat) {
        if(cat.age == age && cat.name == name){
            return true;
        }
        return false;
    }
};

class Pig{
public:
    void operator()(string str){ //很灵活，不限参数
        cout << str << endl;
    }
};

#endif //CJJCORE_OVERLOAD_OPERATOR_H
