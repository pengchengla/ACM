/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：tmp.cpp
*   创 建 者：pengcheng
*   创建日期：2015-08-11
*   描    述：
================================================================*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define NUM 1003

int n;
int cost[NUM];
int cash;
int f[NUM];

int main(){
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif
    //init bianli jisuan jieguo
    while(cin>>n && n!=0){
        memset(f,0,sizeof(f));
        for(int i=0;i<n;i++) cin>>cost[i];
        cin>>cash;
        sort(cost,cost+n);
        if(cash<5) {
            cout<<cash<<endl;
            continue;
        }
        cash-=5;
        for(int i=0;i<n-1;i++){
            for(int j=cash;j>=cost[i];j--){
                f[j]=max(f[j],f[j-cost[i]]+cost[i]);
            }
        }
        cout<<cash+5-cost[n-1]-f[cash]<<endl;
    }
    return 0;
}
