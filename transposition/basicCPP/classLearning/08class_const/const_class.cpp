#include<iostream>
using namespace std;
//常量对象里可以有非常量成员变量
//常量对象可以引用非常量成员变量，但不可以改变
//常量对象可以有但不可以调用非常量成员函数(不管这个成员函数如何)
//常量成员函数可以被任何对象调用
//常量成员函数可以引用非常量成员变量，但不可以改变
//常量成员函数不可以调用非常量成员函数(不管这个成员函数如何)
//常量成员函数后面加的const 可以理解为this----person* const this---->const person* const this



//当形参是const int*时可以传const or not;当形参是int*时，不能传const int*;
// 只要是int*不管是不是形参，都不能用const int*赋值也不能用&const int赋值
class Person{
public:    
    int age;
    mutable int height;
    Person():age(1){}
    Person(int age):age(age){}

    void setAge0(){
        //this->age = 2;
    }

    void setAge()const{
        cout<<age;
        height = 3;
    }
    
};

void test(int* c){
    cout<<"hhh"<<endl;
}

int main(){
    int b = 4;
    const int* a = &b;
    
    
    // const Person p1;
    // cout<<p1.age;
    // Person p2;
    // p2.setAge();
}