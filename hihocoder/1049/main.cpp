#include <iostream>
#include <string>
using namespace std;

struct node{
	node(char pch){ch = pch;}
	char ch;
	node * left;
	node * right;
};

string pre,in;
int mapIndex[256];
void toMap(){
	for(int i=0;i<in.length();i++)
		mapIndex[in[i]] = i;
}

int pstart = 0;
node * build(int istart,int iend){
	if(pstart>pre.length()-1 || istart>iend) return NULL;
	int pos = mapIndex[pre[pstart]];
	node * tree = new node(pre[pstart]);
	pstart++;
	tree->left = build(istart,pos-1);
	tree->right = build(pos+1,iend);
	return tree;
}

void travel(node * tree){
	if(tree==NULL) return;
	if(tree->left) travel(tree->left);
	if(tree->right) travel(tree->right);
	cout<<tree->ch;
}

int main(){
#ifdef ONLINE_JUDGE
#else
	freopen("in.txt","r",stdin);
#endif
	cin>>pre>>in;
	toMap();
	pstart = 0;
	node * tree = build(0,in.length()-1);
	travel(tree);
	cout<<endl;
	return 0;
}
