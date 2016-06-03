#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) 
    {
        vector<vector<int> > ans;
        getSum(candidates,target,0);
        return ans;
    }
private:
    void getSum(vector<int> &candidates,int target,int level)
    {
        for(int i=0;i<candidates.size();i++)
        {
            if(level<3)
            {
                cout<<"level="<<level<<"    scan="<<candidates[i]<<endl;
                getSum(candidates,target,level+1);
            }
            else
            {
                break;
            }
        }
    }
};

int main()
{
    vector<int> candidates;
    candidates.push_back(2);
    candidates.push_back(3);
    candidates.push_back(6);
    candidates.push_back(7);
    Solution * solution = new Solution();
    vector<vector<int> > temp = solution->combinationSum(candidates,7);
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
