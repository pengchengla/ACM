#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    vector<vector<int> > threeSum(vector<int> &num) 
    {
        vector<vector<int> > ans;
        int size = num.size();
        if(size<3) return ans;
        sort(num.begin(),num.end());
        for(int i=0;i<size-2;)
        {
            int left = i+1;
            int right = size-1;
            while(left<right)
            {
                int temp = num[i]+num[left]+num[right];
                if(temp==0)
                {
                    vector<int> v; 
                    v.push_back(num[i]);v.push_back(num[left]);v.push_back(num[right]);
                    ans.push_back(v);
                    left++;
                    right--;
                }
                else if(temp>0) right--;
                else left++;
                while(left<right && num[right]==num[right+1])    right--;
                while(left<right && num[left]==num[left-1])    left++;
            }
            i++;
            while(i<size-2 && num[i]==num[i-1]) i++;
        }
        return ans;
    }
};

int main()
{
    Solution * solution = new Solution();
    int total[]={-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    vector<int> in(total,total+sizeof(total));
    vector<vector<int> > temp = solution->threeSum(in);
    cout<<"ans="<<endl;
    for(int i=0;i<temp.size();i++)
    {
        for(int j=0;j<temp[i].size();j++)
        {
            cout<<temp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
