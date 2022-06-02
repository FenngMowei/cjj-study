//
// Created by $vf on 2022/5/30.
// Desc:
//
#include "WorkManager.h"

int main() {
    WorkManager wm;
    int choice = 0;
    while (true){
        wm.showMenu();
        cout << "请输入你的选择：" << endl;
        while (!(cin >> choice)){
            cin.clear();
            while (cin.get()!= '\n'){
            }
            cout << "请输入一个0~7之间的数：" << endl;
        }
        switch (choice) {
            case 0: //退出循环
                wm.exitSystem();
                exit(0);
            case 1: //增
                wm.addEmp();
                break;
            case 2: //显
                wm.showEmployee();
                break;
            case 3: //删
                wm.deleteEmp();
                break;
            case 4://修
                wm.modifyEmp();
                break;
            case 5: //查
                wm.findEmp();
                break;
            case 6: //排
                wm.sort();
                break;
            case 7: //清
                wm.destroyEmp();
                break;
            default:
                system("cls");
        }
    }

}
