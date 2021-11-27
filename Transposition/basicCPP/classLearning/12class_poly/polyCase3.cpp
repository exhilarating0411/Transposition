#include<iostream>
using namespace std;

//可以看到，这里的组件和电脑之间并没有继承的关系，而是使用了一个指针
//但是在cpu 和 cpu的不同厂商之间是继承的关系，而且cpu显卡……都作为一个抽象类，这个抽象类能通过指针或引用的方式变成一个具体的类
//这样的好处是可以拓充多个不同的厂家
//妙啊。

class Computer{
public:
    Computer(CPU *cpu,VideoCard* vc,Memory* mem){
        m_cpu = cpu;
        m_vc = vc;
        m_mem = mem;
    }

    void work(){
        m_cpu->cal();
        m_vc->dis();
        m_mem->stor();
    }

    ~Computer(){
        if(m_cpu != nullptr){
            delete m_cpu;
        }
        if(m_vc != nullptr){
            delete m_cpu;
        }
        if(m_mem != nullptr){
            delete m_cpu;
        }
    }

private:
    CPU* m_cpu;
    VideoCard* m_vc;
    Memory* m_mem;
};

class CPU{
public:
    virtual void cal() = 0;
};

class VideoCard{
public:
    virtual void dis() = 0;
};

class Memory{
public:
    virtual void stor() = 0;
};

class IntelCPU:public CPU{
public: 
    virtual void cal(){
        cout<<"intel cpu is..."<<endl;
    }
};

class IntelVC:public VideoCard{
public: 
    virtual void dis(){
        cout<<"intel vc is..."<<endl;
    }
};

class IntelMEM:public Memory{
public: 
    virtual void stor(){
        cout<<"intel memory is..."<<endl;
    }
};


class LenovoCPU:public CPU{
public: 
    virtual void cal(){
        cout<<"Lenovo cpu is..."<<endl;
    }
};

class LenovoVC:public VideoCard{
public: 
    virtual void dis(){
        cout<<"Lenovo vc is..."<<endl;
    }
};

class LenovoMEM:public Memory{
public: 
    virtual void stor(){
        cout<<"Lenovo memory is..."<<endl;
    }
};

void test01(){
    CPU* intelcpu = new IntelCPU;
    VideoCard* intelvd = new IntelVC;
    Memory* intelmm = new IntelMEM;

    Computer * computer1 = new Computer(intelcpu,intelvd,intelmm);
    computer1->work();
    delete computer1;
}

