#include <iostream>
#include <string>
#include <bitset>
#include <vector>
using namespace std;

#define N 101
int ok = 0;
int order[N];
int flag[N][N];//矩阵 存储树结构
vector<int> map[N];//链接 存储树结构
bitset<N> route[N];//存储每个节点的可达路径

void get_route(int father,int from){
	route[father][father] = 1;
	for(int i=0;i<map[father].size();i++){
		int child = map[father][i];
		if(child==from) continue;
		get_route(child,father);
		route[father] |= route[child];
	}
}

int j = 0;
int m = 0;
void dfs(int cur,int from){
	if(cur==order[j]) j++;
	if(j==m){
		ok=1; 
		return;
	}
	while(j<m){
		int tmp=j; int t=order[j];
		for(int i=0;i<map[cur].size();i++){
			int child = map[cur][i];
			if(child==from) continue;
			if(route[child][t] && flag[cur][child]){
				flag[cur][child] = 0;
				dfs(child,cur);
				//break;
			}
		}
		if(tmp==j) break;
	}
}

int main(){
#ifdef ONLINE_JUDGE
#else
	freopen("in.txt","r",stdin);
#endif
	int tc; cin>>tc;
	while(tc--){
		ok = 0; j = 0;
		int n; cin>>n;
		int a,b;
		for(int i=0;i<N;i++){
			map[i].clear();
			route[i].reset();
			order[i]=0;
			for(int j=0;j<N;j++) flag[i][j] = 0;
		}
		for(int i=1;i<n;i++){
			cin>>a>>b;
			flag[a][b] = flag[b][a] = 1;
			map[a].push_back(b);
			map[b].push_back(a);
		}
		cin>>m;
		for(int i=0;i<m;i++) cin>>order[i];
		get_route(1,-1);
		dfs(1,-1);
		if(ok) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
