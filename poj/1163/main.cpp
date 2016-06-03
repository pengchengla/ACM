#include <iostream>
using namespace std;

int getans(int ** matrix, int ** ans, int rows, int m, int n)
{
    cout<<"m="<<m<<"    n="<<n<<endl;
    if(m>-1&&m<rows&&n>-1&&n<rows&&ans[m][n]!=0)  return ans[m][n];
    int t1 = getans(matrix,ans,rows,m+1,n);
    int t2 = getans(matrix,ans,rows,m+1,n+1);
    ans[m][n]= t1>t2?(t1+matrix[m][n]):(t2+matrix[m][n]);
    return ans[m][n];
}

int main()
{
    freopen("file","r",stdin);
    int rows;
    cin>>rows;
    //malloc
    int **matrix = new int*[rows];
    int **ans = new int*[rows];
    for(int i=0;i<rows;++i) 
    {
        matrix[i]=new int[rows];
        ans[i]=new int[rows];
    }
    for(int i=0;i<rows;i++)
        for(int j=0;j<rows;j++)
        {
            ans[i][j]=0;
            matrix[i][j]=0;
        }
    for(int i=0;i<rows;++i)
    {
        for(int j=0;j<=i;++j)
        {
            cin>>matrix[i][j];
            if(i==rows-1)
                ans[i][j]=matrix[i][j];
        }
    }
    int re = getans(matrix,ans,rows,0,0);
    cout<<re<<endl;
    return 0;
}
