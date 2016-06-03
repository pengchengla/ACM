/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：ans.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-13
*   描    述：
================================================================*/
#include <iostream>
using namespace std;

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return judge(root->left,root->right);
    }
private:
    bool judge(TreeNode * left,TreeNode * right){
        if(!left && !right) return true;
        if(!left || !right) return false;
        if(left->val != right->val) return false;
        return judge(left->left,right->right) && judge(right->left,left->right);
    }
};

int main(){
    return 0;
}
