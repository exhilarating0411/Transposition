#include<fstream>
#include<iostream>
using namespace std;

class Person{
public:
    char* m_name;
    int m_age;

    Person() = default;
    Person(char* a,int age):m_name(a),m_age(age){}
};

void test01(){
    Person p("tom",10);

    ofstream ofs;
    ofs.open("03test.txt",ios::out | ios::binary);
    ofs.write((const char*)&p,sizeof(p));
    ofs.close();

}

void test02(){
    Person p;
    ifstream ifs;
    ifs.open("03test.txt", ios::in|ios::binary);
    ifs.read((char*)&p,sizeof(p));
    cout<<p.m_name<<endl<<p.m_age<<endl;
    ifs.close();
}

int main(){
    //test01();
    test02();
}