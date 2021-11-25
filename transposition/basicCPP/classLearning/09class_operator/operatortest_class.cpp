#include <iostream>
#include<string>
using namespace std;

//函数调用（）运算符重载---仿函数
//两种方法---产生一个对象然后进行调用；产生一个匿名对象进行调用


class Myprint{
public:
    void operator()(string test){
        cout<<test<<endl;
    }
};


int main(){
    Myprint myPrint;

    myPrint("hello world!");//仿函数
    Myprint()("hhh");
}