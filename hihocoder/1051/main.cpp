/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-08-03
*   描    述：
================================================================*/
#include <iostream>
#include <cstring>
using namespace std;

#define NUM 100

int main(){
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif
    int tc; cin>>tc;
    while(tc--){
        int flag[NUM];
        int total[NUM];
        memset(flag,0,sizeof(flag));
        memset(total,0,sizeof(total));

        int N,M; cin>>N>>M;
        for(int i=0;i<N;i++) cin>>total[i];
        for(int i=0;i<M;i++) flag[i]=1;
        int tail = M-1;//M
        if(M>=N){
            cout<<100<<endl;
            continue;
        }

        int ans = 0;
        int tmp = 0;
        while(tail<N){
            int pre = 0;
            for(int i=0;i<N;i++){
                if(flag[i]==0){
                    tmp = total[i]-pre;
                    if(tmp>ans) ans=tmp;
                    pre = total[i];
                }
            }
            tail++;
            flag[tail]=1;
            flag[tail-M]=0;
        }
        cout<<ans-1<<endl;
    }
    return 0;
}
