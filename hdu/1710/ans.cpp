/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：ans2.cpp
*   创 建 者：pengcheng
*   创建日期：2015-08-10
*   描    述：
================================================================*/
#include <iostream>
using namespace std;
#define NUM 1003
int preOrder[NUM];
int inOrder[NUM];
int lastOrder[NUM];

struct node {
    int val;
    node * left;
    node * right;
    node(){}
    node(int v){val = v; left=NULL; right=NULL;}
};

int getIndex(int num,int startIn,int endIn){
    for(int i=startIn;i<=endIn;i++)
        if(inOrder[i]==num) return i;
    return -1;
}

node * rebuild(int startPre,int endPre,int startIn,int endIn){
    if (startPre > endPre || startIn > endIn) return NULL; 
    node * root = new node(preOrder[startPre]);

    int index = getIndex(preOrder[startPre],startIn,endIn); 
    if (index == -1) return NULL;

    int len1 = index-startIn;
    root->left = rebuild(startPre+1,startPre+len1,startIn,startIn+len1-1);

    int len2 = endIn - index;
    root->right = rebuild(endPre-len2+1,endPre,endIn-len2+1,endIn);

    return root;
}

void postTraverse(node * root,int & index) {
    if (root->left) postTraverse(root->left,index);
    if (root->right) postTraverse(root->right,index);
    lastOrder[index++] = root->val;
}

int main(){ 
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif
    int n;
    while(cin>>n){
        for(int i=0;i<n;i++) cin>>preOrder[i];
        for(int i=0;i<n;i++) cin>>inOrder[i];
        node * root = rebuild(0,n-1,0,n-1);
        int index = 0;
        postTraverse(root,index);
        for(int i=0;i<n;i++){
            if(i!=n-1) cout<<lastOrder[i]<<" ";
            else cout<<lastOrder[i]<<endl;
        }
    }
    return 0;
}
