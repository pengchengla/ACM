/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-21
*   描    述：
================================================================*/
#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000005];

int main(){
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif
    int tc = 0;
    cin>>tc;
    while(tc--){
        int m,n;    cin>>m>>n;
        int w = n-m;
        int kind;   cin>>kind;

        int price[503]={0};
        int weight[503]={0};
        for(int i=0;i<kind;i++) cin>>price[i]>>weight[i];

        for(int i=0;i<=w;i++) dp[i] = 999999;
        dp[0] = 0;

        for(int i=0;i<kind;i++){
            for(int j=weight[i];j<=w;j++){
                dp[j]=min(dp[j],dp[j-weight[i]]+price[i]);
            }
        }

        if(dp[w]==999999)
            cout<<"This is impossible."<<endl;
        else
            cout<<"The minimum amount of money in the piggy-bank is "<<dp[w]<<"."<<endl;
    }
    return 0;
}
