/*===============================================================
*   Copyright (C) 2014 All rights reserved.
*   文件名称：ans.cpp
*   创 建 者：pengcheng
*   创建日期：2014-12-01
*   描    述：
================================================================*/
#include <iostream>
using namespace std;

class Solution 
{
public:
    bool wordBreak(string s, unordered_set<string> &dict)
    {
        int len = s.length();
        bool * dp = new bool[len];
        memset(dp,false,sizeof(bool)*len);
        for(int i=0;i<len;++i)
        {
            dp[i] = ((dict.find(s.substr(0,i+1))!=dict.end())?true:false);
            if(dp[i])   continue;
            else
            {
                for(int j=0;j<i;++j)
                {
                    if(dp[j])
                    {
                        dp[i] = ((dict.find(s.substr(j+1,i-j))!=dict.end())?true:false);
                        if(dp[i])    break;
                    }
                }
            }
        }
        bool ans = dp[len-1];
        delete []dp;
        return ans;
    }
};

int main()
{
    return 0;
}
