#include <iostream>
#include<string>
using namespace std;

struct Student{
    string name; 
    int age;
    int score;
};

struct Teacher{
    string name;
    int id;
    int age;
    struct Student stu;
};

int main(){
    Teacher t;
    t.id = 100;
    t.name = "hh";
    t.age = 80;
    t.stu.score = 90;
    t.stu.age = 89;
    t.stu.name = "hsdj";
}