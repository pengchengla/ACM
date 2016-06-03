#include <iostream>
#include <algorithm>
using namespace std;

const int MAX=101;
const int K=6;
int dp[MAX][MAX][K];

struct thing{
	int price;
	int score;
	int value;
};

thing things[MAX];

int main(){
#ifdef ONLINE_JUDGE
#else
	freopen("in.txt","r",stdin);
#endif
	int n,v1,v2,k;
	while(cin>>n>>v1>>v2>>k){
		for(int i=0;i<n;i++)
			cin>>things[i].price>>things[i].score>>things[i].value;
		memset(dp,0,sizeof(dp));

		for(int i=0;i<n;i++){
			for(int l1=v1;l1>=0;l1--){
				for(int l2=v2;l2>=0;l2--){
					for(int l3=k;l3>=0;l3--){
						int tmp = 0;
						if(things[i].price<=l1)
							tmp=max(tmp,dp[l1-things[i].price][l2][l3]+things[i].value);
						if(things[i].score<=l2)
							tmp=max(tmp,dp[l1][l2-things[i].score][l3]+things[i].value);
						if(l3>=1)
							tmp=max(tmp,dp[l1][l2][l3-1]+things[i].value);
						dp[l1][l2][l3]=max(tmp,dp[l1][l2][l3]);
					}
				}
			}
		}
		cout<<dp[v1][v2][k]<<endl;
	}
	return 0;
}
