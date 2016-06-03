#include <iostream>
#include <string>
using namespace std;
#define MAX 1000+20

int m, n;
int g[MAX][MAX];
bool visited[MAX][MAX];

struct node
{
	int x;
	int y;
};

node a, b;

int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, 1 }, { 0, -1 } };

bool judge(int tx, int ty){
	if ((tx > 0 && tx <= m && ty > 0 && ty <= n && !visited[tx][ty]) && (g[tx][ty] == 0 || (g[tx][ty] != 0 && tx == b.x && ty == b.y))){
		return true;
	}
	return false;
}

bool dfs(int x, int y, int drec, int num)
{
	int i;
	bool flag;
	visited[x][y] = true;
	if (num>2)
		return false;
	if (x == b.x&&y == b.y)
		return true;
	for (i = 0; i<4; i++)
	{
		int tx = x + dir[i][0];
		int ty = y + dir[i][1];
		if (judge(tx,ty))
		{
			if (drec == -1)
				flag = dfs(tx, ty, i, 0);
			else if (drec == i)
				flag = dfs(tx, ty, drec, num);
			else
				flag = dfs(tx, ty, i, num + 1);
			visited[tx][ty] = false;
			if (flag)
				return true;
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
	int i, j, k;
	while (cin >> m >> n&&!(m == 0 && n == 0))
	{
		for (i = 1; i <= m; i++)
			for (j = 1; j <= n; j++)
				cin >> g[i][j];

		cin >> k;
		while (k--)
		{
			cin >> a.x >> a.y >> b.x >> b.y;
			if ((a.x == b.x&&a.y == b.y) || g[a.x][a.y] == 0 || g[a.x][a.y] != g[b.x][b.y])
			{
				cout << "NO" << endl;
				continue;
			}
			memset(visited, 0, sizeof(visited));
			string ans = dfs(a.x, a.y, -1, 0) ? "YES" : "NO";
			cout << ans << endl;
		}
	}
	return 0;
}
