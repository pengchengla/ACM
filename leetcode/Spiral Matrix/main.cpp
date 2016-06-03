/*===============================================================
*   Copyright (C) 2014 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2014-11-27
*   描    述：
================================================================*/

#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) 
    {
        vector<int> ans;
        int m0 = 0;
        int m1 = matrix.size()-1;
        if(m1==-1)   return ans;
        int n0 = 0;
        int n1 = matrix[0].size()-1;

        int i=0; int j=0;
        int count = 0;
        int total = (m1+1)*(n1+1);
        while(count<total)
        {
            while(j<=n1)
            {
                ans.push_back(matrix[i][j]);
                j++;
                count++;
            }
            if(count==total)    return ans;
            m0++;
            i++;
            j--;
            while(i<=m1)
            {
                ans.push_back(matrix[i][j]);
                i++;
                count++;
            }
            if(count==total)    return ans;
            i--;
            j--;
            n1--;
            while(j>=n0)
            {
                ans.push_back(matrix[i][j]);
                j--;
                count++;
            }
            if(count==total)    return ans;
            m1--;
            i--;
            j++;
            while(i>=m0)
            {
                ans.push_back(matrix[i][j]);
                i--;
                count++;
            }
            if(count==total)    return ans;
            i++;
            j++;
            n0++;
        }
        return ans;
    }
};

int main()
{
    return 0;
}
