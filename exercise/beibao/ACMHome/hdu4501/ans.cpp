#include<iostream>
using namespace std;

int dp[2][105][105][10];
int c1[105];
int c2[105];
int val[105];

int main(){
#ifdef ONLINE_JUDGE
#else
	freopen("in.txt","r",stdin);
#endif
	int n,v1,v2,k;
	while(cin>>n>>v1>>v2>>k){
		int i;
		for(i=1;i<=n;i++)
			cin>>c1[i]>>c2[i]>>val[i];
		memset(dp,0,sizeof(dp));

		int now=0;
		for(i=1;i<=n;i++){
			now=now^1;
			for(int l1=0;l1<=v1;l1++){
				for(int l2=0;l2<=v2;l2++){
					for(int kk=0;kk<=k;kk++){
						dp[now][l1][l2][kk]=dp[now^1][l1][l2][kk];

						if(l1>=c1[i]&&dp[now][l1][l2][kk]<dp[now^1][l1-c1[i]][l2][kk]+val[i])
							dp[now][l1][l2][kk]=dp[now^1][l1-c1[i]][l2][kk]+val[i];

						if(l2>=c2[i]&&dp[now][l1][l2][kk]<dp[now^1][l1][l2-c2[i]][kk]+val[i])
							dp[now][l1][l2][kk]=dp[now^1][l1][l2-c2[i]][kk]+val[i];

						if(kk>=1&&dp[now][l1][l2][kk]<dp[now^1][l1][l2][kk-1]+val[i])
							dp[now][l1][l2][kk]=dp[now^1][l1][l2][kk-1]+val[i];
					}
				}
			}
		}
		cout<<dp[now][v1][v2][k]<<endl;
	}
}
