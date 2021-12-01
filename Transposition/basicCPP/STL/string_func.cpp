#include <string>
#include<iostream>
using namespace std;
//string 本质上是一个类
//底层维护着一个char*
//注意：一般char，char* 转string直接赋值就可以了，如果string要转换成char* 比如要使用strcpy（）时，那么可以使用s.c_str()函数，该函数返回的是一个const char*并且包含'\0'
void test(){
    //intialize
    string s1();
    string s2("hello");
    string s3(s2);
    string s4(5,'a');

    string s5 = "hell";
    string s6 ="oWorld";
    string s7 = "world";
    //赋值
    s7.assign(s6);
    s7.assign(5,'c');
    const char* s8 = "hello";
    s7.assign(s8,5);
    //s7.assign(s5,2);注意不能是string的前n个字母而是char* 的前n个
    //拼接，常用的就这两个，第二个指的是一个string，拼接从第x位开始起的y个字符
    s5 += s6;
    s5.append(s6,0,1);
    //查找和替换（就选两个常用的了）4
    string s9 = "abcdefgabcd";
    int index = s9.find("ce");//如果没有，输出的是-1
    cout<<index<<" "<<endl;
    int index2 = s9.rfind("cd");
    cout<<index2<<" "<<endl;
    string s10 = "abcdefgabcd";
    s10.replace(11,4,"1111");//这里可以到11，也就是把'\0'给换了
    cout<<s10<<endl;
    //比较
    string s11 = "abcdefgabcd";
    string s12 = "djsffh";
    int res = s11.compare(s12);
    cout<<res<<endl;
    //存取[]与.at()  对于[]'\0'是有效的；at则无效，因此at更安全，两者都返回引用类型
    //插入和删除
    string s13 = "abcdefgabcd";
    s13.insert(1,"hello");//从序号为1开始插入
    cout<<s13<<endl;
    s13.erase(1,3);//从序号为1开始删除三个
    s13.erase(1);//删除序号为1后的所有
    cout<<s13<<endl;  
    //子串
    string s14 = "336746@qq.com";
    int pos = s14.find('@');
    string s15 = s14.substr(0,pos);
    cout<<s15<<endl;
   
}

int main(){
    test();
}
