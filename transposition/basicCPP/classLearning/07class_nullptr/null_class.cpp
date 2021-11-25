#include<iostream>
using namespace std;
// 一个类——也可以是空指针——但是在调用函数的时候不能涉及到this
// 为了提高健壮性，可以使用if(this == nullptr)
class Person{
    int age;
public:
    void showAge(){
        cout<<"hhhhh"<<endl;
    }

    void showAge1(){
        if(this == nullptr)
        {
            cout<<"nonono"<<endl;
            return;
        }
        cout<<age<<endl;
    }
};

int main(){
    Person* p1 = nullptr;
    p1->showAge();
    p1->showAge1();

}