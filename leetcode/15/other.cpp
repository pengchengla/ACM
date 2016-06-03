#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    vector<vector<int> > threeSum(vector<int> &num) 
    {
        vector<vector<int> > ans;
        ans.clear();
        int size = num.size();
        if(size<3) return ans;
        sort(num.begin(),num.end());
        for(int i=0;i<size-2;i++)
        {
            if(i && num[i]==num[i-1])   continue;
            int left = i+1;
            int right = size-1;
            while(left<right)
            {
                if(left!=i+1 && num[left]==num[left-1]) 
                {   
                    left++;
                    continue;
                }
                if(right!=size-1 && num[right]==num[right+1]) 
                {
                    right--;
                    continue;
                }
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
            }
        }
        return ans;
    }
};

int main()
{
    Solution * solution = new Solution();
    int total[]={-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    int s=sizeof(total)/sizeof(int);
    cout<<"s="<<s<<endl;
    vector<int> in(total,total+s);
    for(int i=0;i<in.size();i++)
    {
        cout<<in[i]<<" ";
    }
    cout<<endl;
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
