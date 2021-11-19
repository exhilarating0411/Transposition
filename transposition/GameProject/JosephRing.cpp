#include<vector>
#include<iostream>
using namespace std;

#define SIZE 5
#define COUNT 2

class Node{
public:    
    int val;

    Node(int val){
        this->val = val;
    }
    Node* next;
};

Node* head = nullptr;
void nodeInit(int n){
    head = new Node(0);
    Node* tmp = head;
    for(int i = 1; i < n; i ++){
        tmp->next = new Node(i);
        tmp = tmp->next;
    }    
    tmp->next = head;
}

//一共有n个node，每数到m删除一个
//linklist 实现
int JosephRing(int n, int m){
    if(m == 1){
        return n-1;
    }
    nodeInit(n);
    Node* tmp = head;
    int index = 1;
    while (tmp->next != tmp)
    {
        if(index < (m-1)%n){
            index ++;
            
        }
        else{
            tmp->next = tmp->next->next;
            index = 1;
            n--;
        }
        tmp = tmp->next;
    }
    return tmp->val;
}
//使用数组实现，注意index+m-1，调用erase 数组下标会改变，直接向前挪动，所以是m-1，尽管迭代器会指向后面一个
vector<int> arr(100);

void arrInit(){
    for(int i = 0; i < SIZE; i++){
        arr[i] = i;
    }
}

int JosephRing2(int m, int n){
    arrInit();
    int index = 0;
    int len = n;
    for(int i = 0; i < n; i ++){
        index = (index+m-1)%len;
        //cout<<arr[index]<<endl;
        arr.erase(arr.begin()+index);
        len --;
        if(len == 1){
            break;
        }
    }
    return arr[0];
}

int main(){
    int a = JosephRing2(COUNT,SIZE);
    cout<<a<<endl;
    
}