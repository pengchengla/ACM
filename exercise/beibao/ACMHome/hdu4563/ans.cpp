#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#define inf 1<<30
#define NN 105
using namespace std;

const double PI = acos(-1.0);
typedef long long LL;

/**
1.除了最后一个命令，其他命令的执行时间必然是整秒，所以枚举每个命令作为最后一个命令的情况
2.剩下n-1条命令抽象成01背包
3.n个命令抽象成n个物品，l表示背包体积，vxi表示第i件物品的体积，vyi表示物品的价值，运行时间表示物品数量
**/

struct Node{
    int x,y;
}v[NN];
double dp[NN];
int N,V;
double g = -9.8;//好怀恋的重力加速度=。=

double fun(int o){
    for (int i = 0;i < NN;i++)
        dp[i] = -inf;
    dp[0] = 0;
    for (int i = 0;i < N;i++){
        if (o == i)//保留最后一条命令
            continue;
        for (int j = V;j >= 0;j--){
            for (int t = 0;t <= j/v[i].x;t++){//除了最后一条命令，其他命令执行时间都是整的
                dp[j] = max (dp[j],dp[j-v[i].x*t] + v[i].y*t + 0.5*g*t*t );//h = vt+(1/2)gt^2
            }
        }
    }
    double ans = - inf;
    for (int i = 0;i <= V;i++){//最后一条命令的处理
        if (dp[i] == -inf) continue;
        double t = (V-i)*1.0/v[o].x;
        ans = max(ans,dp[i] + v[o].y*t + 0.5*g*t*t);//已经到达的高度 加上最后一条指令能到达的高度
    }
    return ans;
}

int main(){
	freopen("in.txt","r",stdin);
    int cas = 0;
    int T; cin>>T;
    while (T--){
		cin>>N>>V;
        for (int i = 0;i < N;i++)
			cin>>v[i].x>>v[i].y;
        double ans = - inf;
        for (int i = 0;i < N;i++)
            ans = max(ans,fun(i));
		cout<<"Case "<<++cas<<": "<<setiosflags(ios::fixed)<<setprecision(3)<<ans<<endl;
    }
    return 0;
}
