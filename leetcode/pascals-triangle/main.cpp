#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) 
    {
        vector<vector<int> > ans;
        if(numRows<=0) return ans;
        for(int i=0;i<numRows;i++)
        {
            int as = ans.size();
            vector<int> tmp;
            tmp.resize(i+1);
            tmp[0] = 1;
            for(int j=1;j<i;j++)
            {
                tmp[j] = ans[as-1][j]+ans[as-1][j-1];
            }
            tmp[i] = 1;
            ans.push_back(tmp);
        }
        return ans;
    }
};

int main()
{
    return 0;
}
