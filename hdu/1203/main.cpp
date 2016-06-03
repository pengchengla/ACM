/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-08-11
*   描    述：
================================================================*/
#include <iostream>
#include <algorithm>
using namespace std;

#define NUM 10003
int cost[NUM];
double prop[NUM];
double dp[NUM];

int main(){
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif
    int n,m;
    while(cin>>n>>m){
        memset(dp,0,sizeof(dp));
        for(int i=0;i<m;i++) cin>>cost[i];
        for(int i=0;i<m;i++) cin>>prop[i];
        for(int i=0;i<m;i++){
            for(int j=n;j>=cost[i];j--){
                dp[j]=max(dp[j],dp[j-cost[i]]+prop[i]);
            }
        }
        double maxProp = dp[n];
        cout<<maxProp<<endl;
    }
    return 0;
}
