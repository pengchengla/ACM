#include <iostream>
#include <string>
using namespace std;

const int rows = 100 + 3;
int m,n;
char total[rows][rows];
bool visited[rows][rows];
int bx,by;
int k;
int dire[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

bool judge(int tx,int ty){
    if(tx>=0 && tx<=m && ty>=0 && ty<=n && !visited[tx][ty] && total[tx][ty]=='.'){
        return true;
    }
    return false;
}

bool dfs(int x, int y, int drec, int num){
    bool flag;
    visited[x][y]=true;
    if(x==bx && y==by) return true;
    if(num>=k) return false;
    for(int i=0;i<4;i++){
        int tx = dire[i][0] + x;
        int ty = dire[i][1] + y;
        if(judge(tx,ty)){
            if(drec==i || drec==i)
                flag = dfs(tx,ty,i,num);
            else
                flag = dfs(tx,ty,i,num+1);
            visited[tx][ty] = false;
            if(flag)
                return flag;
        }
    }
    return false;
}

int main()
{
#ifdef ONLINE_JUDGE
#else
	freopen("in.txt", "r", stdin);
#endif
    int x,y;
    int tc;
    cin >> tc;
    while(tc--){
        cin >> m >> n;
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
                cin>>total[i][j];
        
        memset(visited,0,sizeof(visited));
        cin>>k>>x>>y>>bx>>by;
        string ans = dfs(x,y,-1,0) ? "yes" : "no";
        cout<<ans<<endl;
    }
	return 0;
}
