#include <iostream>
#include<string>
using namespace std;

struct Character{
    string name; 
    int age;
    string sex;
};

string nameSeed = "ABCDE";
void allocateSpace(Character a[], int len){
    for(int i = 0; i < len; i ++){
        a[i].name = "hhh";
        a[i].name += nameSeed[i];
        a[i].sex = "male";
        int random = rand() % 51 + 20;
        a[i].age = random;
    }
}

void bubbleSort(Character a[], int len){
    //进行len-1次冒泡排序就可以，因为最后一次（也就是第一个数）是不用比较的。
    for(int i = 0; i < len-1; i ++){
        bool flag = true;
        for(int j = 0; j < len-1-i; j++){
            if(a[j].age>a[j+1].age){
                int tmp = a[j].age;
                a[j].age = a[j+1].age;
                a[j+1].age = tmp;  
                flag = false;
            }
        }
        if(flag)break;
    }
}

void printInfo(Character a[], int len) {
    for(int i = 0; i < len; i ++){
        cout<<a[i].name<<'\t'<<a[i].age<<'\t'<<a[i].sex;
        cout<<endl;
    }
}

int main(){
    Character people[5];
    int len = sizeof(people) / sizeof(people[0]);
    allocateSpace(people,len);
    bubbleSort(people,len);
    printInfo(people,len);
}