#include <iostream>
using namespace std;

struct comd{
	int vx;
	int vy;
	comd(int x,int y){
		vx=x;
		vy=y;
	}
};

int main(){
#ifdef ONLINE_JUDGE
#else
	freopen("in.txt","r",stdin);
#endif
	comd comds[101];
	int dp[101];
	int tc;cin>>tc;
	while(tc--){
		dp[0]=0;
		for(int i=1;i<101;i++) dp[i]=-100;

		int comds;cin>>comds;
		int dis;cin>>dis;
		for(int i=0;i<comds;i++){
			cin>>comds[i].vx>>comds[i].vy;
		}

		for(int i=0;i<comds;i++){
			for(int j=dis;j>=comds[i].vx;j--){
				dp[j]=max(dp[j],dp[j-comds[i].vx]+comds[i].vy);
			}
		}
	}
	return 0;
}
