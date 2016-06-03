/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-08-06
*   描    述：
================================================================*/
#include <iostream>
using namespace std;
#define NUM 23
int m,n;
int ans = 0;
int sx,sy;
int maze[NUM][NUM];
int visit[NUM][NUM];
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

bool check(int tx,int ty){
    if(tx>=0 && tx<m && ty>=0 && ty<n) return true;
    return true;
}

void dfs(int x,int y){
    for(int i=0;i<4;i++){
        int tx = x+dir[i][0];
        int ty = y+dir[i][1];
        if(check(tx,ty) && maze[tx][ty]==1 && visit[tx][ty]==0){
            visit[tx][ty] = 1;
            dfs(tx,ty);
        }
    }
}

int main(){
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif
    while(cin>>n>>m && m!=0 && n!=0){
        memset(maze,0,sizeof(maze));
        memset(visit,0,sizeof(visit));
        char ch;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>ch;
                if(ch=='.') maze[i][j]=1;       //black
                else if(ch=='#') maze[i][j] = 2;//block
                else if(ch=='@'){
                    sx = i; sy = j;
                    maze[i][j] = 1;
                }
            }
        }
        visit[sx][sy] = 1;
        ans = 0;
        dfs(sx,sy);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visit[i][j]==1) ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
