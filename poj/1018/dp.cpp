#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

const int inf = 0x3f3f3f3f;
int dp[120][1200];

int main(){
#ifdef ONLINE_JUDGE
#else
	freopen("in.txt","r",stdin);
#endif
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        for(int i=1; i<=n; i++)  //初始化
            for(int j=0; j<1100; j++)
                dp[i][j]=inf;

        for(int i=1; i<=n; i++){   //dp
            int num; cin>>num;
            for(int j=1; j<=num; j++){
                int b,p;
				cin>>b>>p;
                if(i==1){
                    dp[1][b]=min(dp[1][b],p);
                }
                else{
                    for(int k=0; k<1100; k++){
                        if(dp[i-1][k]!=inf){
                            if(k<=b)
                                dp[i][k]=min(dp[i][k],dp[i-1][k]+p);
                            else
                                dp[i][b]=min(dp[i][b],dp[i-1][k]+p);
                        }
                    }
                }
            }
        }
        double ans=0;
        for(int i=0; i<1100; i++){
            if(dp[n][i]!=inf){
                double k=(double)i/dp[n][i];
                if(k>ans)
                    ans=k;
            }
        }
		cout<<fixed<<setprecision(3)<<ans<<endl;
    }
    return 0;
}
