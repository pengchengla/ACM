/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-30
*   描    述：
================================================================*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <climits>
#include <vector>
#include <queue>
#include <cstdlib>
#include <string>
#include <set>
#include <stack>
#include <map>
#define LL long long
#define pii pair<int,int>
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 10010;
struct arc{
    int to,next;
    arc(int x = 0,int y = -1){
        to = x;
        next = y;
    }
};
arc e[maxn<<2];
int head[maxn],ans[maxn],uf[maxn],tot,cnt,n,m;
map<string,int>mp;
vector< pii >q[maxn];
bool vis[maxn];
void init(){
    for(int i = 0; i < maxn; ++i){
        head[i] = -1;
        q[i].clear();
        vis[i] = false;
        ans[i] = -1;
    }
    tot = 0;
    cnt = 1;
    mp.clear();
}
void add(int u,int v){
    e[tot] = arc(v,head[u]);
    head[u] = tot++;
}
int Find(int x){
    if(x != uf[x]) uf[x] = Find(uf[x]);
    return uf[x];
}
void tarjan(int u,int fa){
    uf[u] = u;
    for(int i = head[u]; ~i; i = e[i].next){
        if(e[i].to == fa) continue;
        if(!vis[e[i].to]){
            tarjan(e[i].to,u);
            uf[Find(e[i].to)] = u;
        }
    }
    vis[u] = true;
    for(int i = q[u].size()-1; i >= 0; i--)
        if(vis[q[u][i].first]) ans[q[u][i].second] = Find(q[u][i].first);
}
string name[maxn],fa,son;
int main() {
    int u,v;
    while(~scanf("%d",&n)){
        init();
        for(int i = 0; i < n; ++i){
            cin>>fa>>son;
            if(mp[fa]) u = mp[fa];
            else{
                mp[fa] = cnt;
                name[cnt] = fa;
                u = cnt++;
            }
            if(mp[son]) v = mp[son];
            else{
                mp[son] = cnt;
                name[cnt] = son;
                v = cnt++;
            }
            add(u,v);
            add(v,u);
        }
        scanf("%d",&m);
        for(int i = 0; i < m; ++i){
            cin>>fa>>son;
            u = mp[fa];
            v = mp[son];
            q[u].push_back(make_pair(v,i));
            q[v].push_back(make_pair(u,i));
        }
        tarjan(1,-1);
        for(int i = 0; i < m; ++i)
            cout<<name[ans[i]]<<endl;
    }
    return 0;
}
