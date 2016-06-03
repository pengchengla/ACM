/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-24
*   描    述：
================================================================*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        return binSearch(matrix,target,0,0,matrix.size()-1,matrix[0].size()-1);
    }
private:
    bool binSearch(vector<vector<int> >& matrix,int target,int top,int left,int bottom,int right){
        if(left>right || top>bottom) 
            return false;
        int x = (top+bottom)/2;
        int y = (left+right)/2;
        int center = matrix[x][y];

        if(center>target){
            return binSearch(matrix,target,top,left,x-1,right) || 
                   binSearch(matrix,target,x,left,bottom,y-1);
        }else if(center<target){
            return binSearch(matrix,target,top,y+1,bottom,right) || 
                   binSearch(matrix,target,x+1,left,bottom,y);
        }else{
            return true;
        }
    }
};

int main(){
    return 0;
}
