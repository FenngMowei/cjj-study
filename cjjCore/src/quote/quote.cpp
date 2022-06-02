//
// Created by $vf on 2022/5/21.
// Desc: 学习引用
//
#include "iostream"

using namespace std;

int main() {
    //1.引用定义
    int a = 10;
    int &b = a;
    cout << &a << "  :  " << a << endl;
    cout << &b << "  :  " << b << endl;
    int c = 100;
    b = c; //相当于赋值操作
    cout << &a << "  :  " << a << endl;
    cout << &b << "  :  " << b << endl;
    cout << &c << "  :  " << c << endl;

    //2.引用作为函数参数
    void swap1(int &a, int &b);
    int p1 = 100;
    int p2 = 100000;
    swap1(p1, p2); //自动创建引用作为中间
    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;

    //3.引用作为函数值返回
    //不要返回局部变量的引用
    int & r_q();
    int ref = r_q();
    cout << ref << endl;
    r_q() = 10000000;  //修改了定义的全局变量a
    ref = r_q();
    cout << ref << endl;

    //4，引用的本质
    int nn1 = 100;
    int & qq1 = nn1; //qq1 还是地址
    int * const pp1 = & qq1;
    cout << pp1 << endl;
    cout << qq1 << endl; //它会自动解引用

    //5.常量引用
    const int & ref2 = 100;
    //编译器帮助完成工作，int temp = 100; const int & ref2 = temp;
    //常用来修饰形参，防止误操作
    void showValue(const int & a);
    int value = 10000;
    showValue(value);
}

void swap1(int &a, int &b) {
    if (a == b)
        return;
    a = a ^ b;
    b = b ^ a;
    a = a ^ b;
}

int& r_q(){
    static int a = 100;
    return a;
}
void showValue(const int & a){
//    a = 100; //修改操作
    cout << a << endl;

}