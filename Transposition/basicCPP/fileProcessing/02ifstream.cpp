#include<fstream>
#include <iostream>
#include<string>
using namespace std;


void test01(){
    ifstream ifs;
    ifs.open("01test.txt", ios::in);
    if(!ifs.is_open()){
        cout<<"ejrkwr"<<endl;
        return;
    }
    //first way
    char buf[1024] = {0};
    while(ifs>>buf){
        cout<<buf<<endl;
        cout<<"jjj"<<endl;
    }
    ifs.close();

}

void test02(){
    ifstream ifs;
    ifs.open("01test.txt", ios::in);
    char buf[1024] = {0};
    while(ifs.getline(buf,sizeof(buf))){
        cout<<buf<<endl;
    }
    ifs.close();
}

void test03(){
    ifstream ifs;
    ifs.open("01test.txt",ios::in);
    string buf;
    while(getline(ifs,buf)){
        cout<<buf<<endl;
    }
    ifs.close();
}


int main(){
    test01();
}