/*===============================================================
*   Copyright (C) 2014 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2014-11-29
*   描    述：
================================================================*/

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) 
    {
        vector<vector<int> > ans;
        if(root==NULL)  return ans;
        vector<int> vec;
        queue<TreeNode*> qu;

        qu.push(root);
        vec.push_back(root->val);
        qu.push(NULL);

        ans.push_back(vec);
        vec.clear();
        int is_reverse=0;
        while(!qu.empty())
        {
            TreeNode * treeNode = qu.front();
            qu.pop();
            if(treeNode!=NULL)
            {
                if(treeNode->left)
                {
                    qu.push(treeNode->left);
                    if(is_reverse%2==0)
                        vec.insert(vec.begin(),treeNode->left->val);
                    else
                        vec.push_back(treeNode->left->val);
                }
                if(treeNode->right)
                {
                    qu.push(treeNode->right);
                    if(is_reverse%2==0)
                        vec.insert(vec.begin(),treeNode->right->val);
                    else
                        vec.push_back(treeNode->right->val);
                }
            }
            else
            {
                is_reverse++;
                if(vec.size()!=0)
                {
                    ans.push_back(vec);
                    vec.clear();
                }
                if(!qu.empty()) qu.push(NULL);
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}
