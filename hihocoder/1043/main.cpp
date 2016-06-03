#include <iostream>
using namespace std;

int main(){
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif
    int N,M;
    cin>>N>>M;
    int need[503]={0};
    int value[503]={0};
    for(int i=0;i<N;i++){
        cin>>need[i]>>value[i];
    }

    int f[100003]={0};
    for(int i=0;i<N;i++){
        for(int v=need[i];v<=M;v++){
            int tmp = f[v-need[i]] + value[i];
            f[v] = tmp>f[v] ? tmp : f[v];
        }
    }
    cout<<f[M]<<endl;
    return 0;
}
