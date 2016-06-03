/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-13
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
    void recoverTree(TreeNode* root) {
        TreeNode * small=NULL, * large=NULL;
        scan(root,small,large);
        if(!small || !large) return;
        int val = small->val;
        small->val = large->val;
        large->val = val;
    }
private:
    void scan(TreeNode * root,TreeNode * & small, TreeNode * & large){
        if(!root) return;
        if(root->left && root->left->val > root->val){
            large = root->left;
        }
        if(root->right && root->right->val < root->val){
            small = root->right;
        }
        scan(root->left,small,large);
        scan(root->right,small,large);
    }
};

int main(){
    return 0;
}
