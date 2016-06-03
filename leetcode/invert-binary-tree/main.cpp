/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-06-29
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
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return root;
        TreeNode * tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        if(root->left) invertTree(root->left);
        if(root->right) invertTree(root->right);
        return root;
    }
};

int main(){
    return 0;
}
