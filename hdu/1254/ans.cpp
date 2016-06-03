/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：ans.cpp
*   创 建 者：pengcheng
*   创建日期：2015-08-06
*   描    述：
================================================================*/
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <queue>
using namespace std;

const int M = 8;
const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,-1,1};
int maze[M][M];

int n, m;

int Bx, By, Mx, My;
int Nx, Ny;
int flag[M][M], total[M][M][M][M];

struct node{
    int Bx, By;
    int Mx, My;
    int step;
};

int check(int x, int y){
    if(x >= 0 && x < n && y >= 0 && y < m && maze[x][y] != 1) return 1;
        return 0;
}

bool dfs(int Nx, int Ny, int Mx, int My){
    if(Nx == Mx && Ny == My){
        return true;
    }
    for(int i = 0; i < 4 && !Found; i++){
        int x = Nx + dx[i];
        int y = Ny + dy[i];
        if(check(x, y) && !flag[x][y]){
            flag[x][y] = 1;
            if(dfs(x, y, Mx, My)) return true;
            flag[x][y] = 0;
        }
    }
    return false;
}

void bfs(int Bx, int By, int Mx, int My){
    queue<node> Q;
    node p, q;
    p.Bx = Bx, p.By = By, p.Mx = Mx, p.My = My, p.step = 0;
    Q.push(p);
    while(!Q.empty()){
        p = Q.front(); Q.pop();
        if(maze[p.Bx][p.By] == 3){
            printf("%d\n", p.step);
            return ;
        }
        for(int i = 0; i < 4; i++){
            q = p;
            q.Bx += dx[i];
            q.By += dy[i];
            Nx = p.Bx-dx[i];
            Ny = p.By-dy[i];   //箱子对面的坐标
            if(check(q.Bx, q.By)&& check(Nx, Ny) && !total[q.Bx][q.By][Nx][Ny]){  //check(Nx, Ny)
                memset(flag, 0, sizeof(flag));
                flag[p.Bx][p.By] = flag[Nx][Ny] = 1;   //标记起点与箱子，确保人不能走过。 
                if(dfs(Nx, Ny, p.Mx, p.My)){
                    total[q.Bx][q.By][Nx][Ny] = 1;
                    q.Mx = Nx, q.My = Ny;
                    q.step++;
                    Q.push(q);
                }
            }
        }
    }
    printf("-1\n");
    return ;
}

void init(){
    memset(total, 0, sizeof(total));
    memset(maze, 0, sizeof(maze));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>maze[i][j];
            if(maze[i][j] == 2){
                Bx = i;
                By = j;
            }
            if(maze[i][j] == 4){
                Mx = i;
                My = j;
            }
        }
    }
}

int main(){
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif
    int T; cin>>T;
    while(T--){
        cin>>n>>m;
        init();
        bfs(Bx, By, Mx, My);
    }
    return 0;
}
