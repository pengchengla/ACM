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

int main(){
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt", "r", stdin);
#endif
    int total[1003];
    int count = 0;
    while(cin>>count && count!=0){
        int re = INT_MIN;
        int dp[1003]={0};
        memset(total,0,sizeof(total));
        for(int i=1;i<=count;i++) cin>>total[i];

        for(int i=1;i<=count;i++){
            int ans = INT_MIN;
            for(int j=0;j<i;j++){
                if(total[i]>total[j]){
                    ans = max(ans,dp[j]);
                }
            }
            dp[i] = ans + total[i];
            if(dp[i]>re) re = dp[i];
        }
        cout<<re<<endl;
    }
    return 0;
}
