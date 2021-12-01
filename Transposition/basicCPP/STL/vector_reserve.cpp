#include<iostream>
#include<vector>
using namespace std;

void test() {
    vector<int> v;
    int *p = nullptr;
    int num = 0;
    for(int i = 0; i < 100000; i++){
        v.push_back(i);
        if(p != &v[0]){
            p = &v[0];
            num ++;
        }
    }
    cout<<num<<endl;
}

void test_1(){
    vector<int> v;
    v.reserve(100000);
    int *p = nullptr;
    int num = 0;
    for(int i = 0; i < 100000; i++){
        v.push_back(i);
        if(p != &v[0]){
            p = &v[0];
            num ++;
        }
    }
    cout<<num<<endl;
}

int main(){
    test();
    test_1();
}