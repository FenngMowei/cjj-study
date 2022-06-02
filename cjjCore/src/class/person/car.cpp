//
// Created by $vf on 2022/5/28.
// Desc:
//
# include <iostream>
#include <cstring>

using namespace std;

class Car {
private:
    char *brand;
    float price;
public:
//    Car(const char *sz, float p) {
//        //构造函数中为brand分配内存
//        brand = new char[strlen(sz) + 1];
//        strcpy(brand, sz);
//        price = p;
//    }
    Car(const char *sz, float p):price(p){
        brand = new char(strlen(sz) + 1);
        strcpy(brand,sz);
    }
//    Car(const Car & car){
//        brand = new char[strlen(car.brand)];
//        strcpy(brand, car.brand);
//        price = car.price;
//    }
    ~Car() {
        //析构函数中释放申请的内存
        delete[] brand;
        cout << " Clear is over ! " << endl;
    }

    void just_print() {
        cout << "brand : " << brand << endl;
        cout << "price : " << price << endl;
    }
    void showAddress(){
        cout << brand << endl;
    }
};

int main() {
//    Car car_one("BMW", 120);
//    car_one.just_print();
//    //调用默认的拷贝构造函数
//    Car car_two(car_one);
//    car_two.just_print();
//    car_one.showAddress();
//    car_two.showAddress();
//    int a = 10;
//    cout << &a << endl;
//    cout << &car_one << endl;
    char sz[10] = "hhhhhh";
    Car c(sz,9900.44);
    c.just_print();
    return 0;
}