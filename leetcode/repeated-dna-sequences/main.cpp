#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

class Solution 
{
private:
    vector<string> ans;
    map<string,int> mmap;
public:
    vector<string> findRepeatedDnaSequences(string s) 
    {
        if(s.size()<=10) return ans;
        for(int i=0;i<=s.size()-10;i++)
        {
            string sub = s.substr(i,10);
            mmap[sub]+=1;
            if(mmap[sub]>1) ans.push_back(sub);
        }
        return ans;
    }
};

int main()
{
    Solution * solution = new Solution();
    solution->findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    //vector<string> ans = solution->findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    //for(int i=0;i<ans.size();i++)
    //    cout<<ans[i]<<endl;
    return 0;
}
