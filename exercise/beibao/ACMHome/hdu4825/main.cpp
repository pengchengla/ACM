#include <iostream>
using namespace std;

int n,m;
int tree[33][2];
int bitv[33];
int tag=0;

void build(int tmp){
	int root=0;
	for(int i=31;i>=0;i--){
		int bit = tmp&bitv[i]?0:1;
		if(tree[root][bit]==-1) 
			tree[root][bit] = ++tag;
		root = tree[root][bit];
	}
}

int query(int value){
	int root = 0;
	int ans = 0;
	for(int i=31;i>=0;i--){
		int bit = value&bitv[i]?0:1;
		if(tree[root][bit]==-1) bit^=1;
		root = tree[root][bit];
		ans=ans*2+bit;
	}
	return ans;
}

int main(){
#ifdef ONLINE_JUDGE
#else
	freopen("in.txt","r",stdin);
#endif
	bitv[0]=1;
	for(int i=1;i<33;i++){
		bitv[i]=bitv[i-1]*2;
		tree[i][0] = tree[i][1] = -1;
	}

	int tc;cin>>tc;
	for(int t=1;t<=tc;t++){
		cin>>n>>m;
		int tmp;
		for(int i=0;i<n;i++){
			cin>>tmp;
			build(tmp);
		}

		cout<<"Case "<<t<<":";
		for(int j=0;j<m;j++){
			cin>>tmp;
			tmp=tmp^(bitv[32]-1);
			cout<<query(tmp)<<endl;
		}
	}
	return 0;
}
