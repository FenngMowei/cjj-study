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
        cout << "���������ѡ��" << endl;
        while (!(cin >> choice)){
            cin.clear();
            while (cin.get()!= '\n'){
            }
            cout << "������һ��0~7֮�������" << endl;
        }
        switch (choice) {
            case 0: //�˳�ѭ��
                wm.exitSystem();
                exit(0);
            case 1: //��
                wm.addEmp();
                break;
            case 2: //��
                wm.showEmployee();
                break;
            case 3: //ɾ
                wm.deleteEmp();
                break;
            case 4://��
                wm.modifyEmp();
                break;
            case 5: //��
                wm.findEmp();
                break;
            case 6: //��
                wm.sort();
                break;
            case 7: //��
                wm.destroyEmp();
                break;
            default:
                system("cls");
        }
    }

}
