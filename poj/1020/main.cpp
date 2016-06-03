#include <iostream>
using namespace std;

int cmp(const void * a,const void * b)
{
    return *(int*)b - *(int*)a;
}

int main()
{
    freopen("in.txt","r",stdin);
    int tc = 0;
    cin>>tc;
    while(tc--)
    {
        int sq = 0;
        cin>>sq;
        int ** square = new int*[sq];
        for(int i=0;i<sq;i++) square[i] = new int[sq];

        int per = 0;
        cin>>per;
        int * total = new int[per];
        memset(total,0,sizeof(int)*per);
        for(int i=0;i<per;i++)  cin>>total[i];

        qsort(total,per,sizeof(int),cmp);
        for(int i=0;i<per;i++) cout<<total[i]<<" ";
        cout<<endl;
    }
    return 0;
}
