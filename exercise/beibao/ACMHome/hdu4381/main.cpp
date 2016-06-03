#include <iostream>
using namespace std;

int dp[1001];
struct node{
	int op;
	int cost;
	int value;
};

node total[1001];

int main(){
#ifdef ONLINE_JUDGE
#else
	freopen("in.txt","r",stdin);
#endif
	int tc;cin>>tc;
	int vol,n;
	while(tc--){
		cin>>vol>>n;
		memset(dp,0,sizeof(dp));

		for(int i=0;i<n;i++)
			cin>>total[i].op>>total[i].cost>>total[i].value;

		int diff=0;
		for(int i=0;i<n;i++){
			for(int v=vol;v>=0;v--){
				int tmp1 = dp[v];
				int tmp2 = dp[v-total[i].cost]+total[i].value;
				if(total[i].op==1){
				}
				else{
				}
			}
		}
	}
	return 0;
}
