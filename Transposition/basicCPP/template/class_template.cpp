#include<iostream>
#include<string>
using namespace std;
//类模板可以有默认参数,函数模板也接受默认参数
//都可以有多个参数T
//类模板必须显式转换，即便有默认参数了，《》也要有。
//但是如果有默认参数时，必须和默认参数的类型完全相同，或者就是不涉及到模板类型，否则就会报错（不支持隐式转换，因为不知道要不要转）
//但是如果显示指出函数类型，那么可以有隐式转换的

template<class NameType = string,class AgeType = int>
class Person{
public:
    NameType m_name;
    AgeType m_age;

    Person(NameType name,AgeType age):m_name(name),m_age(age){}

    void showPerson(){
        cout<<m_name<<" "<<m_age<<endl;
    }
};

void test(){
    Person<> p1("tom",78);
    Person<string, int> p2 ("peter",34);
    p1.showPerson();
    p2.showPerson();
}

int main(){
    test();
}
