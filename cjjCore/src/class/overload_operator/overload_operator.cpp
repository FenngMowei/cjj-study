//
// Created by $vf on 2022/5/29.
// Desc:
//

#include "overload_operator.h"


int main() {
    //1.
//    Person person(10, "李二");
//    Person person1(40, "李父");
//    Person person2 = person + person1; //相当于 person.operator+(person1);
//    Person person3 = person + 100;
//    cout << person2 << endl;
//    Person person4 = person + person1; //可以选择友元函数，也可以

    //2.测试加加运算符重载
//    MyInt myInt(100);
//    cout << myInt++ << endl;
//    cout << myInt << endl;
//    cout << ++myInt << endl;
//    cout << myInt << endl;

    //3.测试赋值运算符重载
//    Dog dog = 100;
//    Dog dog1 = 200;
//    cout << dog << endl;
//    dog = dog1;
//    cout << dog1 << endl;
//    cout << dog << endl;

    //4.测试关系运算符重载
    Cat c1("二哈",4);
    Cat c2("二哈",4);
    if(c1 == c2){
        cout << "二者相等" << endl;
    } else{
        cout << "不等" << endl;
    }

    //5.测试函数调用运算符重载
    Pig()("王子性价柑橘感觉");


}