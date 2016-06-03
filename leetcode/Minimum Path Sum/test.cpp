/*===============================================================
*   Copyright (C) 2014 All rights reserved.
*   文件名称：test.cpp
*   创 建 者：pengcheng
*   创建日期：2014-11-29
*   描    述：
================================================================*/

#include<iostream>
using namespace std;

int main()
{
    int m=10;int n=10;
    int **dp = (int**)malloc(sizeof(int*)*m);
    for(int i=0;i<m;++i)
        dp[i]=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<m;i++)
    {   
        for(int j=0;j<n;j++)
        {
            dp[i][j]=0;
        }   
    }   
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<dp[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<sizeof(dp)<<endl;
    int * a;
    cout<<sizeof(a)<<endl;
    return 0;
}
