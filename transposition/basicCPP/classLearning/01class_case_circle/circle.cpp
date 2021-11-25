#include "circle.h"



void Circle::setCenter(Point center){
    m_center = center;
}

Point Circle::getCenterX(){
    return m_center;
}

void Circle::setR(int len){
    m_len = len;
}

int Circle::getR(){
    return m_len;
}

void Circle::isInCircle(Point& dot){
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
