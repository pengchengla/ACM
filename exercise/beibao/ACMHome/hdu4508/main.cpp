#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct food{
	food(){}
	food(int l,int e){love=l;energy=e;}
	int love;
	int energy;
};

int kind;
food foods[101];
int volume;
int dp[100001];

int handle(){
	memset(dp,0,sizeof(dp));
	for(int i=0;i<kind;i++){
		for(int j=foods[i].energy;j<=volume;j++){
			dp[j]=max(dp[j],dp[j-foods[i].energy]+foods[i].love);
		}
	}
	return dp[volume];
}

int main(){
#ifdef ONLINE_JUDGE
#else
	freopen("in.txt","r",stdin);
#endif
	int tc=0;
	while(cin>>kind){
		for(int i=0;i<kind;i++)
			cin>>foods[i].love>>foods[i].energy;
		cin>>volume;
		cout<<handle()<<endl;
	}
	return 0;
}
