#include <iostream>
#include <string>
#include <typeinfo>
#include <cxxabi.h> 
using namespace std;
//注意：在类模板中的成员函数是在调用时才创建，也就是说只是创建一个对象，是不会创建成员函数的
//如果涉及到类的比较：一种运算符重载；另一种在函数模板的后面，对某个特殊的类进行特别的具体化。

//可以使用三种方式将类模板传入函数模板中，第一种比较具体就像vector<int>这种，第二种template<class T>func(T& p)
//第三种template<class T1,class T2>func(Person<T1,T2>p)

//如果是继承关系的话，首先子类中它的父类必须模板参数初始化，然后由于需要初始化，为了使得被子类继承的父类类型更加灵活，因此子类最好也要模板化

template <typename T1,typename T2>
class Person1{
public:
    T1 name;
    T2 age;
    Person1(){
        this->name = "John";
        this->age = 22;
    }
    Person1(T1 name, T2 age){
        this->name = name;
        this->age = age;
    }

    void showPerson1(){
        cout<<abi::__cxa_demangle(typeid(this->name).name(),0,0,0)<<" "<<abi::__cxa_demangle(typeid(this->age).name(),0,0,0)<<endl;
        cout<<"showPerson1"<<endl;
    }
};

template<class T1,class T2>
class Person2{
public:
    T1 m_name;
    T2 m_age;
    void showPerson2();
};

template<class T1, class T2>
void Person2<T1,T2>::showPerson2(){
    cout<<"hhh"<<endl;
}


template<class T>
class Myclass{
public:
    T obj;

    void func1(){
        obj.showPerson1();
    }

    void func2(){
        obj.showPerson2();
    }
};

template<class T1, class T2>
void func(Person1<T1, T2>& p ){
    p.showPerson1();
}

template<class T>
void func2(T& p){
    p.showPerson1();
}

void test(){
    Person1<string,int>p;
    func(p);
}

void test01(){
    // Myclass<Person1>m; ----不会调用person1成员函数，不会报错
    Myclass<Person1<string,int>> m;
    m.func1();
}

void test02(){
    Person1<string,int>p3;
    func2(p3);
}



int main(){
   // test01();
    //test();
    test02();
}