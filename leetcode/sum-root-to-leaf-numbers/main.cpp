#include <iostream>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution 
{
public:
    int sumNumbers(TreeNode *root) 
    {
        int ans = 0;
        if(!root) return ans;
        int cur = root->val;
        dfs(root,cur,ans);
        return ans;
    }
private:
    void dfs(TreeNode * root, int cur, int & ans)
    {
        if(!root->left && !root->right)
        {
            ans+=cur;
        }
        else
        {
            if(root->left)  dfs(root->left,cur*10+root->left->val,ans); 
            if(root->right)  dfs(root->right,cur*10+root->right->val,ans);
        }
    }
};

int main()
{
    return 0;
}
