/*===============================================================
*   Copyright (C) 2014 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2014-11-30
*   描    述：
================================================================*/
#include<iostream>
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
    Solution()
    {
        ans=INT_MIN;
    }
    int maxPathSum(TreeNode *root) 
    {
        if(root==NULL) return 0;
        int left = maxPathSum(root->left);
        int right = maxPathSum(root->right);
        int cur=root->val;
        if(left>0)  cur+=left;
        if(right>0) cur+=right;
        if(cur>ans) ans=cur;
        return ans;
    }
private:
    int ans;
};

int main()
{
    TreeNode * root = new TreeNode(-1);
    TreeNode * left = new TreeNode(1);
    TreeNode * right = new TreeNode(3);
    TreeNode * left_left = new TreeNode(1);
    root->left = left;
    root->right = right;
    root->left->left = left_left;
    Solution * solution = new Solution();
    cout<<solution->maxPathSum(root)<<endl;
    return 0;
}
