#include <iostream>
#include <string>
using namespace std;

struct node{
	node(char c){ch = c;}
	char ch;
	node * left;
	node * right;
};

string pre,in;
int mpos[256];
void toPos(){
	for(int i=0;i<in.length();i++)
		mpos[in[i]] = i;
}

int pos=0;
node * build(int start,int end){
	if(pos>pre.length()-1 || start>end) return NULL;
	node * root = new node(pre[pos]);
	int bre = mpos[pre[pos]];
	pos++;
	root->left = build(start,bre-1);
	root->right = build(bre+1,end);
	return root;
}

void scan(node * tree){
	if(tree==NULL) return;
	scan(tree->left);
	scan(tree->right);
	cout<<tree->ch;
}

int main(){
#ifdef ONLINE_JUDGE
#else
	freopen("in.txt","r",stdin);
#endif
	cin>>pre>>in;
	toPos();
	node * root = build(0,in.length()-1);
	scan(root);
	cout<<endl;
	return 0;
}
