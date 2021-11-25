#pragma once
#include "point.h"


void Point::setPoint(int x, int y){
    m_x = x;
    m_y = y;
}

int Point::getPointX(){
    return m_x;
}

int Point::getPointY(){
    return m_y;
}
