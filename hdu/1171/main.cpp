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

int total[5005];
int dp[255555];

int main(){
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif
    int N;
    while(cin>>N && N>=0){
        memset(total,0,sizeof(total));
        memset(dp,0,sizeof(dp));
        int pos = 0;
        int value,count;
        int v=0;
        for(int i=0;i<N;i++){
            cin>>value>>count;
            v+=(value*count);
            while(count--) total[pos++] = value;
        }
        int volume = (v)/2;
        for(int i=0;i<pos;i++){
            for(int j=volume;j>=total[i];j--){
                dp[j]=max(dp[j],dp[j-total[i]]+total[i]);
            }
        }
        cout<<v-dp[volume]<<" "<<dp[volume]<<endl;
    }
    return 0;
}
