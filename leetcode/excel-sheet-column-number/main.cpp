#include <iostream>
using namespace std;

class Solution 
{
public:
    int titleToNumber(string s) 
    {
        int re = 0;
        int base = 1;
        for(int i=len.size()-1;i>=0;i--)
        {
            re += (s[i]-'A'+1)*base;
            base*=26;
        }
        return re;
    }
};

int main()
{
    char ch = 'A';
    char ch1 = 'C';
    int st = 1;
    cout<<ch1-ch+st<<endl;
    return 0;
}
