#include <iostream>
using namespace std;

// 二叉树结点的描述  
typedef struct BiTNode  
{  
    char data;  
    struct BiTNode *lchild, *rchild;      // 左右孩子  
}BinaryTreeNode; 

// 节点只有左指针、右指针，没有parent指针，root已知
BinaryTreeNode* findLowestCommonAncestor(BinaryTreeNode* root , BinaryTreeNode* a , BinaryTreeNode* b)
{
	if(root == NULL)
		return NULL;
	if(root == a || root == b)
		return root;
	BinaryTreeNode* left = findLowestCommonAncestor(root->lchild , a , b);
	BinaryTreeNode* right = findLowestCommonAncestor(root->rchild , a , b);
	if(left && right)
		return root;
	return left ? left : right;
}

int main(){
	return 0;
}
