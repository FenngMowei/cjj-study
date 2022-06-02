//
// Created by $vf on 2022/5/30.
// Desc:
//

#include "polymorphism.h"

int main() {
//    Cat cat;
//    doSpeak(cat);
//    int d = 100;
//    int *s = &d;
//    cout << "size of double * s= " << sizeof(s) << endl;
//    cout << "size of animal = " << sizeof(Animal) << endl;
//    cout << "size of cat = " << sizeof(Cat) << endl;
    Animal * animal = new Pig("佩奇");
    delete animal;
}