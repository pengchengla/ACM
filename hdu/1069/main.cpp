/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-07
*   描    述：
================================================================*/
#include <iostream>
#include <algorithm>
using namespace std;

struct _node{
    int l;
    int w;
    int h;
}node[1000];
int dp[1000];

bool cmp(const _node & n1, const _node & n2){
    if((n1.l * n1.w)>(n2.l * n2.w)) return 1;
    return 0;
}

int main(){
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif
    int n;
    int l,w,h;
    int ca = 1;
    while(cin>>n && n){
        int count = 0;
        for(int i=0;i<n;i++){
            cin>>l>>w>>h;
            node[count].l=l; node[count].w=w; node[count].h=h; count++;
            node[count].l=l; node[count].w=h; node[count].h=w; count++;
            
            node[count].l=w; node[count].w=l; node[count].h=h; count++;
            node[count].l=w; node[count].w=h; node[count].h=l; count++;
            
            node[count].l=h; node[count].w=w; node[count].h=l; count++;
            node[count].l=h; node[count].w=l; node[count].h=w; count++;
        }
        sort(node,node+count,cmp);
        memset(dp,0,sizeof(dp));
        int ans = 0;
        for(int i=0;i<count;i++){
            dp[i] = node[i].h;
            for(int j=0;j<i;j++){
                if(node[i].l < node[j].l && node[i].w < node[j].w)
                    dp[i] = max(dp[i],dp[j]+node[i].h);
            }
            if(dp[i]>ans) ans=dp[i];
        }
        cout<<"Case "<<ca<<": maximum height = "<<ans<<endl;
        ca++;
    }
    return 0;
}
