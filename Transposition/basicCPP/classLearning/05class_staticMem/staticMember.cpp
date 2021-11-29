#include<iostream>
using namespace std;


//静态成员变量：
// 共享一篇内存（全局区）
// 编译时就分配内存（全局区和代码区）
// 类内声明，类外初始化
//不能放在初始化列表中，只能在类外初始化……
//私有权限类外访问不到


//静态成员函数----只能访问静态成员变量
//当然，确切地说，是如果有特定对象的话是可以的，必须有指定的特定对象，那么是可以的
//this 用于非静态成员
//因为静态成员函数是被共享的不存在所谓的this
//私有权限类外访问不到

//私有变量，函数都可以通过公有的方式得到，就是说public中是提供接口的，公有函数可以调用私有函数


class Person{
public:
    static int m_a;
    int m_b;
    int m_c;

    

    Person():m_b(20),m_c(30){
       // cout<<m_a<<m_b<<m_c<<endl;
    }

    Person(int a, int b = 1, int c = 5):m_b(b), m_c(c){
        //cout<<m_a<<m_b<<m_c<<endl;
    }

    static void test01(Person &p);

    void test02(){
        test03();
    }

private:
    void test03(){
        cout<<"hhh"<<endl;
    }
    
};

void Person::test01(Person &p){
    Person p1;
    Person::m_a = 100;
    p.m_b = 10;
    cout<<"static member function called"<<endl;
}

int Person::m_a = 100;

int main(){
    Person p1(3);
    Person p2;
    p2.m_a = 10;
    
    p1.test02();

    //可以通过对象 或 类来访问，都会改变它（类中的全局）
    // cout<<p1.m_a<<endl;
    // cout<<Person::m_a<<endl;
}