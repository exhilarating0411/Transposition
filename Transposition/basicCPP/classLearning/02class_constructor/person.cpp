#include<iostream>
using namespace std;


class Point{
    int m_x;
    int m_y;
};

class Person{
public:
    int age;
    Person(){
        cout<<"no argument constructor called"<<endl;
    }

    Person(int a){
        age = a;
        cout<<"argument constructor called"<<endl;
    }

    Person(const Person& p){
        age = p.age;
        cout<<"age is"<<age<<'\t';
        cout<<"copy constructor called"<<endl;
    }

    ~Person(){
        cout<<"distructor called"<<endl;
    }

    
};

  //()法
void test_1(){
    Person p1;
    Person p2(10);
    Person p3(p2);
    //Person p4();  这种写法编译器认为是一种函数声明，不会报错但是也不会生成该对象……因为只是一个声明
}

//显示法_匿名对象
void test_2(){
   // Person p4 = Person();
    Person p5 = Person(10);
    Person p6 = Person(p5);
    //Person(10)是一个匿名对象已经调用，立即会被系统析构；
    //不要使用单独的Person(p5) 因为这会让编译器认为是一个函数声明person p5

}
//隐士转换法
void test_3(){
    Person p7 = 10;
    Person p8 = p7;
}


int main(){
    //test_1();
    test_2();
    //test_3();
}