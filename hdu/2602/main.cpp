/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-08-11
*   描    述：
================================================================*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define NUM 1003

int main(){
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif
    int cost[NUM];
    int value[NUM];
    int f[NUM];

    int tc; cin>>tc;
    while(tc--){
        memset(f,0,sizeof(f));
        int n,v;
        cin>>n>>v;
        for(int i=0;i<n;i++) cin>>value[i];
        for(int i=0;i<n;i++) cin>>cost[i];
        memset(f,0,sizeof(f));
        for(int i=0;i<n;i++){
            for(int j=v;j>=cost[i];j--){
                f[j]=max(f[j],f[j-cost[i]]+value[i]);
            }
        }
        cout<<f[v]<<endl;
    }
    return 0;
}
