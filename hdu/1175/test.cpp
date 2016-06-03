#include <iostream>
#include <string>
using namespace std;

struct Point{
	int x;
	int y;
};

int total[1003][1003];
bool visited[1003][1003];
int m, n;
const int direction = 4;
int dir[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

bool judge(Point p, int d){
	p.x += dir[d][0];
	if (p.x < 1 || p.x >m) return false;
	p.y += dir[d][1];
	if (p.y < 1 || p.y > n) return false;

	if (visited[p.x][p.y]) return false;
	return true;
}

bool dfs(Point & start, Point & end){
	if (start.x == end.x && start.y == end.y) return true;

	for (int i = 0; i < direction; ++i){
		if (!judge(start, i)) continue;

		start.x += dir[i][0];
		start.y += dir[i][1];
		visited[start.x][start.y] = true;

		if (dfs(start, end)) return true;

		start.x -= dir[i][0];
		start.y -= dir[i][1];
		visited[start.x][start.y] = false;
	}
	return false;
}

int main(){
#ifdef ONLINE_JUDGE
#else
	freopen("in.txt", "r", stdin);
#endif
	while ((cin >> m >> n) && m != 0 && n != 0){
		for (int i = 1; i <= m; ++i){
			for (int j = 1; j <= n; ++j){
				cin >> total[i][j];
			}
		}

		int tc;
		cin >> tc;
		while (tc--){
			for (int i = 1; i <= m; ++i){
				for (int j = 1; j <= n; ++j){
					if (total[i][j] != 0) visited[i][j] = true;
					else visited[i][j] = false;
				}
			}

			Point p1, p2;
			cin >> p1.x >> p1.y >> p2.x >> p2.y;
			if (total[p1.x][p1.y] != total[p2.x][p2.y] || (p1.x == p2.x && p1.y == p2.y) || visited[p1.x][p1.y] != true || visited[p2.x][p2.y] != true) {
				cout << "NO" << endl;
				continue;
			}

			visited[p1.x][p1.y] = false;
			visited[p2.x][p2.y] = false;

			string str = dfs(p1, p2) ? "YES" : "NO";
			cout << str << endl;
		}
	}
	return 0;
}
