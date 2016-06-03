#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
            vector<vector<int> > ret;
            vector<int> path;
            sort( candidates.begin(), candidates.end() );  // ensure non-descending
            dfs( candidates, target, 0, path, ret );
            return ret;
        }
        // depth-first 
        void dfs(vector<int> &candidates, int target, int idx,
        vector<int> path, vector<vector<int> > &ret)
        {
            for( int i = idx; i < candidates.size(); i++ )    // begin with idx, avoid duplicated
            {
                if( target == candidates[i] )
                {
                    vector<int> tmp = path;
                    tmp.push_back( candidates[i] );
                    ret.push_back(tmp);
                }
                if( target - candidates[i] >= candidates[0] )
                {
                    vector<int> tmp = path;
                    tmp.push_back( candidates[i] );
                    dfs( candidates, target-candidates[i], i, tmp, ret );
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
