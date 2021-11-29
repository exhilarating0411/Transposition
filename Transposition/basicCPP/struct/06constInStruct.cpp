#include <iostream>
#include<string>
using namespace std;

struct Student{
    string name; 
    int age;
    int score;
};

void printStu(const Student *stu){
    //stu->age = 78;  防止结构体数据被修改；即禁止写入操作
    cout<<stu->name<<stu->age<<stu->score;
}

int main(){
    Student *stu1;
    printStu(stu1);
}