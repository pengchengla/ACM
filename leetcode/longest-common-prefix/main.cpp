#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) 
    {
        int s = strs.size();
        if(s==0)  return "";
        sort(strs.begin(),strs.end());
        int ans=0;
        for(int i=0;i<strs[0].size()&&i<strs[s-1].size();i++)
        {
            if(strs[0][i]==strs[s-1][i]) ans++;
            else break;
        }
        return strs[0].substr(0,ans);
    }
};

int main()
{
    return 0;
}
