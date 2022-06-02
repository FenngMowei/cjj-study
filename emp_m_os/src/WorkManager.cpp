//
// Created by $vf on 2022/5/31.
// Desc:
//
#include "WorkManager.h"

void WorkManager::exitSystem() {
    cout << "退出系统！" << endl;
    system("pause");
    exit(0);
}


WorkManager::WorkManager() {
    this->num = 0;
    this->pWorkerArray = nullptr;
    this->isFileEmpty = true;
    ifstream ifs(FILENAME, ios::in);
    if (!ifs.is_open()) {
        cout << "文件不存在!" << endl;
        ifs.close();
        return;
    }
    //定义ch的作用？
    char ch;
    ifs >> ch; //将文件标识符定义到文件尾
    if (ifs.eof()) { //eof()函数是根据文件状态标识来判断当前是否到了文件尾
        cout << "文件为空!" << endl;
        ifs.close();
        return;
    }
    //3、文件存在
    //读文件，初始化
    //1.获取文件中人的个数
    this->num = getFileNum();
    this->pWorkerArray = new Worker *[this->num];
    //2.调用读文件的函数
    fileReadInit();
    this->isFileEmpty = false;
    ifs.close();
}

WorkManager::~WorkManager() {
    delete pWorkerArray;
}

void WorkManager::showMenu() {
    cout << "********************************************" << endl;
    cout << "*********  欢迎使用职工管理系统！ **********" << endl;
    cout << "*************  0.退出管理程序  *************" << endl;
    cout << "*************  1.增加职工信息  *************" << endl;
    cout << "*************  2.显示职工信息  *************" << endl;
    cout << "*************  3.删除离职职工  *************" << endl;
    cout << "*************  4.修改职工信息  *************" << endl;
    cout << "*************  5.查找职工信息  *************" << endl;
    cout << "*************  6.按照编号排序  *************" << endl;
    cout << "*************  7.清空所有文档  *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}

void WorkManager::addEmp() {
    int addNum = 0;
    cout << "请输出新增员工人数：" << endl;
    while (!(cin >> addNum)) {
        cin.clear();
        while (cin.get() != '\n') {
        }
        cout << "请输入一个数字: ";
    }
    if (addNum > 0) {
        int newSize = num + addNum;
        Worker **newArr = new Worker *[newSize];
        if (pWorkerArray != nullptr) {
            //将原来的空间的内存放到现在的空间下
            for (int i = 0; i < num; ++i) {
                newArr[i] = pWorkerArray[i];
            }
        }
        //输入新数据
        for (int i = 0; i < addNum; i++) {
            int id;
            string name;
            int did;
            cout << "请输入第 " << i + 1 << " 个新职工编号：" << endl;
            cin.clear();
            while (cin.get() != '\n') {
            }
            while (!(cin >> id)) {
                cin.clear();
                while (cin.get() != '\n')
                    continue;
                cout << "请输入一个数字:";
            }
            cout << "请输入第 " << i + 1 << " 个新职工姓名：" << endl;
            cin >> name;
            cout << "请选择该职工的岗位：" << endl;
            cout << "1、普通职工" << endl;
            cout << "2、经理" << endl;
            cout << "3、老板" << endl;
            cin.clear();
            while (cin.get() != '\n') {
            }
            while (!(cin >> did)) {
                cin.clear();
                while (cin.get() != '\n') {
                }
                cout << "请输入一个数字:";
            }
            Worker *worker = nullptr;
            switch (did) {
                case 1: //普通员工
                    worker = new Employee(id, name, 1);
                    break;
                case 2: //经理
                    worker = new Manager(id, name, 2);
                    break;
                case 3:  //老板
                    worker = new Boss(id, name, 3);
                    break;
                default:
                    break;
            }
            newArr[num + i] = worker;
        }
        delete pWorkerArray;
        this->num = newSize;
        this->pWorkerArray = newArr;
        this->isFileEmpty = false;
        ofstream ofs2(FILENAME, ios::app);
        save(num - addNum, ofs2);
        cout << "成功添加 " << addNum << "人" << endl;
    } else {
        cout << "输出有误！" << endl;
    }
    system("pause");
    system("cls");
}

void WorkManager::save(int begin, ofstream &ofs) {
    for (int i = begin; i < num; ++i) {
        ofs << pWorkerArray[i]->id << "\t"
            << pWorkerArray[i]->name << "\t"
            << pWorkerArray[i]->did << endl;
    }
    ofs.close();
}

int WorkManager::getFileNum() {
    ifstream ifs(FILENAME, ios::in);
    int id = 0;
    string name;
    int did = 0;
    int cnt = 0;
    while (ifs >> id && ifs >> name && ifs >> did) {
        cnt++;
    }
    ifs.close();
    return cnt;
}

void WorkManager::fileReadInit() {
    ifstream ifs(FILENAME, ios::in);
    int id = 0;
    string name;
    int did = 0;
    int index = 0;
    Worker *worker = nullptr;
    while (ifs >> id && ifs >> name && ifs >> did) {
        switch (did) {
            case 1:
                worker = new Employee(id, name, did);
                break;
            case 2:
                worker = new Manager(id, name, did);
                break;
            case 3:
                worker = new Boss(id, name, did);
                break;
            default:
                cout << "文件中存在不正确的worker 的部门" << endl;
        }
        this->pWorkerArray[index++] = worker;
    }


}

void WorkManager::showEmployee() {
    if (isFileEmpty) {
        cout << "空目录！" << endl;
        system("pause");
        system("cls");
        return;
    }
    for (int i = 0; i < num; ++i) {
        pWorkerArray[i]->showInfo();
    }
    system("pause");
    system("cls");
}

int WorkManager::isExist(int id) {
    int index = 0;
    for (; index < num; ++index) {
        if (pWorkerArray[index]->id == id) {
            return index;
        }
    }
    return -1;
}

void WorkManager::deleteEmp() {
    if (isFileEmpty) {
        cout << "目录为空！" << endl;
        return;
    }
    cout << "输入你想要删除人的编号：" << endl;
    int eN = -1;
    int index;
    while (!(cin >> eN) || (index = isExist(eN)) == -1) {
        cin.clear();
        while (cin.get() != '\n') {
        }
        cout << "输入的编号有误或者是编号不存在:";
    }
    for (int i = index; i < num - 1; ++i) {
        pWorkerArray[i] = pWorkerArray[i + 1];
    }
    //修改文件中的目录
    this->num--;
    if (num == 0) {
        this->isFileEmpty = true;
    }
    ofstream ofs(FILENAME, ios::trunc);
    save(0, ofs);
    cout << "删除成功！" << endl;
    system("pause");
    system("cls");
}

void WorkManager::modifyEmp() {
    if (isFileEmpty) {
        cout << "目录为空！" << endl;
        return;
    }
    cout << "输入你想要修改人的编号：" << endl;
    int eN = -1;
    int index;
    cin >> eN;
    if((index = isExist(eN)) == -1) {
        cout << "输入的编号有误或者是编号不存在:";
    }else{
        delete pWorkerArray[index];
    }
    Worker *worker = nullptr;
    int id;
    string name;
    int did;
    cout << "请输入职工编号：" << endl;
    while (!(cin >> id)) {
        cin.clear();
        while (cin.get() != '\n')
            cout << "请输入一个数字:";
    }
    cout << "请输入职工姓名：" << endl;
    cin >> name;
    cout << "请选择该职工的岗位：" << endl;
    cout << "1、普通职工" << endl;
    cout << "2、经理" << endl;
    cout << "3、老板" << endl;
    cin.clear();
    while (cin.get() != '\n') {
    }
    while (!(cin >> did)) {
        cin.clear();
        while (cin.get() != '\n') {
        }
        cout << "请输入一个数字:";
    }
    switch (did) {
        case 1: //普通员工
            worker = new Employee(id, name, 1);
            break;
        case 2: //经理
            worker = new Manager(id, name, 2);
            break;
        case 3:  //老板
            worker = new Boss(id, name, 3);
            break;
        default:
            break;
    }
    pWorkerArray[index] = worker;
    ofstream ofs(FILENAME, ios::trunc);
    save(0, ofs);
    cout << "修改成功！" << endl;
    system("pause");
    system("cls");
}

int WorkManager::findEmp() {
    if (isFileEmpty) {
        cout << "目录为空！" << endl;
        return -1;
    }
    int choice;
    cout << "请输入查找的方式：" << endl;
    cout << "1、按职工编号查找" << endl;
    cout << "2、按姓名查找" << endl;
    while (!(cin >> choice)) {
        cin.clear();
        while (cin.get() != '\n')
            cout << "请输入一个数字:";
    }
    int result = 0;
    if (choice == 1) {
        int id;
        cout << "请输入职工编号：" << endl;
        while (!(cin >> id)) {
            cin.clear();
            while (cin.get() != '\n')
                cout << "请输入一个数字:";
        }
        result = isExist(id);
    } else if (choice == 2) {
        string name;
        cout << "输入要查询的名字：" << endl;
        cin >> name;
        result = findByName(name);
    }
    if (result == -1) {
        cout << "查找失败，查无此人" << endl;
        system("pause");
        system("cls");
        return -1;
    } else {
        cout << "查找成功！该职工信息如下：" << endl;
        this->pWorkerArray[result]->showInfo();
        system("pause");
        system("cls");
        return result;
    }
}

int WorkManager::findByName(string name) {
    int result = 0;
    for (; result < num; ++result) {
        if (pWorkerArray[result]->name == name) {
            return result;
        }
    }
    return -1;
}

void WorkManager::sort() {
    if (this->isFileEmpty) {
        cout << "文件不存在或记录为空！" << endl;
        system("pause");
        system("cls");
    } else {
        cout << "请选择排序方式： " << endl;
        cout << "1、按职工号进行升序" << endl;
        cout << "2、按职工号进行降序" << endl;
        int select = 0;
        cin >> select;
        if (select == 1) {
            mergeSort(this->pWorkerArray, 0, num - 1, true);
        } else if (select == 2) {
            mergeSort(this->pWorkerArray, 0, num - 1, false);
        } else {
            cout << "输入错误！" << endl;
        }
    }
    ofstream ofs(FILENAME, ios::trunc);
    save(0, ofs);
    system("pause");
    system("cls");
}

void WorkManager::mergeSort(Worker **pWorker, int left, int right, bool isUp) {
    int mid = (left + right) / 2;
    if (left < right) {
        mergeSort(pWorker, left, mid, isUp);
        mergeSort(pWorker, mid + 1, right, isUp);
        merge(pWorker, left, right, mid, isUp);
    }
}

void WorkManager::merge(Worker **pWorker, int left, int right, int mid, bool isUp) {
    Worker **ptemp = new Worker *[right - left + 1];
    int index = mid + 1;
    int l = left;
    int cnt = 0;
    int up = 1;
    if (!isUp) {
        up = -1;
    }
    while (left <= mid && index <= right) {
        if (up * (pWorker[left]->id - pWorker[index]->id) < 0) {
            ptemp[cnt] = pWorker[left];
            cnt++;
            left++;
        } else {
            ptemp[cnt++] = pWorker[index++];
        }
    }
    while (left <= mid) {
        ptemp[cnt++] = pWorker[left++];
    }
    while (index <= right) {
        ptemp[cnt++] = pWorker[index++];
    }
    for (int i = l; i < cnt + l; ++i) {
        pWorker[i] = ptemp[i - l];
    }
    delete[] ptemp;
}

void WorkManager::destroyEmp() {
    cout << "确认清空？" << endl;
    cout << "1、确认" << endl;
    cout << "2、返回" << endl;

    int select = 0;
    cin >> select;

    if (select == 1) {
        ofstream ofs(FILENAME, ios::trunc);
        if (pWorkerArray != nullptr) {
            for (int i = 0; i < num; ++i) {
                delete pWorkerArray[i];
            }
            delete [] pWorkerArray;
            pWorkerArray = nullptr;
            this->num = 0;
            this->isFileEmpty = true;
            cout << "清空成功！" << endl;
        }
        else{
            cout << "文件已经是空的！" << endl;
        }
    }
    system("pause");
    system("cls");

}

