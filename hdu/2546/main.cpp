/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-06-19
*   描    述：
================================================================*/
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif
    int kind;
    int cost[1003];
    int f[1003];
    int money;
    while(cin>>kind && kind){
        memset(cost,0,sizeof(cost));
        memset(f,0,sizeof(f));
        for(int i=0;i<kind;i++) cin>>cost[i];
        cin>>money;
        for(int i=0;i<kind;++i){
            int tmp = min(cost[i],5);
            for(int v=money;v>=tmp;v--){
                f[v] = max(f[v],f[v-cost[i]]+cost[i]);
            }
        }
        cout<<money-f[money]<<endl;
    }
    return 0;
}
