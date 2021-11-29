#include<iostream>
using namespace std;
// #include "circle.h"
// #include "point.h"

class Point{
    int m_x;
    int m_y;

public:
    void setPoint(int x, int y){
        m_x = x;
        m_y = y;
    }

    int getPointX()const{
        return m_x;
    }

    int getPointY()const{
        return m_y;
    }

};

class Circle{
    Point m_center;
    int m_len;
public:
    void setCenter(Point center){
        m_center = center;
    }

    Point getCenterX(){
        return m_center;
    }

    void setR(int len){
        m_len = len;
    }

    int getR(){
        return m_len;
    }

    void isInCircle(const Point& dot){
        int dis_x = dot.getPointX() - m_center.getPointX();
        int dis_y = dot.getPointY() - m_center.getPointY();
        int distance = dis_x * dis_x + dis_y * dis_y;
        if(distance > m_len){
            cout<<"out of circle"<<endl;
        }
        else if(distance == m_len){
            cout<<"on the circle"<<endl;
        }
        else{
            cout<<"in the circle"<<endl;
        }
    }
};


int main(){
    Point A;
    A.setPoint(0,0);


    Point B;
    B.setPoint(10,10);
    Circle t_circle;
    t_circle.setCenter(B);
    t_circle.setR(5);

    t_circle.isInCircle(A);

}