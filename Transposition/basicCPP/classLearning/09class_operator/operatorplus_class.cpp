#include <iostream>
using namespace std;

//函数运算符可以重载,而且可以连续使用

class Person{
public:
    int m_a;
    int m_b;

    // operator as class member function
    Person operator+(const Person &p){
        Person p1;
        p1.m_a = this->m_a + p.m_a;
        p1.m_b = this->m_b + p.m_b;
        return p1;
    }
};

// operator as global function
Person operator+(const Person& p1, const Person& p2){
    Person p3;
    p3.m_a = p1.m_a + p2.m_a;
    p3.m_b = p1.m_b + p2.m_b;
    return p3;
}

void test01(){
    Person p1;
    p1.m_a = 10;
    p1.m_b = 20;
    
    Person p2;
    p2.m_a = 30;
    p2.m_b = 40;
   
    Person p3 = p1+p2+ p1;
    Person p4 = p1.operator+(p2);
    Person p5 = operator+(p1,p2);
    
    cout<<p3.m_a<<p3.m_b<<endl;
    cout<<p4.m_a<<p4.m_b<<endl;
    cout<<p5.m_a<<p5.m_b<<endl;

}

int main(){
    test01();
}