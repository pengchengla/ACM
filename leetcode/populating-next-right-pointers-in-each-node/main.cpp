/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-03
*   描    述：
================================================================*/
#include <iostream>
#include <queue>
using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        queue<TreeLinkNode *> qu;
        qu.push(root);
        qu.push(NULL);
        root->next = NULL;
        TreeLinkNode * pre = NULL;
        while(!qu.empty()){
            TreeLinkNode * cur = qu.front();
            qu.pop();
            if(cur){
                if(cur->left) qu.push(cur->left);
                if(cur->right) qu.push(cur->right);
            }else{
                if(qu.empty()) return ;
                qu.push(NULL);
            }
            if(pre==NULL) pre = cur;
            else{
                pre->next = cur;
                pre = cur;
            }
        }
    }
};

int main(){
    return 0;
}
