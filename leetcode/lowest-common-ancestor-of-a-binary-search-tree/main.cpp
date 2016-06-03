/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-26
*   描    述：
================================================================*/
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return root;
        int big = max(p->val,q->val);
        int small = min(p->val,q->val);
        if(root->val > big){
            return lowestCommonAncestor(root->left,p,q);
        }else if(root->val < small){
            return lowestCommonAncestor(root->right,p,q);
        }else{
            return root;
        }
    }   
};


int main(){
    return 0;
}
