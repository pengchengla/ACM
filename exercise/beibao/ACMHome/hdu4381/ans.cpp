#include <algorithm>
#include <iostream>
using namespace std;

const int maxn = 2005;
struct node{
    int aa,xx;
    node(){}
    node(int _aa,int _xx){
       aa = _aa;   xx = _xx;
    }
}x1[maxn],x2[maxn];

int n,m;
int dp1[maxn],dp2[maxn];
int sumx1,sumx2;

bool cmp(const node &p,const node &q){
    return p.aa < q.aa;
}

int main(){
	freopen("in.txt","r",stdin);
    int cas,ta=1;  cin>>cas;
    while(cas--){
         int i,j;
		 cin>>n>>m;

         sumx1 = sumx2 = 1;
         for(i=0; i<m; i++){
             int op,aa,xx;
			 cin>>op>>aa>>xx;
             if(op == 1){
                x1[sumx1++] = node(aa,xx);
             }else{
                x2[sumx2++] = node(n-aa+1,xx);
             }
         }
         sort(x1+1,x1+sumx1,cmp);
         sort(x2+1,x2+sumx2,cmp);
         memset(dp1,0x3f,sizeof(dp1));
         memset(dp2,0x3f,sizeof(dp2));
         dp1[0] = dp2[0] = 0;

         for(i=1; i<sumx1; i++){
             for(j=x1[i].aa; j>=x1[i].xx; j--){
                dp1[j] = min(dp1[j],dp1[j-x1[i].xx]+1);
             }
         }// for

         for(i=1; i<sumx2; i++){
             for(j=x2[i].aa; j>=x2[i].xx; j--){
                dp2[j] = min(dp2[j],dp2[j-x2[i].xx]+1);
             }
         }// for

         int ans = 0,anssum = 0,tmp;
         for(i=1; i<=n; i++){
			 if(i == 3){
				 tmp = 1;
			 }
             for(j=0; j<=i; j++){
				tmp = dp1[j] + dp2[i-j];
				if(tmp <= m){
					if(ans != i){
						ans = i;
						anssum = tmp;
					}
					else if(tmp < anssum){
						anssum = tmp;
					}
				}
			}
		}
		cout<<"Case "<<ta++<<": "<<ans<<" "<<anssum<<endl;
    }
    return 0;
}
