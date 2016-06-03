#include <iostream>
using namespace std;

int exchange(int m,int n)
{
    m--;
    int ans = ((1+m)*m)/2 + n;
    return ans;
}
void print(int * matrix,int rows)
{
        for(int i=1;i<rows;++i) cout<<matrix[i]<<" ";
            cout<<endl;
}

int getans(int * matrix, int * ans, int rows, int m, int n)
{
    int pos=exchange(m,n);
    if(m>0&&m<=rows&&n>0&&n<=rows&&ans[pos]!=0)  return ans[pos];
    int t1 = getans(matrix,ans,rows,m+1,n);
    int t2 = getans(matrix,ans,rows,m+1,n+1);
    ans[pos]= t1>t2?(t1+matrix[pos]):(t2+matrix[pos]);
    return ans[pos];
}

int main()
{
    //freopen("file","r",stdin);
    int rows;
    cin>>rows;
    //malloc
    int size = exchange(rows,rows)+1;
    int * matrix = new int[size];
    int * ans = new int[size];
    memset(matrix,0,sizeof(int)*size);
    memset(ans,0,sizeof(int)*size);
    for(int i=1;i<=size;++i)
        cin>>matrix[i];
    int start = exchange(rows,1);
    for(int i=start;i<=size;++i)
        ans[i]=matrix[i];
    int re = getans(matrix,ans,rows,1,1);
    cout<<re<<endl;
    return 0;
}
