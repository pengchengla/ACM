/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-01
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
    bool isSymmetric(TreeNode* root) {
        midSearch(root);
        int size = ans.size();
        int i = 0,j = size;
        while(i<j){
            if(ans[i]!=ans[j]) return false;
            i++; j--;
        }
        return true;
    }
private:
    vector<int> ans;
private:
    void midSearch(TreeNode * root){
        if(root==NULL) return;
        midSearch(root->left);
        ans.push_back(root->val);
        midSearch(root->right);
    }
};

int main(){
    return 0;
}
