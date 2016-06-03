/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-08-03
*   描    述：
================================================================*/
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define NUM 100003
#define MOD 142857

int ans[NUM];
vector<int> graph[NUM];
int grade[NUM];

void topscan(int node){
    for(int i=0;i<graph[node].size();i++){
        int child = graph[node][i];
        grade[child]--;
        ans[child]+=ans[node];
        ans[child]%=MOD;
    }
    grade[node]=-1;
}

int main(){
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif
    memset(ans,0,sizeof(ans));
    memset(grade,0,sizeof(grade));
    int N,M,K;
    cin>>N>>M>>K;
    int tmp = 0;
    for(int i=0;i<K;i++){
        cin>>tmp;
        ans[tmp] = 1;
    }
    int u,v;
    for(int i=0;i<M;i++){
        cin>>u>>v;
        graph[u].push_back(v);;
        grade[v]++;
    }
    bool flag = true;
    while(flag){
        flag = false;
        for(int i=1;i<=N;i++){
            if(grade[i]==0){
                flag = true;
                topscan(i);
            }
        }
    }
    int res = 0;
    for(int i=1;i<=N;i++){
        res+=ans[i];
        res%=MOD;
    }
    cout<<res<<endl;
    return 0;
}
