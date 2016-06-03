/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-28
*   描    述：
================================================================*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        if(row==0 && col==0) return false;
        //
        row-=1; col-=1;
        int high = 0;
        int low = row;
        int mid = (low+high)/2;
        while(!(matrix[mid][0]<=target && matrix[mid][col]>=target) && high<=low){
            if(matrix[mid][0]>target) low = mid-1;
            else if(matrix[mid][0]<target) high = mid+1;
            else return true;
            if(low<0||high>row) return false;
            mid = (low+high)/2;
        }
        if(!(matrix[mid][0]<=target && matrix[mid][col]>=target)) return false;
        int realRow = mid;
        int left = 0;
        int right = col;
        mid = col/2;
        while(matrix[realRow][mid]!=target && left<=right){
            if(matrix[realRow][mid]>target) right = mid-1;
            else if(matrix[realRow][mid]<target) left = mid+1;
            if(left>col || right<0) return false;
            mid = (left+right)/2;
        }
        if(matrix[realRow][mid]==target) return true;
        return false;
    }
};

int main(){
    return 0;
}
