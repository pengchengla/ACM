/*===============================================================
*   Copyright (C) 2014 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2014-11-29
*   描    述：
================================================================*/

#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
public:
    int minPathSum(vector<vector<int> > &grid) 
    {
        int m = grid.size();
        if(m==0)    return 0;
        int n = grid[0].size();
        if(n==0)    return 0;
        int ** dp = (int**)malloc(sizeof(int*)*m);
        for(int i=0;i<m;++i)
            dp[i] = (int*)malloc(sizeof(int)*n);
        memset(dp,sizeof(int)*m*n,0);
        m--;n--;
        for(int i=n;i>=0;--i)
        {
            if(i==n)    dp[m][i] = grid[m][i];
            else    dp[m][i] = grid[m][i]+dp[m][i+1];
        }
        for(int i=n;i>=0;--i)
        {
            for(int j=m-1;j>=0;--j)
            {
                if(i==n)
                {
                    dp[j][i] = grid[j][i]+dp[j+1][i];
                }
                else
                {
                    dp[j][i] = grid[j][i]+( dp[j+1][i]>dp[j][i+1]?dp[j][i+1]:dp[j+1][i] );
                }
            }
        }
        return dp[0][0];
    }
};

int main()
{
    vector<int> v1;
    v1.push_back(1);
    vector< vector<int> > v;
    v.push_back(v1);
    Solution * solution = new Solution();
    cout<<solution->minPathSum(v)<<endl;
    return 0;
}
