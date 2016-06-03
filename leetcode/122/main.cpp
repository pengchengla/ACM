#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution 
{
public:
    int maxProfit(vector<int> &prices) 
    {
        priority_queue<int> qu;
        int size=prices.size();
        if(size==0||size==1) return 0;
        int temp = 0;
        for(int i=1;i<size;i++)
        {
            int tmp = prices[i]-prices[i-1];
            if(tmp>=0) temp+=tmp;
            else
            {
                if(temp!=0)
                {
                    qu.push(temp);
                    temp=0;
                }
            }
        }
        if(temp!=0) qu.push(temp);
        int ans=0;
        int count = 2;
        while(!qu.empty())
        {
            if(count!=0)
            {
                ans+=qu.top();
                qu.pop();
                count--;
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> prices;
    prices.push_back(1);
    prices.push_back(2);
    Solution * solution = new Solution();
    cout<<solution->maxProfit(prices)<<endl;
    return 0;
}
