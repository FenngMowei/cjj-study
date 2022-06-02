//
// Created by $vf on 2022/5/30.
// Desc:
//

#ifndef CJJCORE_FILE_H
#define CJJCORE_FILE_H
#include "iostream"
#include <fstream>
#include "cstring"
using namespace std;

void fileOperate1() {
    ofstream ofs;
    ofs.open(R"(C:\Users\33863\Desktop\haha.txt)", ios::out);
    ofs << "你是哈哈哈" << endl;
    ofs << "第二段" << endl;
    ofs << "第三段" << endl;
    ofs.close();
}

void readFile(){
    ifstream ifs;
    ifs.open(R"(C:\Users\33863\Desktop\haha.txt)", ios::in);
    if(!ifs.is_open()){
        cout << "打开文件失败！" <<endl;
        return;
    }
    //方式一
//    char buf[1024] = {0}; //数组全部初始化为0
//    while (ifs >> buf){
//        cout << buf << endl;
//    }

//    char buf[1024] = {0};
//    while (ifs.getline(buf,sizeof(buf))){
//        cout << buf << endl;
//
//    }

//    string buf;
//    while (getline(ifs,buf)){
//        cout <<buf << endl;
//
//    }
    //第四种，不推荐使用
    char c;
    while ((c=ifs.get()) != EOF){
        cout << c;
    }
    ifs.close();
}
class Person{
    friend ostream & operator<<(ostream &out, Person &p);
private:
    char name[64];
    int age;
public:
    Person() = default;
    Person(const char * name, int age){
        strcpy(this->name,name);
        this->age = age;
    }

};


ostream &operator<<(ostream &out, Person &p) {
    out <<"姓名： "<<p.name << "   年龄： "<< p.age;
    return out;
}

void biWrite(){
    ofstream ofs(R"(C:\Users\33863\Desktop\haha.txt)", ios::out|ios::binary);
    Person p("李二",18);
    cout << p << endl;
    ofs.write((const char *)&p,sizeof(p));
    ofs.close();
}


void biRead(){
    ifstream ifs(R"(C:\Users\33863\Desktop\haha.txt)", ios::in|ios::binary);
    if(!ifs.is_open()){
        cout << "打开文件失败！" <<endl;
        return;
    }
    Person p;
    ifs.read((char *)&p,sizeof(p));
    cout << p << endl;
    ifs.close();
}
//
#endif //CJJCORE_FILE_H
