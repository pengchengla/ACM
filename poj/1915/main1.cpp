#include <iostream>
#include <queue>
using namespace std;

typedef struct pos
{
    int x;
    int y;
    int ans;
    pos(){ans=0;}
}pos;

int visit[300][300];
int dir[8][2] = {{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};
int bfs(int len,pos & start,pos & end)
{
    int ans = 0;
    queue<pos> qu;
    qu.push(start);
    visit[start.x][start.y]=1;
    int tx,ty;
    pos cur;
    while(!qu.empty())
    {
        pos tmp = qu.front();
        qu.pop();
        ans = tmp.ans;
        if(tmp.x==end.x && tmp.y==end.y)
        {
            break;
        }
        else
        {
            for(int i=0;i<8;i++)
            {
                tx = tmp.x + dir[i][0];
                ty = tmp.y + dir[i][1];
                if(visit[tx][ty]||tx<0||tx>=len||ty<0||ty>=len)
                    continue;
                cur.x = tx; cur.y = ty; cur.ans = tmp.ans+1;
                qu.push(cur);
                visit[tx][ty]=1;
            }
        }
    }
    return ans;
}

int main()
{
    //freopen("file","r",stdin);
    //freopen("ans1","w",stdout);
    int tc;
    cin>>tc;
    while(tc--)
    {
        memset(visit,0,sizeof(int)*300*300);
        int len = 0;
        cin>>len;
        pos start;
        pos end;
        cin>>start.x>>start.y>>end.x>>end.y;
        int ans = bfs(len,start,end);
        cout<<ans<<endl;
    }
    return 0;
}
