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
    bool hasPathSum(TreeNode *root, int sum) 
    {
        if(!root) return false;
        int cur = root->val;
        return dfs(root,sum,cur);
    }
private:
    bool dfs(TreeNode * root, const int sum, int cur)
    {
        if(root&&!root->left&&!root->right&&cur==sum)
        {
            return true;
        }
        else
        {
            bool flag = false;
            if(root->left) flag = dfs(root->left,sum,cur+root->left->val);
            if(!flag&&root->right) flag = dfs(root->right,sum,cur+root->right->val);
            return flag;
        }
    }
};

int main()
{
    return 0;
}
