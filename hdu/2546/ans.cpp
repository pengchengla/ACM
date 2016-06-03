#include<iostream>
#include<cstring>
#include<algorithm>
const int N=1100;
using namespace std;

int price[N];
int dp[N];

int main(){
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif
    int n,m;
    while(scanf("%d",&n)!=EOF&&n){
        for(int i=0;i<n;i++){
            scanf("%d",&price[i]);
        }
        sort(price,price+n);
        scanf("%d",&m);
        if(m<5){
            printf("%d\n",m);
            continue;
        }
        m-=5;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n-1;i++){
            for(int j=m;j>=price[i];j--){
                dp[j]=(dp[j-price[i]]+price[i])>dp[j]?(dp[j-price[i]]+price[i]):dp[j];
            }
        }
        printf("%d\n",m+5-price[n-1]-dp[m]);
    }
    return 0;
}
