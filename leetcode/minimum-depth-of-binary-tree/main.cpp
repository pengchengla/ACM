#include <iostream>
#include <queue>
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
    queue<TreeNode*> qu;
public:
    int minDepth(TreeNode *root) 
    {
        if(root==NULL) return 0;
        qu.push(root);
        qu.push(NULL);
        int dep=1;
        while(!qu.empty())
        {
            TreeNode * tmp = qu.front();
            qu.pop();
            if(tmp==NULL)
            {
                dep+=1;
                qu.push(NULL);
            }
            else if(tmp->left==NULL && tmp->right==NULL)
            {
                break;
            }
            else
            {
                if(tmp->left) qu.push(tmp->left);
                if(tmp->right) qu.push(tmp->right);
            }
        }
        return dep;
    }
};


int main()
{
    return 0;
}
