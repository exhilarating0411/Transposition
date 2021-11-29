#include<iostream>
using namespace std;
//如果自己写了有参——没有了无参
//如果写了拷贝——没有了无参有参
//如果成员函数里面有指针，并且在堆区开辟了一块空间，那么当你使用拷贝构造函数的时候，请自己创建一个；并且还需要在析构里把空间释放掉

class Person{
public:
    string name;
    Person(){
        name = "anony_p";
        cout<<name<<" constructor called"<<endl;
    }

    Person(const string &a){
        name = a;
        cout<<name<<" constructor called"<<endl;
    }

    Person(const Person& p){
        name = "copy " + p.name;
        cout<<name<<" copy constructor called"<<endl;
    }

    ~Person(){
        cout<<name<<" deconstructor called"<<endl;
    }


};

void test01(Person p){
    
}

void test02(Person &p){

}

Person test03(){
    Person p2;
    cout<<&p2<<endl;
    p2.name = "p2";
    return p2;
}

//同等地位后创建的先析构
int main(){
    //Person p1("p1");
    //test01(p1); -----函数需要传入这个类的形参的时候，调用拷贝构造函数
    //test02(p1); -----如果传的是个引用，编译器会完美的让你觉得没有调用拷贝构造函数也就是让你觉得是一个别名。
    Person p4 = test03();//这个匿名对象直接做了优化,直接给了p4 在函数结束时没有deconstructor————就像一步初始化
    cout<<&p4<<endl;
    p4.name = "p4";
    cout<<&p4<<endl;
    Person p5;

    p5 = test03();//如果不是初始化那么返回值是类的话 是会调用这个临时构造对象的析构函数的。
    
    p5.name = "p5";

    cout<<"aaa"<<endl;

    test03();
    

}