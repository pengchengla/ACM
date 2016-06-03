/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-08-05
*   描    述：
================================================================*/
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> trees(1, nullptr);
        for (int i = 1; i <= n; i++) {
            int len = trees.size();
            for (int j = 0; j < len; j++) {
                TreeNode *root = trees[j];
                TreeNode *it = root;
                while (it != nullptr) {
                    TreeNode node(i);
                    node.left = it->right;
                    it->right = &node;
                    TreeNode *root_copy = cloneTree(root);
                    trees.push_back(root_copy);
                    it->right = it->right->left;
                    it = it->right;
                }
                TreeNode *node = new TreeNode(i);
                node->left = root;
                trees[j] = node;
            }
        }
        return trees;
    }
private:
    TreeNode* cloneTree(TreeNode *root) {
        if (root == nullptr) {
            return nullptr;
        }
        TreeNode *root_copy = new TreeNode(root->val);
        root_copy->left = cloneTree(root->left);
        root_copy->right = cloneTree(root->right);
        return root_copy;
    }
};

int main(){
    return 0;
}
