/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-08-05
*   描    述：
================================================================*/
#include <iostream>
#include <algorithm>
using namespace std;

int total[101][101];
int dp[101][101];

int main(){
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif
    int tc; cin>>tc;
    while(tc--){
        memset(total,0,sizeof(total));
        memset(dp,0,sizeof(dp));
        int N; cin>>N;
        for(int i=0;i<N;i++){
            for(int j=0;j<i+1;j++){
                cin>>total[i][j];
                if(i==N-1) dp[i][j] = total[i][j];
            }
        }
        for(int i=N-2;i>=0;i--){
            for(int j=0;j<i+1;j++){
                dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+total[i][j];
            }
        }
        cout<<dp[0][0]<<endl;
    }
    return 0;
}
