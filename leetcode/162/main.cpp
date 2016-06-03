#include <iostream>
using namespace std;

class Solution 
{
public:
    int findPeakElement(const vector<int> &num) 
    {
        int ans = -1;
        int i = 0;
        for(i=0;i<num.size()-1;i++)
        {
            if(num[i]>num[i+1])
            {
                ans = i;
                break;
            }
        }
        if(i==num.size()-1) ans= num.size()-1;
        return ans;
    }
};

int main()
{
    return 0;
}
