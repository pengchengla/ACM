#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
private:
    vector<vector<int> > ans;
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) 
    {
        int sum = 0;
        int idx = 0;
        vector<int> path;
        path.clear();
        sort(num.begin(),num.end());
        for(int i=0;i<num.size();i++)   cout<<num[i]<<" ";
        cout<<endl;
        dfs(num,target,sum,idx,path);
        return ans;
    }
private:
    void dfs(vector<int> &num,int target,int &sum,int idx,vector<int>&path)
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
                    is_push=false;
                    break;
                }
            }
            if(is_push) 
            {
                ans.push_back(tmp);
            }
        }
        for(int i=idx;i<num.size();i++)
        {
            if((target-sum)>num[i])
            {
                sum+=num[i];
                path.push_back(num[i]);
                dfs(num,target,sum,i+1,path);
            }
            else
            {
                break;
            }
        }
        if(!path.empty())
        {
            int can = path[path.size()-1];
            path.pop_back();
            sum-=can;
        }
    }
};

int main()
{
    vector<int> num;
    int total[]={10,1,2,7,6,1,5};
    for(int i=0;i<sizeof(total)/sizeof(int);i++)
    {
        num.push_back(total[i]);
    }
    Solution * solution = new Solution();
    vector<vector<int> > tmp = solution->combinationSum2(num,8);
    for(int i=0;i<tmp.size();i++)
    {
        for(int j=0;j<tmp[i].size();j++)
        {
            cout<<tmp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
