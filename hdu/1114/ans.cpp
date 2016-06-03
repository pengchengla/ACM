/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：ans.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-22
*   描    述：
================================================================*/
#include <algorithm>
#include <iostream>
using namespace std;

int dp[1000005];

int main()
{
    int t;
    int wa,wb,w;
    int n,val[505],wei[505],i,j;
    cin>>t;
    while(t--)
    {
        cin>>wa>>wb;
        w = wb-wa;//必须减去小猪本身重量
        cin>>n;
        for(i = 0;i<n;i++) cin>>val[i]>>wei[i];

        for(i = 0;i<=w;i++) dp[i] = 10000000;//因为要求小的，所以dp数组必须存大数
        dp[0] = 0;

        for(i = 0;i<n;i++){
            for(j = wei[i];j<=w;j++){
                dp[j] = min(dp[j],dp[j-wei[i]]+val[i]);
            }
        }
        if(dp[w] == 10000000) cout<<"This is impossible."<<endl;
        else cout<<"The minimum amount of money in the piggy-bank is "<<dp[w]<<"."<<endl;
    }
    return 0;
}
