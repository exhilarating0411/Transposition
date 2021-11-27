#include <iostream>
using namespace std;
//首先，在调用一个子类的时候，需要先调用一个父类，然而如果我们没有显示的调用父类的有参构造，那么会调用默认，那么如果父类只有有参，就会报错
class Person{
public:
    int m_a;
};

class Phone:virtual public Person{
    int m_b;

};


class Animal{
public:
    int m_a;


};

class Sheep:virtual public Animal{
public:
    
   // int m_c;

};

class Camel:virtual public Animal {
public:
   // int m_b;
};

class SheepCamel: public Sheep, public Camel {
public:
    int m_a;
    //int m_a;
};
//虚继承和静态是不一样的，静态是属于类的，也就是说，所有的对象都能改变这个值
//虚继承则是只有在这个对象下，这个数据只有一份，可以访问到的是孙子，俩儿子，这三个之间的数据是共享的。
//通过实验可知，如果孙子类有一个和虚基类相同的成员变量，那么孙子类调用自己的，如果没有会通过虚基类指针，找有没有m_a
void test01(){
    Animal a; 
    Sheep s;
    Camel c;
    SheepCamel sc;
    sc.Sheep::m_a = 18;
    sc.Camel::m_a = 28;
    //
    cout<<sc.Sheep::m_a<<endl;
    cout<<sc.Camel::m_a<<endl;
    //cout<<sc.m_a<<endl;--182628
    cout<<sizeof(sc)<<endl;//----24---在孙子类没有数据的时候,有vbptr，而有了这个，我更倾向于认为编译器会用8bit为单位记录，也就是说int m_a 通过8个bit的方式因此被记录为24.
    Phone p;
    cout<<sizeof(p);
}

int main(){
    test01();
}