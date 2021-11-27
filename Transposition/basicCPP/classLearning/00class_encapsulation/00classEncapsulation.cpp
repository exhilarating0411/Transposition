#include <iostream>
#include <string>
using namespace std;
//将成员变量设为私有，能够控制可读可写权限
//可写中能够判断有效性

class Student{
private:
    string m_Name;
    int m_Age;
public:
    void setName(string name){
        m_Name = name;
    }
    string showName(){
        return m_Name;
    }
};


class Cube{
    int m_Len;

public:
    void setLen(int len){
        m_Len = len;
    }

    int getLen(){
        return m_Len;
    }


    int getArea(){
        int area = m_Len * m_Len * 6;
        return area;
    }

    int getVolume(){
        int volume = m_Len * m_Len * m_Len;
        return volume;
    }

    bool isSame(Cube &c1){
        return m_Len == c1.m_Len;
    }
};

bool isSame(Cube &c1,Cube &c2){
    int len1 = c1.getLen();
    int len2 = c2.getLen();
    return len1 == len2;
}


int main() {
    Cube c1, c2;
    c1.setLen(10);
    c2.setLen(5);
    cout<<"area is"<<c1.getArea()<<endl;
    cout<<"volume is "<<c2.getVolume()<<endl;
    cout<<"they are same or not "<<c1.isSame(c2)<<endl;
    cout<<"they are same or not "<<isSame(c1,c2)<<endl;

}