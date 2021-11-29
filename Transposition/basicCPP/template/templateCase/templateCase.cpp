#include <iostream>
#include<string>
#include"person.hpp"
// 当使用类模板的时候，直接包含头文件会出错，因为类中的成员函数不是声明后马上生成的，而是在调用的时候在生成的，因此分文件链接不到
// 解决方式：1.直接包含cpp文件，2.将头文件和cpp文件写在一起，然后后缀为.hpp
using namespace std;

void test() {
    Person<string,int> p("John", 18);
    p.showPerson();

}


int main(){
    test();
}