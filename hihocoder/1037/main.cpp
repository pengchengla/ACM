#include <iostream>
using namespace std;

int getmax(int t1,int t2)
{
    int ans = t2;
    if(t1>t2) ans = t1;
    return ans;
}

int main()
{
    freopen("in.txt","r",stdin);
    int lines = 0;
    cin>>lines;
    int ** total = new int*[lines];
    for(int i=0;i<lines;i++) total[i] = new int[lines];
    for(int i=0;i<lines;i++)
        for(int j=0;j<=i;j++)
            cin>>total[i][j];
    for(int i=lines-2;i>=0;i--)
    {
        for(int j=0;j<=i;j++)
        {
            total[i][j] = getmax(total[i][j]+total[i+1][j],total[i][j]+total[i+1][j+1]);
        }
    }
    cout<<total[0][0];
    return 0;
}
