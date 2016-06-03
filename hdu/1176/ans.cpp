/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：ans.cpp
*   创 建 者：pengcheng
*   创建日期：2015-08-05
*   描    述：
================================================================*/
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

#define MAXT 100010
int dp[14][MAXT];
int n,t;

void init(){
    int x,tt;
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++){
        scanf("%d%d",&x,&tt);
        dp[x+1][tt]++;
        t=max(t,tt);
    }
}

int dps(){
    for(int i=t-1;i>=0;i--){
        for(int j=1;j<=11;j++)
            dp[j][i]=max(dp[j][i+1],max(dp[j+1][i+1],dp[j-1][i+1]))+dp[j][i];
    }
    return dp[6][0];
}

int main(){
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif
    while(cin>>n && n){
        init();
        cout<<dps()<<endl;
    }
    return 0;
}
