/*===============================================================
*   Copyright (C) 2014 All rights reserved.
*   文件名称：test1.cpp
*   创 建 者：pengcheng
*   创建日期：2014-11-29
*   描    述：
================================================================*/

#include<iostream>
using namespace std;

int main()
{
    int m=1;
    int n=1;
    int ** dp = (int**)malloc(sizeof(int*)*m);
    for(int i=0;i<n;++i)
        dp[i]=(int*)malloc(sizeof(int)*n);
    dp[0][0]=1;
    for(int i=0;i<m;++i)
        for(int j=0;j<n;++j)
            cout<<dp[i][j]<<endl;
    return 0;
}
