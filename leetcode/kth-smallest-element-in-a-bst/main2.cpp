/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-07
*   描    述：
================================================================*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int val = 0;
        int l = 0;
        inorder(root,l,k,val);
        return val;
    }
private:
    void inorder(TreeNode * root,int &l,const int k,int &val){
        if(root==NULL) return;
        inorder(root->left,l,k,val);
        l++;
        if(l==k){
            val=root->val;
            return;
        }
        inorder(root->right,l,k,val);
    }
};

int main(){
    return 0;
}
