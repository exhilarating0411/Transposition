#include<iostream>
#include<string>
using namespace std;
//全局函数作为友元的类内实现和类外实现（一般类内实现）
// 类外首先需要声明类，再是写这个函数因为这个函数也是个模板，并且需要在类的友元生命中加一个空类型参数列表

template<class T1,class T2>
class Person;

template<class T1, class T2>
void printPerson1(Person<T1,T2> p){
    cout<<p.name<<" "<<p.age;
}

template<class T1, class T2>
class Person{
    friend void printPerson(Person<T1,T2> p){
        cout<<p.name<<" "<<p.age;
    }
    friend void printPerson1<>(Person<T1,T2> p);

public:

    
    Person(T1 name, T2 age) : name(name), age(age){}
private:
    T1 name;
    T2 age;
};




void test(){
    Person<string, int>p("John",18);
    printPerson1(p);
}

int main(){
    test();
}