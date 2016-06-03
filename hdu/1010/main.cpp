/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-06-18
*   描    述：
================================================================*/

#include <iostream>
#include <string>
using namespace std;

struct node{
    int x;
    int y;
};

const int rows = 10;
char total[rows][rows];
bool visited[rows][rows];
int drec[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int m,n,t;
node dest;

bool judge(int tx,int ty){
    if((tx>=0 && tx<=m && ty>=0 && ty<=n && !visited[tx][ty]) && (total[tx][ty]=='.'||(tx==dest.x && ty==dest.y)))
        return true;
    return false;
}

bool dfs(int x,int y,int num){
    visited[x][y]=true;
    if(num==t && x==dest.x && y==dest.y) return true;//恰巧t秒到达地点
    if(num>=t) return false;
    //01
    int tmp = (t-num) - abs(x-dest.x) - abs(y-dest.y);
    if(tmp<0 || tmp&1) return false;
    for(int i=0;i<4;i++){
        int tx = x + drec[i][0];
        int ty = y + drec[i][1];
        if(judge(tx,ty)){
            if(dfs(tx,ty,num+1)) return true;
            visited[tx][ty]=false;
        }
    }
    return false;
}

int main(){
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif
    node start;
    start.x=start.y=dest.x=dest.y=0;
    while(cin>>m>>n>>t){
        int dotNum=0;
        if(m==0 && n==0 && t==0) break;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>total[i][j];
                if(total[i][j]=='S'){
                    start.x=i;
                    start.y=j;
                }
                else if(total[i][j]=='D'){
                    dest.x=i;
                    dest.y=j;
                }
                else if(total[i][j]=='X'){
                    dotNum++;
                }
            }
        }
        if(m*n-dotNum <= t) {
            cout<<"NO"<<endl;
            continue;
        }
        memset(visited,0,sizeof(visited));
        string ans = dfs(start.x,start.y,0) ? "YES" : "NO";
        cout<<ans<<endl;
    }
    return 0;
}
