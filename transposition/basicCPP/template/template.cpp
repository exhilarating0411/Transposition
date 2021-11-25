#include<iostream>
using namespace std;

//template声明模板
//typename数据类型

//可以使用自动类型转换，和指定类型转换
//但是不管怎样都需要使模板明确数据类型

//自动类型转换不支持隐式类型转换
//指定类型转换是可以隐式类型转换

//但是需要注意的是使用引用的时候是不可以隐式类型转换的

// 有函数模板和普通函数，会先调用普通函数据类型
//通过空模板的参数列表能去调用函数模板，如test02（）

//然而只要函数类型不同，比如int 和 double 会发现即使能发生隐式转换，也会优先调用模板
//当然如果是自动类型的模板是不支持隐式类型转换的，因此会调用普通函数，如 1.1

//一般有了函数模板就不会写一个普通的了

template <typename T>
T getAdd(T a, T b) {
    cout<<"template"<<'\t';
    return a+b;
}

int getAdd(int a, int b){
    cout<<"function"<<'\t';
    return a+b;
}

void test02(){
    int a = 2, b = 3;
    double c = 4.0, d = 5.0;
    char e = 'a';
    cout<<getAdd(c,e)<<endl;//1.1
    cout<<getAdd<int>(c,e);
    // cout<<getAdd<>(c,e)<<endl;报错


}


template<typename T>
void swap1(T a, T b){
    T temp = a;
    a = b; 
    b = temp;
}

template<typename T>
void func(){
    cout<<"hhh"<<endl;
}

void test01(){
    int a = 3;
    int b = 4;
    double c = 4.0;
    char d = 'c';
    double e = 5.0;
    swap1<double>(c,e);
    swap1<int>(a,d);
    // swap1(a,d);

    //此时必须确定模板的数据类型
    //func();
    func<int>();
}

int main(){
    test02();
    
}