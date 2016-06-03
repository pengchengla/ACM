#include <iostream>
using namespace std;

class Solution 
{
public:
    void merge(int A[], int m, int B[], int n) 
    {
        int size = m+n;
        int * ans = new int[size];
        int i=0;int j=0;
        int k=0;
        while(i<m && j<n)
        {
            if(A[i]>B[j])   ans[k++] = B[j++];
            else ans[k++] = A[i++];
        }
        while(i<m)  ans[k++] = A[i++];
        while(j<n)  ans[k++] = B[j++];
        for(int l=0;l<size;l++) A[l] = ans[l];
        delete []ans;
    }
};

int main()
{
    return 0;
}
