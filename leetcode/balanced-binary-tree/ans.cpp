#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution 
{
private:
    bool isBalancedRetHeight(struct TreeNode *root,int *height) {
        if(NULL==root){
            *height=0;
            return true;
        }

        int l_d;
        if(!isBalancedRetHeight(root->left,&l_d)) return false;

        int r_d;
        if(!isBalancedRetHeight(root->right,&r_d)) return false;

        if(abs(l_d-r_d)>1) return false;

        *height= (l_d>r_d?l_d:r_d)+1;
        return true;
    }

public:
    bool isBalanced(struct TreeNode* root) {
        int height=0;

        return isBalancedRetHeight(root,&height);
    }
};

int main(){
    return 0;
}
