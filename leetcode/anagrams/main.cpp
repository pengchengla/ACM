#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

class Solution 
{
private:
    vector<string> ans;
    unordered_map<string,vector<string> > mmap;
public:
    vector<string> anagrams(vector<string> &strs) 
    {
        ans.clear();
        for(int i=0;i<strs.size();i++)
        {
            string tmp = strs[i];
            sort(tmp.begin(),tmp.end());
            mmap[tmp].push_back(strs[i]);
        }
        for(unordered_map<string,vector<string> >::iterator iter=mmap.begin();iter!=mmap.end();iter++)
        {
            if((iter->second).size() > 1)
            {
                for(int k=0;k<(iter->second).size();k++)
                    ans.push_back((iter->second)[k]);
            }
        }
        return ans;
    }
};

int main()
{
    Solution * solution = new Solution();
    solution->anagrams(strs);
    string str="asdfghjkl";
    cout<<str<<endl;
    sort(str.begin(),str.end());
    cout<<str<<endl;
    return 0;
}
