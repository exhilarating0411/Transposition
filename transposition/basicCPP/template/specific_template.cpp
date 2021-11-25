#include <string>
#include<iostream>
using namespace std;

class Person{
public:
    string name;
    int age;

    Person(string n = "tom", int a = 10):name(n), age(a){}
};

template<typename T>
bool cmp(T &a, T &b){
    if(a == b){
        
        return true;
    }
    else{
        return false;
    }
}

template<>bool cmp(Person &a, Person &b){
    if(a.name == b.name && a.age == b.age){
        return true;
    }
    else{
        return false;
    }
}
void test(){
    Person p1;
    Person p2("kim",15);
    cout<<cmp(p1,p2)<<endl;
}

int main(){
    test();
}