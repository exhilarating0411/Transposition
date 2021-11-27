#pragma once
#include "point.h"
#include<iostream>
using namespace std;
class Circle{
    Point m_center;
    int m_len;
public:
    void setCenter(Point center);

    Point getCenterX();

    void setR(int len);

    int getR();

    void isInCircle(Point& dot);
};