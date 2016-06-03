#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<queue>
using namespace std;

int M; //棋盘大小
struct Node
{
       int x,y,step;
};

int dir[8][2]={ {-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1} };
int sx,sy,ex,ey;
int vis[305][305];
int bfs()
{
    queue<Node>q;
    Node temp,cur;
    temp.x=sx, temp.y=sy, temp.step=0;
    vis[sx][sy]=1;
    q.push(temp);
    while(!q.empty())
    {
        cur=q.front();
        q.pop();
        for(int i=0;i<8;i++)
        {
            int x=cur.x+dir[i][0],y=cur.y+dir[i][1],step=cur.step+1;
            if(x==ex && y==ey)
                return step;
            if(!vis[x][y] && x>=0 && x<M && y>=0 && y<M)
            {
                vis[x][y]=1;
                temp.x=x, temp.y=y, temp.step=step;
                q.push(temp);
            }
        }
    }
    return -1;
}

int main()
{
    freopen("data","r",stdin);
    freopen("ans2","w",stdout);
    int Case;
    scanf("%d",&Case);
    while(Case--)
    {
         scanf("%d",&M);
         scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
         memset(vis,0,sizeof(vis));
         if(sx==ex && sy==ey)
             puts("0");
         else
             printf("%d\n",bfs());
    }
    return 0;
}

