#include<iostream>
#include<queue>
#include<vector>
#define ROW 7
#define COL 7
using namespace std;

class Point{
friend class PointMap;
friend class cmp;
public:
    int x;
    int y;
    int type;
    int number;
    int originCost;
    int heuristicCost;
    bool isVisited;
    Point* pre;

    Point():type(0),isVisited(false),pre(nullptr),originCost(INT_MAX){};
};


class PointMap{
private:
    int row;
    int col;
    void setMap(int row,int col);
    void setType(int i,int j,int posi,int posj);
    
public:    
    vector<vector<Point*>>pArray;

    PointMap() = default;
    PointMap(int a,int b):row(a),col(b){
        setMap(a,b);
    }


};

pair<int,int> startXY = pair<int,int>(1,1);
pair<int,int> endXY = pair<int,int>(2,5);

void PointMap::setMap(int row, int col){
    int m = row + 2;
    int n = col + 2;
    //number
    int number = 1;
    for(int i = 1; i <= row; i ++){
        for(int j = 1; j <= col; j ++){
            pArray[i][j]->x = i;
            pArray[i][j]->y = j;
            pArray[i][j]->number = number;
            pArray[i][j]->heuristicCost = abs(endXY.first+endXY.second-i-j);
            number++;
        }
    }
    //type;
    setType(0,0,m-1,0);
    setType(0,n-1,m-1,n-1);
    setType(0,0,0,n-1);
    setType(m-1,0,m-1,n-1);
    
    pArray[startXY.first][startXY.second]->type = 1;
    pArray[endXY.first][endXY.second]->type = 1;

    setType(4,1,4,2);
    setType(5,2,6,2);
    setType(1,4,5,4);
    setType(5,5,5,5);

}

void PointMap::setType(int m, int n,int posm,int posn){
    for(int i = m; i <= posm; i++){
        for(int j = n; j < posn; j ++){
            pArray[i][j]->type = 1;
        }
    }
}
//smaller-to-larger
class cmp{
public:
    bool operator()(const Point* &a,const Point* &b){
        int cost_a = a->originCost + a->heuristicCost;
        int cost_b = b->originCost + b->heuristicCost;
        return cost_a > cost_b;
    }
};


vector<int>dirs = {0,1,0,-1,0};
int main(){
    priority_queue<Point*,vector<Point*>,cmp>que;
    PointMap M;

    Point* start = M.pArray[startXY.first][startXY.second];
    Point* end = M.pArray[endXY.first][endXY.second];
    start->originCost = 0;
    
    que.push(start);
    while(!que.empty()){
        Point* ori = que.top();
        if(ori->number == end->number)break;
        for(int i = 0; i < 4; i ++){
            Point* tmp = M.pArray[ori->x + dirs[i]][ori->y + dirs[i+1]];
            int tmp_oriCost = tmp->originCost;
            int new_oriCost = ori->originCost + 1;
            if(tmp->type == 0 && (!tmp->isVisited || tmp_oriCost < new_oriCost)){
                tmp->originCost = new_oriCost;
                tmp->isVisited = true;
                tmp->pre = &(*ori);
                que.push(tmp);
            }
            
        }
        que.pop();
    }



}
