#include<iostream>
using namespace std;


class Angel{
public:
    
};

//this 指针第一个用法：避免冲突。形参和成员函数。
class Person{
public:
    int age;
    Person(int age){
        this->age = age;
    }

    Person& addAge(Person &p){
        age += p.age;
        return *this;
    }
};

//另一种用法：就是返回对象 的引用 ！！
//为什么必须是引用呢？
//如果不是引用。返回的是一个临时对象。
// 直接调用p1.addAge(p2).addAge(p2)然后输出p1的age 
// 会发现p1.age仍然只有8，那么15去哪儿了，实际上，15给了p1.addAge(p2)这个匿名对象；
// 如果写的是Person p3 = p1.addAge(p2).addAge(p2)，那么p3能得到正确结果，因为最后的临时对象赋值给的是p3
// 简而言之，有等号赋给左值


//返回引用相当于*this自己改变了。所以当返回类型是引用的时候注意一般都是全局或者静态局部变量

class Monster{
public:
    int m_a;
    char m_b;

    static int m_c;
    //非静态成员和静态成员函数都不在对象的存储空间中
    void func(int a){
        m_a = a;
    }

};

//静态成员变量不存储在类的对象上
int Monster::m_c = 3;

int main(){
    //每个空对象占用一个字节，因为需要区分不同的空对象
    Angel a;
    //cout<<sizeof(a)<<endl;

    //由于内存对齐因此是8个bit
    Monster m;
    //cout<<sizeof(m)<<endl;

    Person p1(3);
    Person p2(5);

    //1.用一个新的对象接收————可以连续加
    //2.p1.addAge(p2).addAge(p2)————p1.age只有8————只返回了一次给p1
    Person p3 = p1.addAge(p2).addAge(p2);

    p1.addAge(p2).addAge(p2);
    cout<<p1.age<<endl;
    //cout<<p3.age<<endl;
}