/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-31
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(ans,root);
        return ans;
    }
private:
    void inorder(vector<int> & ans, TreeNode * root){
        if(root==NULL) return ;
        ans.push_back(root);
        inorder(ans,root->left);
        inorder(ans,root->right);
    }
};

int main(){
    return 0;
}
