/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-13
*   描    述：
================================================================*/
#include <iostream>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[101][101];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++) dp[1][i] = 1;
        for(int i=1;i<=m;i++) dp[i][1] = 1;

        for(int i=2;i<=m;i++){
            for(int j=2;j<=n;j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m][n];
    }
};

int main(){
    return 0;
}
