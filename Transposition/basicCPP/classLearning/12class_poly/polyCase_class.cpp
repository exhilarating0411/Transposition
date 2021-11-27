#include<iostream>
using namespace std;

class AbstractCalculator{
public:

    virtual int getRes(){
        return 0;
    }

    int m_num1;
    int m_num2;
};

class AddCal:public AbstractCalculator{
public:
    int getRes(){
        return m_num1+m_num2;
    }
};


class MultiCal:public AbstractCalculator{
public:
    int getRes(){
        return m_num1*m_num2;
    }
};

void test01(){
    AbstractCalculator *abc = new AddCal;
    abc->m_num2 = 10;
    abc->m_num1 = 10;
    cout<<abc->getRes()<<endl;
    delete abc;
    abc = new MultiCal;
    abc->m_num2 = 10;
    abc->m_num1 = 10;
    cout<<abc->getRes()<<endl;
    delete abc;
    
}

int main(){
    test01();
}
