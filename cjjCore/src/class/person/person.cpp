//
// Created by $vf on 2022/5/22.
// Desc:
//



#include "iostream"
#include "person.h"

using namespace std;


void test1(Person2 p) { //不是引用，会自动使用拷贝构造一个p对象,在堆中
    cout << "p的地址是： " << (int *) &p << endl;
    p.showPerson();
}

Person2 test2() {
    Person2 p(199, "王子精");
    cout << "p的地址是： " << (int *) &p << endl;
    return p;
}

int main() {
//    Person2 person;
//    person.setAge(100);
//    person.setName("老王已经死了！");
//    person.showPerson();
//    Person2 p1;
//    Person2 p2(100,"王子精");
//    Person2 p3(p2);

//    Person2 p1 = Person2();
//    Person2 p2 = Person2(100,"王凯掏");
//    Person2 p3 = Person2(p2);
//    p2.showPerson();
//    p3.showPerson();

//    Person2 p;
//    Person2 p1 = {133,"老王"};
////    Person2 p2 = p1;
//    cout << "p1的地址是： " << (int*)&p1 << endl;
//    test1(p1);

//    Person2 p1 = test2();
//    p1.showPerson();
//    cout << "p1的地址是： " << (int *) &p1 << endl;


//    Person p(100,123);
//    p.showPerson();
//    p.showIntAddress();
//    Person p2(p);
//    p2.showIntAddress();
//    p2.showPerson();

//    VOID aVoid;
//    cout << "size of avoid = " << sizeof (aVoid) << endl;

    Dog dog(10);
    Dog dog1;
    dog1 = dog.addDog(dog).addDog(dog);
    cout << "dog 的内存地址：" << &dog << endl;
    cout << "dog1 的内存地址：" << &dog1 << endl;
    cout << dog1.getAge() << endl;

    Dog * p = nullptr;
    cout << p->getAge() << endl;
}
