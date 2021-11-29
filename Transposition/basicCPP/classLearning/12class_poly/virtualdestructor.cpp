#include<iostream>
#include<string>
using namespace std;

// 虚析构和纯虚析构主要是为了解决父类指针析构不会调用子类中析构函数，无法释放子类堆区的问题
//主要就是子类的堆区释放不释放的问题
// animal constructor
// catconstructor
// cat is...
// cat deconstructor
// animal destructor

class Animal{
public:
    Animal(){
        cout<<"animal constructor"<<endl;
    }
    virtual void speak() = 0;
    // virtual ~Animal(){
    //     cout<<"animal destructor"<<endl;
    // }

    virtual ~Animal() = 0;
};
//因为父类有可能有数据在堆区
Animal::~Animal(){
    cout<<"hhh"<<endl;
}

class Cat:public Animal{
public:

    Cat(string name){
        cout<<"catconstructor"<<endl;
        m_name = new string(name);
    }

    virtual void speak(){
        cout<<"cat is..."<<endl;
    }
    string* m_name;
    ~Cat(){
        cout<<"cat deconstructor"<<endl;
        if(m_name != nullptr){
            delete m_name;
        }
    }
};

void test01(){
    Animal *animal = new Cat("tom");
    animal->speak();
    delete animal;
}
int main(){
    test01();
}