#include<iostream>
using namespace std;

//函数需要连续操作，那么运算符重载要注意返回的应该是该类型的引用

class Person{
public:
    int m_a;
    int m_b;

    Person(int a, int b):m_a(a), m_b(b){
        cout<<"constructor"<<endl;
    }

    Person& operator=(const Person &p){
        this->m_a = p.m_a;
        this->m_b = p.m_b;
        cout<<"operator ="<<endl;
        return *this;
    }
};

int main(){
    Person p1(3,4);
    Person p2(5,6);
    Person p3 = Person(1,2);

    p1 = p2 = p3;
    cout<<p1.m_a<<p1.m_b;

}