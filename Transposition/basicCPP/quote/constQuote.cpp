#include <iostream>
using namespace std;

int main() {
    //引用不能直接初始化为常量；但是常量引用可以（编译器会优化：int tmp = 10; const int& ref = tmp;)
    const int& ref = 10;
    //常量引用主要被用于，形参……不能修改输入的变量就会使用const int& a
}