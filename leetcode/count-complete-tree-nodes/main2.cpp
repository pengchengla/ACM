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
        int count = 0;
        int height = getHeight(root);
        int cur = 0;
        TreeNode * pNode = root;
        TreeNode * tmp = pNode;
        for(int h=height;h>1;h--){
            cur = h-1;
            tmp = pNode->left;
            for(int c=cur;c>1;c--){
                tmp = tmp->right;
            }
            if(tmp->left && !tmp->right){
                pNode = pNode->left;
                count += ((pow(2,cur)-1) + 1);
            }else if(tmp->left && tmp->right){
                pNode = pNode->right;
                count += ((pow(2,cur+1)-1) + 1);
            }else if(!tmp->left && !tmp->right){
                pNode = pNode->left;
                count += ((pow(2,cur)-1) + 1);
            }
        }
        if(pNode->right) count+=3;
        else if(pNode->left) count+=2;
        else count++;
        return count;
    }
private:
    int getHeight(TreeNode * root){
        int height = 0;
        while(root){
            height++;
            root=root->right;
        }
        return height;
    }
};

int main(){
    return 0;
}
