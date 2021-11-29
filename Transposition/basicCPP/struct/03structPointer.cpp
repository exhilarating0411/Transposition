#include <iostream>
#include<string>
using namespace std;

struct Student{
    string name;
    int age;
    int score;
};

int main(){
    Student s = {"hhh", 12, 89};
    Student *p = &s;
    cout<<p->name<<p->age<<p->score;
}