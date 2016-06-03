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
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int count = 1;
        qu.push(root);
        while(!qu.empty()){
            TreeNode * tmp = qu.front();   qu.pop();
            if(tmp->left) {qu.push(tmp->left); count++;}
            if(tmp->right) {qu.push(tmp->right); count++;}
        }
        return count;
    }
private:
    queue<TreeNode *> qu;
};

int main(){
    return 0;
}
