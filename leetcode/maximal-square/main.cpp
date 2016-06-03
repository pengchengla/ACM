/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-08
*   描    述：
================================================================*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char> >& matrix) {
        if(matrix.size()==0) return 0;
        int ans = 0;
        int dp[1000][1000]={0};

        int row = matrix.size();
        int col = matrix[0].size();
        for(int i=0;i<col;i++){
            if(matrix[0][i]=='0') dp[0][i]=0;
            else dp[0][i]=1;
            if(dp[0][i]==1) ans=1;
        }

        for(int i=0;i<row;i++){
            if(matrix[i][0]=='0') dp[i][0]=0;
            else dp[i][0]=1;
            if(dp[i][0]==1) ans=1;
        }

        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++){
                if(matrix[i][j]=='1'){
                    dp[i][j] = getmin(dp[i-1][j-1],dp[i][j-1],dp[i-1][j])+1;
                }
                if(dp[i][j]>ans) ans = dp[i][j];
            }
        }
        return ans*ans;
    }
private:
    int getmin(int a,int b,int c){
        int t;
        if(a>b){t=a;a=b;b=t;}
        if(a>c){t=a;a=c;c=t;}
        if(b>c){t=b;b=c;c=t;}
        return a;
    }
};

int main(){
    return 0;
}
