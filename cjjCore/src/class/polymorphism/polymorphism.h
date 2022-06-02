//
// Created by $vf on 2022/5/30.
// Desc:
//

#ifndef CJJCORE_POLYMORPHISM_H
#define CJJCORE_POLYMORPHISM_H

#include "iostream"
#include "string"

using namespace std;

class Animal {
public:
    virtual void speak() = 0;

    Animal() {
        cout << "animal 的构造函数执行" << endl;
    }

   virtual ~Animal() {
        cout << "Animal 的析构函数执行！" << endl;
    }
};

class Pig : public Animal {
public:
    void speak() override {
        cout << "pig oh oh jiao" << endl;
    }

    Pig(string name) {
        this->name = new string(name);
        cout << *this->name << "pig 的构造函数执行" << endl;
    }
    ~Pig(){
        cout << "pig 的析构函数执行！" << endl;
        if(name != nullptr){
            delete name;
        }
    }
private:
    string *name;
};

class Cat : public Animal {
public:
    void speak() override {
        cout << "cat miao miao" << endl;
    }
};

void doSpeak(Animal &animal) {
    animal.speak();
}


#endif //CJJCORE_POLYMORPHISM_H
