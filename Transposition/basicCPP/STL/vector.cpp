#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void myPrint(int val){
     cout<<val<<endl;
}

void test() {
    vector<int> v;
    v.push_back(10);

    vector<int>::iterator itBegin = v.begin();
    vector<int>::iterator itEnd = v.end();

    //traverse way 1
    while(itBegin != itEnd) {
        cout<<*itBegin<<endl;
        itBegin++;
    }

    //traverse way 2
    for(vector<int>::iterator it = v.begin(); it != v.end();it ++){
        cout<<*it<<endl;
    }
    //callback 函数指针的用途，通过函数指针，库函数能够调用其他函数
    for_each(v.begin(), v.end(),myPrint);

}