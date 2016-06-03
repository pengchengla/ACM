#include <iostream>
#include <string>
using namespace std;

class Solution 
{
public:
    string convertToTitle(int n) 
    {
        string ans="";
        if(n<=0) return ans;
        while(n)
        {
            if(n<=26)
            {
                char ch = 'A' + n-1;
                ans+=ch;
                break;
            }
            else
            {

            }
        }
        return ans;
    }
};

int main()
{
    Solution * solution = new Solution();
    cout<<solution->convertToTitle(1)<<endl;
    return 0;
}
