#include <iostream>
using namespace std;

int tree[3011111][2];
int tag=0;
int one[33];

void add(int num){
	int cur=0;
	for(int i=31;i>=0;i--){
		int bit = num&one[i]?1:0;
		if(tree[cur][bit]==-1)
			tree[cur][bit]=++tag;
		cur=tree[cur][bit];
	}
}

int query(int num){
	int cur=0;
	int ans=0;
	for(int i=31;i>=0;i--){
		int bit = num&one[i]?1:0;
		if(tree[cur][bit]==-1) bit^=1;
		cur=tree[cur][bit];
		ans=ans*2+bit;
	}
	return ans;
}

int main(){
#ifdef ONLINE_JUDGE
#else
	freopen("in.txt","r",stdin);
#endif
	one[0]=1;
	for(int i=1;i<33;i++)
		one[i]=2*one[i-1];

	int tc;cin>>tc;
	int num;
	for(int i=1;i<=tc;i++){
		memset(tree,-1,sizeof(tree));
		int n,m;
		cin>>n>>m;
		for(int j=0;j<n;j++){
			cin>>num;
			add(num);
		}
		cout<<"Case #"<<i<<":"<<endl;
		for(int k=0;k<m;k++){
			cin>>num;
			num=num^(one[32]-1);
			cout<<query(num)<<endl;
		}
	}
	return 0;
}
