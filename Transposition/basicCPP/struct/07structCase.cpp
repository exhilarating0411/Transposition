#include <iostream>
#include<string>
using namespace std;

struct Student{
    string name; 
    int score;
};

struct Teacher{
    Student stuArray[5];
    string tName;
};

string nameSeed = "ABCDE";
void allocateSpace(Teacher tArray[], int len){
    for(int i = 0; i < len; i ++) {
        tArray[i].tName = "teacher_";
        tArray[i].tName += nameSeed[i];
        for(int j = 0; j < 5; j ++){
            tArray[i].stuArray[j].name = "student_";
            tArray[i].stuArray[j].name += nameSeed[j];
            int random = rand()%61 + 40;
            tArray[i].stuArray[j].score = random;
        }
        
    }
}

void printInfo(Teacher tarray[], int len){
    for(int i = 0; i < len; i ++){
        cout<<"tname:  "<<tarray[i].tName<<'\n';
        for(int j = 0; j < 5; j ++){
            cout<<tarray[i].stuArray[j].name<<'\t';
            cout<<tarray[i].stuArray[j].score<<endl;
        }
        cout<<endl;
    }
}

int main(){
    srand((unsigned int)time(NULL));
    Teacher tArray[3];
    int len = sizeof(tArray) / sizeof(tArray[0]);
    allocateSpace(tArray,len);
    printInfo(tArray,len);

}