#include <iostream>
using namespace std;

//左移运算符重载
//只能作为全局函数，因为如果是成员函数把cout传进去————p<<cout ----so strange
//通常会把它作为友元。
//为了连续的输出所以返回值设定为了引用类型ostream

class Person{
    friend ostream& operator<<(ostream& cout, const Person& p);
public:
    Person(int a,int b):m_a(a),m_b(b){}
private:
    int m_a;
    int m_b;
};



// operator as global function
ostream& operator<<(ostream& cout, const Person& p){
    cout<<p.m_a<<p.m_b<<endl;
    return cout;
}

void test01(){
    Person p1(10,20);
    Person p2(30,40);
    cout<<p1<<endl<<p2<<endl;

}

int main(){
    test01();
}