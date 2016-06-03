#include <iostream>
#include <string>
using namespace std;

int getans(string str)
{
    int ans = 1;
    int l = 0;
    int r = 0;
    int len = str.length();
    for(int i=0;i<len;i++)
    {
        //ji
        l = i-1;
        r = i+1;
        while(l>=0&&r<str.size()&&str[l]==str[r])
        {
            l--;
            r++;
        }
        int tmp = r-l-1;
        if(tmp>ans) ans = tmp;
        //ou
        l = i;
        r = i+1;
        while(l>=0&&r<str.size()&&str[l]==str[r])
        {
            l--;
            r++;
        }
        tmp = r-l-1;
        if(tmp>ans) ans = tmp;
    }
    return ans;
}

int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif
    int tc = 0;
    cin>>tc;
    while(tc--)
    {
        string str;
        cin>>str;
        cout<<getans(str)<<endl;
    }
    return 0;
}
