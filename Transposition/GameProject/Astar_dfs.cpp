//dfs---还是在queue中用了指针
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define ROW 6
#define COL 6

class Point{
public:
    int x;
    int y;
    int type;
    int number;
    bool isVisited;
    Point* pre;


    Point(){
        type = 0;
        isVisited = false;
    }    
};

Point pArray[100][100];

pair<int,int> startXY = pair<int,int>(1,1);
pair<int,int> endXY = pair<int,int>(3,4);

void setXY(){
    for(int i = 1; i < ROW; i ++){
        for(int j = 1; j < COL; j ++){
            pArray[i][j].x = i;
            pArray[i][j].y = j;
        }
    }
}

void setType(){
    for(int i = 1; i < ROW; i ++){
        for(int j = 1; j < COL; j ++){
            pArray[i][j].type = 1;
        }
    }
    pArray[2][4].type = 0;
    pArray[3][3].type = 0;
    pArray[4][3].type = 0;
}

void setNumber(){
    int count = 1;
    for(int i = 1; i < ROW; i ++){
        for(int j = 1; j < COL; j ++){
            pArray[i][j].number = count;
            count++;
        }
    }
}

void arrayInit(){
    setXY();
    setType();
    setNumber();
}

vector<int>dirs = {0,1,0,-1,0};

int main(){
    arrayInit();
    
   
    queue<Point*> que;
    Point* start = &pArray[startXY.first][startXY.second];
    Point* end = &pArray[endXY.first][endXY.second];
    
    int goalNum = end->number;

    que.push(start);
    start->isVisited = true;
    
    bool flag = false;

    while(!que.empty()){
        Point* pre = que.front();
        
        if(pre->number == goalNum){
            flag = true;
            break;
        }
        for(int i = 0; i < 4; i ++){
            Point* next = &pArray[pre->x+dirs[i]][pre->y+dirs[i+1]];
            
            if(next->type == 1 && !next->isVisited){
                next->isVisited = true;
                que.push(next);
                next->pre = &(*pre);//最关键的一步！！！！
            }
        }
        que.pop();
    }
    
    if(!flag){
        cout<<"no matching"<<endl;
    }
    else{
        vector<int> path;
        Point end = pArray[endXY.first][endXY.second];
        int init = end.number;
        Point* tmp = &end;
        while(tmp->number != 1){
            path.push_back(tmp->number);
            tmp = tmp->pre;
        }
        path.push_back(1);

        int n = path.size();
        cout<<endl;
        for(int i = n-1; i >=0; i--){
            cout<<path[i]<<'\t';
        }
        cout<<endl;
    }
}



