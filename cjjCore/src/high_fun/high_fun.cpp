//
// Created by $vf on 2022/5/21.
// Desc:学习函数的高级用法
//

#include "iostream"

using namespace std;

int f_sum(int a, int b = 10, int c = 10);

void f_occupy(int a, int, int);



int ff(int a, int b = 10, int c = 100) {
    cout << a + b + c << endl;
    return a + b + c;
}

int main() {
    //1. 函数默认参数
    cout << f_sum(10) << endl;
    cout << f_sum(10, 20) << endl;
    //2.占位参数
    void f_occupy(int a, int, int = 100);
    f_occupy(100, 10100);
    ff(100, 100, 100);
    //3.函数重载
    void f_t(int &a); //只能接收变量
    void f_t(const int &a); //只能接收常量
    f_t(10);
    int value  = 100;
    f_t(value);


}

int f_sum(int a, int b, int c) {
    return a + b + c;
}

void f_occupy(int a, int, int) {
    cout << a << endl;
}

void f_t(int &a) {
    cout << "void f_t(int & a) " << a << endl;
}

void f_t(const int &a) {
    cout << "void f_t( const int & a) " << a << endl;
}

