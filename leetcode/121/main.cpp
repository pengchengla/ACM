#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    int maxProfit(vector<int> &prices) 
    {
        int size = prices.size();
        if(size==0) return 0;
        int * total = new int[size-1];
        memset(total,0,sizeof(int)*(size-1));
        for(int i=0;i<size-1;i++)
            total[i] = prices[i+1]-prices[i];
        int ans = 0;
        int max_v = 0;
        for(int i=1;i<size;i++)
        {
            if(ans>0)
            {
                ans+=(ans+total[i]);
            }
            else
            {
                ans=total[i];
            }
            if(ans>max_v) max_v=ans;
        }
        return max_v;
    }
};

int main()
{
    return 0;
}
