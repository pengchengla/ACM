/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：ans.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-07
*   描    述：
================================================================*/
#include<iostream>
#include<algorithm>
using namespace std;
struct Node{
    int l,w,h;
}node[1000];
int dp[1000];

int cmp(const Node &a,const Node &b){
    if(a.l>b.l)return 1;
    if(a.l==b.l&&a.w>b.w)return 1;
    //if((a.l * a.w)>(b.l * b.w)) return 1;
    return 0;
}

int main(){
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif
    int n,x,y,z,_case=1;
    while(scanf("%d",&n)!=EOF){
        if(n==0)break;
        int count=0;
        for(int i=0;i<n;i++){
            scanf("%d%d%d",&x,&y,&z);
            node[count].l=x,node[count].w=y,node[count++].h=z;
            node[count].l=x,node[count].w=z,node[count++].h=y;
            node[count].l=y,node[count].w=x,node[count++].h=z;
            node[count].l=y,node[count].w=z,node[count++].h=x;
            node[count].l=z,node[count].w=x,node[count++].h=y;
            node[count].l=z,node[count].w=y,node[count++].h=x;
        }
        for(int i=0;i<count;i++) cout<<node[i].l<<"  "<<node[i].w<<"  "<<node[i].h<<endl;
        sort(node,node+count,cmp);
        cout<<"================"<<endl;
        for(int i=0;i<count;i++) cout<<node[i].l<<"  "<<node[i].w<<"  "<<node[i].h<<endl;
        memset(dp,0,sizeof(dp));
        int ans = 0;
        for(int i=0;i<count;i++){
            dp[i]=node[i].h;
            for(int j=0;j<=i;j++){
                //符合条件的
                if(node[i].l<node[j].l&&node[i].w<node[j].w){
                    dp[i]=max(dp[i],dp[j]+node[i].h);
                }
                if(dp[i]>ans) ans = dp[i];
            }
        }
        printf("Case %d: maximum height = %d\n",_case++,ans);
    }
    return 0;
}
