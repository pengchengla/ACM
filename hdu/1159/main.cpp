/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-07
*   描    述：
================================================================*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define LEN 1003
int dp[LEN][LEN];
int main(){
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif
    string fir,sec;
    while(cin>>fir>>sec){
        memset(dp,0,sizeof(dp));
        int len1 = fir.length();
        int len2 = sec.length();
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(fir[i-1]==sec[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        cout<<dp[len1][len2]<<endl;
    }
    return 0;
}
