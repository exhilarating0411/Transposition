#include <iostream>
using namespace std;

//多态：
//静态多态：函数重载+运算符重载
//动态多态：派生类+虚函数

// 区别：
// 静态多态函数地址早绑定，编译阶段确定函数地址
// 动态多态函数地址晚绑定，运行阶段确定函数地址

//c++中允许使用父类的引用或者指针（类型本身也可以） = 子类对象
// 但是不能用子类引用或指针 = 父类对象

// 动态多态满足条件：
// 继承关系
// 子类要重写父类的虚函数

// 动态多态使用
// 父类的指针或者引用 执行子类对象

class Animal{
public:
    //晚绑定
    virtual void speak(){
        cout<<"animal is..."<<endl;
    }
};

class Cat: public Animal{
public: 
    void speak(){
        cout<<"cat is ..."<<endl;
    }
};

class Dog: public Animal{
public: 
    void speak(){
        cout<<"dog is ..."<<endl;
    }
};

// 函数地址早绑定，编译阶段已经确定了函数起始地址是在animal.speak()
//如果需要cat。speak（）需要函数晚绑定
void doSpeak(Animal &animal){
    animal.speak();
}

void test01(){
    Cat cat;
    doSpeak(cat); 
    Dog dog;
    doSpeak(dog);
}

void test02(){
    Animal a;
    cout<<sizeof(a);
}


int main(){
    //test01();
    test02();
}