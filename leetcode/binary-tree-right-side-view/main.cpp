/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-06-25
*   描    述：
================================================================*/

#include <iostream>
#include <vector>
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
    vector<int> rightSideView(TreeNode* root) {
        return levelSearch(root);
    }

private:
    vector<int> levelSearch(TreeNode * root){
        vector<int> vec;
        if(root==NULL) return vec;
        TreeNode * right = root;
        queue<TreeNode *> qu;
        qu.push(root);
        qu.push(NULL);
        while(!qu.empty()){
            TreeNode * tmp = qu.front();
            qu.pop();
            if(tmp==NULL){
                if(!qu.empty()) qu.push(NULL);
                vec.push_back(right->val);
                continue;
            }
            right = tmp;
            if(tmp->left) qu.push(tmp->left);
            if(tmp->right) qu.push(tmp->right);
        }
        return vec;
    }
};

int main(){
    return 0;
}
