#include <iostream>
#include <string>
#include <vector>
#include <bitset>
using namespace std;

#define MAX 101
int m, ok, j, order[MAX];
int flag[MAX][MAX];
bitset<MAX> digit[MAX];//存放每个城市能到达的所有城市，能到达不是两城市间必须有路
vector<int> u[MAX];//存放每个城市有路连接的所有城市

//预处理出每个节点的子树中能达到的节点
void canReach(int a, int v){
    digit[a][a] = 1;
    for(int i = 0; i < u[a].size(); i++){
        int b = u[a][i];
        if(b == v) continue;
        canReach(b, a);
        digit[a] |= digit[b];////子节点能到达的点,当前点也能到,用bitset处理可以直接用或运算比较快捷
    }
}

void dfs(int a, int v){
    if(a == order[j]) j++;
    if(j == m){
        ok = 1;
        return;
    }
    while(j < m){
        int p = j, c = order[j];
        for(int i = 0; i < u[a].size(); i++){
            int b = u[a][i];
            if(b == v) continue;
            if(digit[b][c] && flag[a][b]){//如果b能到达c并且a、b之间有路
                flag[a][b] = 0;
                dfs(b, a);
                break;
            }
        }
        if(p == j) break;//表示以该节点为根的子树不存在目标点，跳出循环，（然后返回递归上一层）
    }
}

int main(void){
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif
    int a, b, i, t, n;
    cin>>t;
    while(t--){
        ok = j = 0;
        //memset(flag, 0, sizeof flag);
        for(i = 0; i < MAX; i++){
            digit[i].reset();
            u[i].clear();
        }
        cin>>n;
        for(i = 1; i < n; i++){
            cin>>a>>b;
            u[a].push_back(b);
            u[b].push_back(a);
            flag[a][b] = flag[b][a] = 1;
        }
        cin>>m;
        for(i = 0; i < m; i++) cin>>order[i];
        canReach(1, -1);
        dfs(1, -1);
        if(ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
