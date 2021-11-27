#include <iostream>
#include<string>
using namespace std;

struct Student{
    string name;
    int age;
    int score;
}s3;

int main() {
    //结构体创建方式
    struct Student s1;
    s1.name = "hhh";
    s1.age = 10;
    s1.score = 100;
    cout<<s1.name<<'\t'<<s1.age<<'\t'<<s1.score;

    Student s2 = {"hhh1",15,90};
    cout<<s2.name<<'\t'<<s2.age<<'\t'<<s2.score;


    s3.name = "hhh2";
    s3.age = 20;
    s3.score = 96;
    cout<<s3.name<<'\t'<<s3.age<<'\t'<<s3.score;


}