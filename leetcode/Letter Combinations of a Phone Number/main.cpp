/*===============================================================
*   Copyright (C) 2014 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2014-11-30
*   描    述：
================================================================*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution 
{
public:
    vector<string> letterCombinations(string digits) 
    {
        vector<string> ans;
        int len = digits.length();
        int *pos = new int[len];
        memset(pos,sizeof(int)*len,0);
        for(int i=0;i<len;i++)
        {
            
        }
        return ans;
    }
private:
    string mem[8] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
};

int main()
{
    Solution * solution = new Solution();
    solution->letterCombinations("aa");
    return 0;
}
