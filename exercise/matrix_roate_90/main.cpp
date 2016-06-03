#include <iostream>
using namespace std;

int main()
{
    freopen("file","r",stdin);
    int n=0;
    cin>>n;
    int ** matrix = new int*[n];
    for(int i=0;i<n;i++) matrix[i] = new int[n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>matrix[i][j];
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<n/2;i++)
    {
        for(int j=i;j<n-i-1;j++)
        {
            int temp = matrix[n-j-1][i];
            matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
            matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
            matrix[j][n-i-1] = matrix[i][j];
            matrix[i][j] = temp;
        }
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
