#include <string>
#include<iostream>
using namespace std;
//string 本质上是一个类
//底层维护着一个char*
void test(){
    //intialize
    string s1();
    string s2("hello");
    string s3(s2);
    string s4(5,'a');

    string s5 = "hell";
    string s6 ="oWorld";
    string s7 = "world";
    //赋值
    s7.assign(s6);
    s7.assign(5,'c');
    const char* s8 = "hello";
    s7.assign(s8,5);
    //s7.assign(s5,2);注意不能是string的前n个字母而是char* 的前n个

       

    cout<<s7<<endl;
}

int main(){
    test();
}
