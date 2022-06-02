//
// Created by $vf on 2022/5/22.
// Desc:
//

#ifndef CJJCORE_PERSON_H
#define CJJCORE_PERSON_H
using namespace std;
class Person2 {
private:
    string name;
    int age;
public:
    Person2() {
        name = "王子机";
        age = 166;
        cout << "调用了 Person2 的无参构造函数" << endl;
    }

    Person2(int _age, string _name) {
        age = _age;
        name = _name;
        cout << "调用了person 2 的有参构造器" << endl;
    }

    Person2(const Person2 &p) {
        name = p.name;
        age = p.age;
        cout << "调用了 person2 的拷贝构造函数" << endl;
    }

    ~Person2() {
        cout << "调用了 Person2 的析构函数" << endl;

    }

    void setName(string aname) {
        name = aname;
    }

    void setAge(int aage) {
        age = aage;
    }

    void showPerson() {
        cout << "姓名：" << name << " 高龄：" << age << endl;
    }

};

class Person {
private:
    int age;
    int *aint;
public:
    Person(int _age, int _aint) {
        age = _age;
        aint = new int(_aint);
    }

    ~Person() {
        if (aint != nullptr) {
            delete aint;
            aint = nullptr;
        }
    }

    void showPerson() {
        cout << *aint << "现在 " << age << " 高龄" << endl;
    }

    void showIntAddress() {
        cout << &aint << endl;

    }
};


class VOID {

};

class Dog {
    mutable int age;
public:
    Dog(int age) {
        this->age = age;
    }

    Dog() {

    }

    Dog(const Dog &dog) {
        this->age = dog.age;
        cout << "调用了拷贝构造函数！" << endl;

    }

    Dog &addDog(const Dog &dog) {
        this->age += dog.age;
        return *this;
    }

    int getAge() {
        if(this == nullptr){
            return -1;
        }
        return this->age;
    }

    int calculate(int age) const{
        this->age += age;
        cout << this->age << endl;
    }


};

#endif //CJJCORE_PERSON_H
