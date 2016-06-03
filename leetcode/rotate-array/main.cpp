#include <iostream>
using namespace std;

class Solution {
public:
    void rotate(int nums[], int n, int k) 
    {
        k = k%n;
        if(n==1||k==0) return;
        for(int i=0;i<=(n-k-1)/2;i++)
        {
            int temp = nums[i];
            nums[i] = nums[n-k-1-i];
            nums[n-k-1-i] = temp;
        }
        for(int i=n-k;i<=n-k+(k-1)/2;i++)
        {
            int temp = nums[i];
            nums[i] = nums[n-k+n-1-i];
            nums[n-k+n-1-i] = temp;
        }
        for(int i=0;i<=(n-1)/2;i++)
        {
            int temp = nums[i];
            nums[i] = nums[n-i-1];
            nums[n-i-1] = temp;
        }
    }
};

int main()
{
    int total = 1;
    int * nums = new int[total];
    for(int i=0;i<total;i++) nums[i] = i+1;
    Solution * solution = new Solution();
    solution->rotate(nums,total,3);
    for(int i=0;i<total;i++) cout<<nums[i]<<" ";
    cout<<endl;
    return 0;
}
