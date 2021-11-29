#include<iostream>
using namespace std;

class Drinking{
public:
    virtual void boilWater() = 0;
    virtual void brew() = 0;
    virtual void pourInCup() = 0;
    virtual void putSome() = 0;
    void makeDrink(){
        boilWater();
        brew();
        pourInCup();
        putSome();
    }
};

class Coffee:public Drinking{
public:
    virtual void boilWater(){
        cout<<"boil coff"<<endl;
    }
    virtual void brew(){
        cout<<"brew coff"<<endl;
    }
    virtual void pourInCup(){
        cout<<"pour coff"<<endl;
    }
    virtual void putSome() {
        cout<<"put coff"<<endl;
    }
};

class Tea:public Drinking{
public:
    virtual void boilWater(){
        cout<<"boil tea"<<endl;
    }
    virtual void brew(){
        cout<<"brew tea"<<endl;
    }
    virtual void pourInCup(){
        cout<<"pour tea"<<endl;
    }
    virtual void putSome() {
        cout<<"put tea"<<endl;
    }
};

void doWork(Drinking *drink){
    drink->makeDrink();
    delete drink;
}

void test01(){
    doWork(new Coffee);
    doWork(new Tea);
}


int main(){
    test01();
}