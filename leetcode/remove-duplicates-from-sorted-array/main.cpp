#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) 
    {
        if(A==NULL||n==0) return n;
        int newp = 0;
        for(int scanp=0;scanp<n;scanp++)
        {
            if(A[scanp]!=A[newp])
            {
                newp++;
                A[newp] = A[scanp];
            }
        }
        return newp+1;
    }
};


int main()
{
    return 0;
}
