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
public:
    bool isBalanced(TreeNode *root) {
        if(!root) return true;
        int left=1;
        int right=1;
        dfs(root,left,right);
    }
private:
    void dfs(TreeNode * root, int left, int right){
        if(!root) return;
    }
};

int main(){
    return 0;
}
