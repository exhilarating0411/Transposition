#include<iostream>
using namespace std;

//不管有没有被初始化，都会先调用person中的类phone的构造函数，再调用person的。
//由于是在栈里，因此先放进去的后析构

class Phone{
public:
    string m_name;

    Phone():m_name("iphone"){
        cout<<"this is phone.";
    };
};

class Person{
public:
    int m_a;
    int m_b;
    int m_c;

    Phone phn;

    Person():m_a(10),m_b(20),m_c(30){
        cout<<m_a<<m_b<<m_c<<endl;
    }

    Person(int a, int b, int c):m_a(a), m_b(b), m_c(c){
        cout<<m_a<<m_b<<m_c<<endl;
    }

    
};

int main(){
    Person p1;
    Person p2(30,20,10);
}