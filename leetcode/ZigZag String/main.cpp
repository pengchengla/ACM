#include <iostream>
using namespace std;

class Solution 
{
public:
    string convert(string s, int nRows)
    {
        if(nRows==1) return s;
        string ans="";
        string *strs=new string[nRows];
        int len=s.length();
        bool flag=true;
        int k=-1;
        for(int i=0;i<len;++i)
        {
            if(flag)
            {
                strs[++k]+=s[i];
                if(k==nRows-1) flag=false;
            }
            else
            {
                strs[--k]+=s[i];
                if(k==0) flag=true;
            }
        }
        for(int i=0;i<nRows;++i)
            ans+=strs[i];
        return ans;
    }
};

int main()
{
    Solution * solution = new Solution();
    cout<<solution->convert("AB",1)<<endl;
    //PAHNAPLSIIGYIR
    return 0;
}
