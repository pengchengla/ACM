#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
private:
    vector<vector<int> > ans;
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) 
    {
        vector<int> path;   path.clear();
        int sum = 0;
        sort(candidates.begin(),candidates.end());
        dfs(candidates,target,sum,path);
        return ans;
    }
private:
    void dfs(vector<int> &candidates,int target,int &sum,vector<int> &path)
    {
        if(target==sum)
        {
            vector<int> tmp = path;
            sort(tmp.begin(),tmp.end());
            bool is_push = true;
            for(vector<vector<int> >::iterator iter=ans.begin();iter!=ans.end();iter++)
            {
                if(*iter==tmp)
                {
                    is_push = false;
                    break;
                }
            }
            if(is_push) ans.push_back(tmp);
        }
        for(int i=0;i<candidates.size();i++)
        {
            if((target-sum)>=candidates[i])
            {
                sum+=candidates[i];
                path.push_back(candidates[i]);
                dfs(candidates,target,sum,path);
            }
            else
            {
                break;
            }
        }
        if(path.size()!=0)
        {
            int can = path[path.size()-1];
            path.pop_back();
            sum-=can;
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
