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
char maze[NUM][NUM];
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

bool check(int tx,int ty){
    if(tx>=0 && tx<m && ty>=0 && ty<n) return true;
    return true;
}

void dfs(int x,int y){
    for(int i=0;i<4;i++){
        int tx = x+dir[i][0];
        int ty = y+dir[i][1];
        if(check(tx,ty) && maze[tx][ty]=='.'){
            maze[tx][ty]='#';
            ans++;
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
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>maze[i][j];
                if(maze[i][j]=='@'){
                    sx = i; sy = j;
                }
            }
        }
        ans = 1;
        dfs(sx,sy);
        cout<<ans<<endl;
    }
    return 0;
}
