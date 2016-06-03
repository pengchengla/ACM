/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-22
*   描    述：
================================================================*/
#include <iostream>
using namespace std;

int main(){
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif
    int N;
    int cost[3]={1,2,3};
    int weight[3]={1,1,1};
    int kind = 3;
    int dp[32770];
    while(cin>>N){
        for(int i=0;i<=N;i++) dp[i]=-999999;
        dp[0] = 0;

        for(int i=0;i<kind;i++){
            for(int j=cost[i];j<=N;j++){
                dp[j]=max(dp[j],dp[j-cost[i]]+weight[i]);
            }
        }
        cout<<dp[N]<<endl;
    }
    return 0;
}
