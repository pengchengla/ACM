/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-28
*   描    述：
================================================================*/
#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        p = root;
        while(p){
            st.push(p);
            p = p->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty() || p;
    }

    /** @return the next smallest number */
    int next() {
        while(p){
            st.push(p);
            p = p->left;
        }
        p = st.top();
        st.pop();
        int ans = p->val;
        p = p->right;
        return ans;
    }
private:
    TreeNode * p ;
    stack<TreeNode *> st;
};

/**
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

int main(){
    return 0;
}
