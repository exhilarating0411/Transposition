#include <iostream>
#include<string>
using namespace std;

struct Student{
    string name; 
    int age;
    int score;
};

void printStu1(Student s){
    s.age = 100;
    cout<<s.name<<s.age<<s.score<<endl;
}

void printStu2(Student *s){
    s->age = 200;
    cout<<s->name<<s->age<<s->score<<endl;
}

int main(){
    Student s1 = {"hhh", 89, 90};
    printStu1(s1);
    cout<<s1.name<<s1.age<<s1.score<<endl;
    printStu2(&s1);
    cout<<s1.name<<s1.age<<s1.score<<endl;
}