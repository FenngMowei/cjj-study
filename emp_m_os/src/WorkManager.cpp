//
// Created by $vf on 2022/5/31.
// Desc:
//
#include "WorkManager.h"

void WorkManager::exitSystem() {
    cout << "�˳�ϵͳ��" << endl;
    system("pause");
    exit(0);
}


WorkManager::WorkManager() {
    this->num = 0;
    this->pWorkerArray = nullptr;
    this->isFileEmpty = true;
    ifstream ifs(FILENAME, ios::in);
    if (!ifs.is_open()) {
        cout << "�ļ�������!" << endl;
        ifs.close();
        return;
    }
    //����ch�����ã�
    char ch;
    ifs >> ch; //���ļ���ʶ�����嵽�ļ�β
    if (ifs.eof()) { //eof()�����Ǹ����ļ�״̬��ʶ���жϵ�ǰ�Ƿ����ļ�β
        cout << "�ļ�Ϊ��!" << endl;
        ifs.close();
        return;
    }
    //3���ļ�����
    //���ļ�����ʼ��
    //1.��ȡ�ļ����˵ĸ���
    this->num = getFileNum();
    this->pWorkerArray = new Worker *[this->num];
    //2.���ö��ļ��ĺ���
    fileReadInit();
    this->isFileEmpty = false;
    ifs.close();
}

WorkManager::~WorkManager() {
    delete pWorkerArray;
}

