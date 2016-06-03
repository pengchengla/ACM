#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

class Solution 
{
public:
    int threeSumClosest(vector<int> &num, int target) 
    {
        int size = num.size();
        int ans = num[0]+num[1]+num[2];
        if(size==3) return ans;
        sort(num.begin(),num.end());
        for(int i=0;i<size-2;i++)
        {
            int left = i+1;
            int right = size-1;
            while(left<right)
            {
                int temp = num[i]+num[left]+num[right];
                if((temp-target)==0)
                {
                    return target;
                }
                if(abs(ans-target)>abs(temp-target)>0)
                {
                    ans = temp;
                }
                (temp>target)?right--:left++;
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}
