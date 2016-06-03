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
    vector<vector<int> > pathSum(TreeNode *root,int sum)
    {
        vector<int> vec;
        getPath(root,sum,vec);
        return ans;
    }
private:
    void getPath(TreeNode *root,int sum,vector<int> &vec) 
    {
        if(root==NULL)  return;
        if(!root->left && !root->right && sum==root->val)
        {
            vec.push_back(root->val);
            this->ans.push_back(vec);
            vec.pop_back();
        }
        else
        {
            sum-=root->val;
            vec.push_back(root->val);
            getPath(root->left,sum,vec);
            getPath(root->right,sum,vec);
            vec.pop_back();
            sum+=root->val;
        }
    }
private:
    vector<vector<int> > ans;
};

int main()
{
    return 0;
}
