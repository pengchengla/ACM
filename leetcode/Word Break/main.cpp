/*===============================================================
*   Copyright (C) 2014 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2014-11-30
*   描    述：
================================================================*/

#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

class Solution 
{
public:
    bool wordBreak(string s, unordered_set<string> &dict) 
    {
        int len = s.length();
        int * dp = new int[len];
        memset(dp,0,sizeof(int)*len);
        for(int i=0;i<len;++i)
        {
            string temp = s.substr(0,i+1);
            unordered_set<string>::const_iterator iter = dict.find(temp);
            if(iter!=dict.end())    dp[i]=1;
            else
            {
                for(int j=0;j<i;++j)
                {
                    if(dp[j]==1)
                    {
                        string temp = s.substr(j+1,i-j);
                        unordered_set<string>::const_iterator iter = dict.find(temp);
                        if(iter!=dict.end())
                        {
                            dp[i]=1;
                            break;
                        }
                    }
                }
            }
        }
        if(dp[len-1]!=0) return true;
        return false;
    }
};

int main()
{
    /**string str = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    string all[] = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};*/
    string str="leetcode";
    string all[] = {"l","t","lee","code"};

    unordered_set<string> dict;
    for(int i=0;i<3;++i)
    {   
        dict.insert(all[i]);
    }   
    Solution * solution = new Solution();
    cout<<solution->wordBreak(str,dict)<<endl;
    return 0;
}
