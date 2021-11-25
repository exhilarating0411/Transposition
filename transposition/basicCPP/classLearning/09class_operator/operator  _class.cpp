#include <iostream>
using namespace std;

class Person{
    friend ostream& operator<<(ostream& cout, const Person& p);
private:
    int m_a;
    int m_b;

public: 
    Person(int a,int b):m_a(a),m_b(b){}
    //++p  返回 引用
    Person& operator++(){
        m_a++;
        m_b++;
        return *this;
    }
    //p++ int占位参数 (和++p区分) 返回 值 
    Person operator++(int){
        Person tmp = *this;
        m_a++;
        m_b++;
        return tmp;
    }


};

ostream& operator<<(ostream& cout, const Person& p){
    cout<<p.m_a<<p.m_b<<endl;
    return cout;
}


void test01(){
    Person p1(10,20);
    
    cout<<++p1<<endl;
    cout<<++p1<<endl;
    
    cout<<p1++<<endl;
    cout<<p1++<<endl;
}

int main(){
    test01();
}