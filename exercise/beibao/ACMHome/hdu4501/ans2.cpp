#include<iostream>
#include<string>
#include<algorithm>
const int MAX=101;
const int K=6;
int DP[MAX][MAX][K];//三重背包
using namespace std;

struct thing{
    int price;
    int score;
    int value;
};
thing s[MAX];

int main(){
	freopen("in.txt","r",stdin);
    int n,v1,v2,k,i,j,q,p;
    while(cin>>n>>v1>>v2>>k){
        for(i=1;i<=n;i++)
            cin>>s[i].price>>s[i].score>>s[i].value;
        memset(DP,0,sizeof(DP));

        for(i=1;i<=n;i++){
            for(j=v1;j>=0;j--){
                for(q=v2;q>=0;q--){
					for(p=k;p>=0;p--){
                        int temp=0;
                        if(j-s[i].price>=0)
                        	temp=max(temp,DP[j-s[i].price][q][p]+s[i].value);
                        if(q-s[i].score>=0)
                        	temp=max(temp,DP[j][q-s[i].score][p]+s[i].value);
                        if(p-1>=0)
                        	temp=max(temp,DP[j][q][p-1]+s[i].value);
                        DP[j][q][p]=max(DP[j][q][p],temp);
                    }
                }
            }
        }
        cout<<DP[v1][v2][k]<<endl;
    }
    return 0;
}
