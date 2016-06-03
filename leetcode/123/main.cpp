#include <iostream>
using namespace std;

class Solution 
{
public:
    int maxProfit(vector<int> &prices) 
    {
        int size = prices.size();
        if(size==0||size==1) return 0;
        int ans=0;
        for(int i=1;i<size;i++)
        {
            int tmp = prices[i]-prices[i-1];
            if(tmp>0) ans+=tmp;
        }
        return ans;
    }
};


int main()
{
    return 0;
}
