#include <iostream>
using namespace std;


//注意：不能返回局部变量的引用；函数的返回值为引用可以作为左值；引用可以用其他引用初始化
//指针的本质是一个指针常量 int &ref = a; equals to int const* ref = a;
// 在写代码的时候注意：不要想的太复杂，把它当作一个别名就可以了。
//指针的引用是有的（可以改变指针指向的地址，但是引用的指针是没有的因为没有必要）


//引用作用的对象：全局区的，不要局部变量
int& test01(){
    static int a = 10;//存放在全局区，由操作系统在程序运行结束后释放
    return a;
}
//指针的引用----可以改变p的地址---否则出了函数体不可以改变p指向的地址（也就是p的内容是否被改变）
void test02(int*& p){
    static int b = 2;
    p = &b;
    
}

int main(){
    //引用必须初始化，并且不能修改引用的指向
    int a = 10;
    int &b = a;//a的引用
    int* p = &a;//a的指针
    cout<<&(*p)<<endl;
    test02(p);
    cout<<&(*p)<<endl;

    char g = 'a';
    char &z  = g;
    
    
    //指针的大小在64位系统中一直是8字节
    //cout<<sizeof(p)<<endl;
    //引用的大小则和原先的初始化类型大小是一样的。
    //cout<<sizeof(z)<<endl;//=1

    int c = 20;
    b = c;//赋值操作，也就是说，b仍然指向a

    int d = test01();//d = 10 赋值操作
    cout<<d<<endl;
    test01() = c;//d = 10; test01()始终是 a 的别名，a = 20。
    int e = test01();
    cout<<e<<endl;

    //引用可以用其他引用初始化
    int &f = test01();
    cout<<f<<endl;

}