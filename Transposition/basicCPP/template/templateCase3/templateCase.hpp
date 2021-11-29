#pragma once
#include <iostream>
#include<string>

using namespace std;

template<typename T>
class MyArray{
public:
    MyArray(int capacity) {
        cout<<"constructor"<<endl;
        this->m_Capacity = capacity;
        this->m_Size = 0;
        this->pAddress = new T[this->m_Capacity];
    }

    MyArray(const MyArray& arr) {
        cout<<"copy constructor"<<endl;
        this->m_Capacity = arr.m_Capacity;
        this->pAddress = new T[this->m_Capacity];
        this->m_Size = arr.m_Size;

        for(int i = 0; i < this->m_Size; i++){
            this->pAddress[i] = arr.pAddress[i];
        }
    }

    MyArray& operator=(const MyArray& arr) {
        //相比于拷贝构造函数，需要先判断arr中是否已经有数据，如果有先释放
        cout<<"operator = "<<endl;
        if(this->pAddress != nullptr){
            delete [] this->pAddress;
            this->pAddress = nullptr;
            this->m_Capacity = 0;
            this->m_Size = 0;
        }
        this->m_Size = arr.m_Size;
        this->m_Capacity = arr.m_Capacity;
        this->pAddress = new T[this->m_Capacity];
        for(int i = 0; i < m_Size; i ++){
            pAddress[i] = arr.pAddress[i];
        }
        return *this;
    }

    void push_back(const T& elem){
        
        if(this->m_Capacity == this->m_Size){
            return;
        }
        
        this->pAddress[this->m_Size] = elem;
        this->Size += 1;
    }

    void pop(){
        if(this->m_Size == 0){
            return;
        }
        this->size --;
    }

    T& operator[](int index){
        return this->pAddress[index];
    }

    int getCapacity(){
        return this->m_Capacity;
    }

    int getSize(){
        return this->m_Size;
    }

    ~MyArray(){
        if(this->pAddress != NULL){
            delete[] this->pAddress;
            this->pAddress = NULL;
        }
    }

private:
    T* pAddress;
    int m_Capacity;
    int m_Size;
};