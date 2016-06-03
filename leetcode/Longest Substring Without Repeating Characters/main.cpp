#include <iostream>
using namespace std;

class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        const int asclen=128;
        int sts[asclen];
        memset(sts,0,sizeof(int)*asclen);
        int ans=0;
        for(int i=0;i<s.length();++i)
        {
            int len=0;
            for(int j=i;j<s.length();++j)
            {
                int &flag = sts[s[j]];
                if(flag==0) {flag++;len++;}
                else break;
            }
            if(len>ans) ans=len;
            memset(sts,0,sizeof(int)*asclen);
        }
        return ans;
    }
};

int main()
{
    string input="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!";
    Solution * solution = new Solution();
    cout<<solution->lengthOfLongestSubstring(input)<<endl;
    return 0;
}
