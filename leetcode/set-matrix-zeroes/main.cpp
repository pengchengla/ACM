/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-28
*   描    述：
================================================================*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Point{
    Point(int xx,int yy){
        x = xx;
        y = yy;
    }
    int x;
    int y;
};

class Solution {
public:
    void setZeroes(vector<vector<int> >& matrix) {
        queue<Point> qu;
        int row = matrix.size();
        int col = matrix[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==0){
                    qu.push(Point(i,j));
                }
            }
        }
        while(!qu.empty()){
            Point pp = qu.front();
            for(int k=0;k<col;k++) matrix[pp.x][k] = 0;
            for(int k=0;k<row;k++) matrix[k][pp.y] = 0;
            qu.pop();
        }
    }
};

int main(){
    return 0;
}
