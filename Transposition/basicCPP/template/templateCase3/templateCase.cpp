#include<iostream>
#include"templateCase.hpp"
using namespace std;

void test(){
    MyArray<int> arr1(10);
    MyArray<int> arr2(arr1);
    MyArray<int> arr3(20);
    arr3 = arr1;
}

int main(){
    test();
}