void WorkManager::showMenu() {
    cout << "********************************************" << endl;
    cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
    cout << "*************  0.�˳��������  *************" << endl;
    cout << "*************  1.����ְ����Ϣ  *************" << endl;
    cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
    cout << "*************  3.ɾ����ְְ��  *************" << endl;
    cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
    cout << "*************  5.����ְ����Ϣ  *************" << endl;
    cout << "*************  6.���ձ������  *************" << endl;
    cout << "*************  7.��������ĵ�  *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}

void WorkManager::addEmp() {
    int addNum = 0;
    cout << "���������Ա��������" << endl;
    while (!(cin >> addNum)) {
        cin.clear();
        while (cin.get() != '\n') {
        }
        cout << "������һ������: ";
    }
    if (addNum > 0) {
        int newSize = num + addNum;
        Worker **newArr = new Worker *[newSize];
        if (pWorkerArray != nullptr) {
            //��ԭ���Ŀռ���ڴ�ŵ����ڵĿռ���
            for (int i = 0; i < num; ++i) {
                newArr[i] = pWorkerArray[i];
            }
        }
        //����������
        for (int i = 0; i < addNum; i++) {
            int id;
            string name;
            int did;
            cout << "������� " << i + 1 << " ����ְ����ţ�" << endl;
            cin.clear();
            while (cin.get() != '\n') {
            }
            while (!(cin >> id)) {
                cin.clear();
                while (cin.get() != '\n')
                    continue;
                cout << "������һ������:";
            }
            cout << "������� " << i + 1 << " ����ְ��������" << endl;
            cin >> name;
            cout << "��ѡ���ְ���ĸ�λ��" << endl;
            cout << "1����ְͨ��" << endl;
            cout << "2������" << endl;
            cout << "3���ϰ�" << endl;
            cin.clear();
            while (cin.get() != '\n') {
            }
            while (!(cin >> did)) {
                cin.clear();
                while (cin.get() != '\n') {
                }
                cout << "������һ������:";
            }
            Worker *worker = nullptr;
            switch (did) {
                case 1: //��ͨԱ��
                    worker = new Employee(id, name, 1);
                    break;
                case 2: //����
                    worker = new Manager(id, name, 2);
                    break;
                case 3:  //�ϰ�
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
        cout << "�ɹ���� " << addNum << "��" << endl;
    } else {
        cout << "�������" << endl;
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
                cout << "�ļ��д��ڲ���ȷ��worker �Ĳ���" << endl;
        }
        this->pWorkerArray[index++] = worker;
    }


}

void WorkManager::showEmployee() {
    if (isFileEmpty) {
        cout << "��Ŀ¼��" << endl;
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
        cout << "Ŀ¼Ϊ�գ�" << endl;
        return;
    }
    cout << "��������Ҫɾ���˵ı�ţ�" << endl;
    int eN = -1;
    int index;
    while (!(cin >> eN) || (index = isExist(eN)) == -1) {
        cin.clear();
        while (cin.get() != '\n') {
        }
        cout << "����ı����������Ǳ�Ų�����:";
    }
    for (int i = index; i < num - 1; ++i) {
        pWorkerArray[i] = pWorkerArray[i + 1];
    }
    //�޸��ļ��е�Ŀ¼
    this->num--;
    if (num == 0) {
        this->isFileEmpty = true;
    }
    ofstream ofs(FILENAME, ios::trunc);
    save(0, ofs);
    cout << "ɾ���ɹ���" << endl;
    system("pause");
    system("cls");
}

void WorkManager::modifyEmp() {
    if (isFileEmpty) {
        cout << "Ŀ¼Ϊ�գ�" << endl;
        return;
    }
    cout << "��������Ҫ�޸��˵ı�ţ�" << endl;
    int eN = -1;
    int index;
    cin >> eN;
    if((index = isExist(eN)) == -1) {
        cout << "����ı����������Ǳ�Ų�����:";
    }else{
        delete pWorkerArray[index];
    }
    Worker *worker = nullptr;
    int id;
    string name;
    int did;
    cout << "������ְ����ţ�" << endl;
    while (!(cin >> id)) {
        cin.clear();
        while (cin.get() != '\n')
            cout << "������һ������:";
    }
    cout << "������ְ��������" << endl;
    cin >> name;
    cout << "��ѡ���ְ���ĸ�λ��" << endl;
    cout << "1����ְͨ��" << endl;
    cout << "2������" << endl;
    cout << "3���ϰ�" << endl;
    cin.clear();
    while (cin.get() != '\n') {
    }
    while (!(cin >> did)) {
        cin.clear();
        while (cin.get() != '\n') {
        }
        cout << "������һ������:";
    }
    switch (did) {
        case 1: //��ͨԱ��
            worker = new Employee(id, name, 1);
            break;
        case 2: //����
            worker = new Manager(id, name, 2);
            break;
        case 3:  //�ϰ�
            worker = new Boss(id, name, 3);
            break;
        default:
            break;
    }
    pWorkerArray[index] = worker;
    ofstream ofs(FILENAME, ios::trunc);
    save(0, ofs);
    cout << "�޸ĳɹ���" << endl;
    system("pause");
    system("cls");
}

int WorkManager::findEmp() {
    if (isFileEmpty) {
        cout << "Ŀ¼Ϊ�գ�" << endl;
        return -1;
    }
    int choice;
    cout << "��������ҵķ�ʽ��" << endl;
    cout << "1����ְ����Ų���" << endl;
    cout << "2������������" << endl;
    while (!(cin >> choice)) {
        cin.clear();
        while (cin.get() != '\n')
            cout << "������һ������:";
    }
    int result = 0;
    if (choice == 1) {
        int id;
        cout << "������ְ����ţ�" << endl;
        while (!(cin >> id)) {
            cin.clear();
            while (cin.get() != '\n')
                cout << "������һ������:";
        }
        result = isExist(id);
    } else if (choice == 2) {
        string name;
        cout << "����Ҫ��ѯ�����֣�" << endl;
        cin >> name;
        result = findByName(name);
    }
    if (result == -1) {
        cout << "����ʧ�ܣ����޴���" << endl;
        system("pause");
        system("cls");
        return -1;
    } else {
        cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
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
        cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
        system("pause");
        system("cls");
    } else {
        cout << "��ѡ������ʽ�� " << endl;
        cout << "1����ְ���Ž�������" << endl;
        cout << "2����ְ���Ž��н���" << endl;
        int select = 0;
        cin >> select;
        if (select == 1) {
            mergeSort(this->pWorkerArray, 0, num - 1, true);
        } else if (select == 2) {
            mergeSort(this->pWorkerArray, 0, num - 1, false);
        } else {
            cout << "�������" << endl;
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
    cout << "ȷ����գ�" << endl;
    cout << "1��ȷ��" << endl;
    cout << "2������" << endl;

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
            cout << "��ճɹ���" << endl;
        }
        else{
            cout << "�ļ��Ѿ��ǿյģ�" << endl;
        }
    }
    system("pause");
    system("cls");

}

