#include<iostream>
using namespace std;

// 抽象类特点：无法实例化对象。。。base b；new base都不行
// 抽象类的子类必须重写纯虚函数

class Base{
public:

    virtual void func() = 0;
};

class Son: public Base{
public:
    void func(){
        cout<<"hhh"<<endl;
    }

};

void test01(){
    Base* bse = new Son;
    bse->func();
}

int main(){
    test01();
}