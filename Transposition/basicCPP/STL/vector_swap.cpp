#include<iostream>
#include<vector>
using namespace std;
//swap的用法：1.可以直接交换两个数组
//2.能够收缩vector的capacity！！！！
void printVector(vector<int> &v){
    for(int &t :v){
        cout<<t<<'\t';
    }
    cout<<endl;
}

void test(){
    vector<int> v1 = {1,2,3,4,5};
    vector<int> v2 = {6,7,8,9};
    swap(v1,v2);//两种写法都可以
    //v1.swap(v2);
    printVector(v1);
}

void test_1(){
    vector<int> v1(100,1);
    cout<<v1.capacity()<<endl;
    v1.resize(10);//resize(10,2)是不可行的，仍然是1，因此变长了可以，变短无用
    vector<int>(v1).swap(v1);//注意！！！！！！！！把v1的值赋给一个匿名对象然后交换，从而改变capacity，妙啊！！
    printVector(v1);
    cout<<v1.capacity()<<endl;
}
int main(){
    test_1();
}