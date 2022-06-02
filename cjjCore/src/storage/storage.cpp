//
// Created by $vf on 2022/5/21.
// Desc:测试存储
//
#include "iostream"

using namespace std;
int global_a = 100;
int global_b= 100;
const int c_g_a = 100;
int main(){
    int j_a = 100;
    cout << "j_a = " << &j_a << endl;

    //1.静态变量和全局变量存储在全局区
    static int s_a = 100;
    cout << "静态变量a的地址： " << &s_a <<endl;
    cout << "全局变量的global_a的地址：" << &global_a <<endl;
    cout << "全局变量的global_a的地址：" << &global_b <<endl;

    //2.常量
    const int c_j_a = 100;
    cout << "c_j_a " << &c_j_a<< endl;
    cout << "c_g_a " << &c_g_a<< endl;
    
    //3.字符串的存储方式
    string s_1 = "字符串！"; //局部
    cout << &s_1 << endl;
    char s2[] = "字符串"; //局部
    cout << &s2 << endl;
    char * s3 = "字符串！";
    cout << (int*)s3 << endl; //全局

    //4.堆区开辟内存
    int * p = new int(1);
    int * p_arr = new int[4];

    cout << p << endl;
    cout << *p << endl;
    p_arr[1] = 100;
    p_arr[2] = 101;
    p_arr[3] = 102;
    p_arr[4] = 103;
    
    

}

