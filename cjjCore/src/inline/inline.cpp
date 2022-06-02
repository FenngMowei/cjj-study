//
// Created by $vf on 2022/5/17.
// Desc:
//
#include "iostream"
#include "fstream"
#include "cstdlib"
using namespace std;
const int LIMIT = 5;
int main(){
    ofstream fout;
    const char * fn = "ep-data.txt";
    fout.open(fn);
    if(!fout.is_open()){
        cout << "Can't open " << fn<< ".Bye."<< endl;
        exit(EXIT_FAILURE);
    }
    double objective;
    cout << "Enter the focal length of your " "telescope objective in mm ";
    cin >> objective;
    double eps[LIMIT];
    cout << "Enter the focal lengths, in mm, of" << LIMIT << " eyepieces"<<endl;
    for(int i =0; i< LIMIT; i++){
        cout << "Eyepiece #" << i + 1 << ": ";
        cin >> eps[i];
    }
}
void file_it(ostream & os, double fo, const double fe[]){
    
}