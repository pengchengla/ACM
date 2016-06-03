#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    freopen("file","r",stdin);
    int tc;
    cin>>tc;
    stack<int> s_count;
    stack<char> s_op;
    stack<string> s_tmp;
    while(tc--)
    {
        string ans="";
        string tmp="";
        string src;
        cin>>src;
        for(int i=0;i<src.length();i++)
        {
            if(src[i]=='(')
            {
                if(s_op.size()!=0) 
                {
                    s_tmp.push(tmp);
                    tmp="";
                }
                s_op.push(src[i]);
            }
            else if(src[i]==')')
            {
            }
            else if(src[i]>='a' && src[i]<='z')
            {
                tmp+=src[i];
            }
            else//num
            {
                s_count.push(src[i]-'0');
            }
        }
    }
    return 0;
}
