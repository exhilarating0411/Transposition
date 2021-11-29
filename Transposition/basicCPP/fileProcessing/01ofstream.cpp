#include<fstream>
#include <iostream>
using namespace std;
// 文本文件 ascll码
// 二进制文件 二进制

// ofstream ---- write
// ifstream ----- read
// fstream ---- read and write

void test01(){
    ofstream ofs;
    ofs.open("01test.txt", ios::out);
    ofs << "name is hhhh"<<endl;
    ofs<< "fjkdsf"<<endl;
    ofs.close();
}

int main(){
    test01();
}