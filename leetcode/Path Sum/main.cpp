/*===============================================================
*   Copyright (C) 2014 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2014-11-30
*   描    述：
================================================================*/
#include <iostream>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution 
{
public:
    bool hasPathSum(TreeNode *root,int sum) 
    {
        if(root==NULL)  return false;
        if(!root->left && !root->right && sum==root->val)
        {
            return true;
        }
        sum-=root->val;
        bool flag=false;
        flag = hasPathSum(root->left,sum);
        if(!flag)   flag = hasPathSum(root->right,sum);
        sum+=root->val;
        return flag;
    }
};

int main()
{
    return 0;
}
