#include <iostream>
#include <string>
using namespace std;

struct Node{
	Node(){
		flag = false;
		for(int i=0;i<26;i++) next[i]=NULL;
	}
	bool flag;
	Node * next[26];
};

bool search(string & str,int & i, Node * & pTree){
	bool ans = true;
	for(int i=0;i<str.length();i++){
		int pos = str[i]-'a';
		if(pTree->next[pos]!=NULL){
			pTree = pTree->next[pos];
		}else{
			ans = false;
			break;
		}
	}
	return ans;
}

void handle(string & str,Node * pTree){
	int cur = 0;
	Node * ppTree = pTree;
	bool sans = search(str,cur,ppTree);
	if(sans && ppTree->flag) cout<<str<<" is correct"<<endl;
}
int main(){
	freopen("in.txt","r",stdin);
	Node * tree = new Node();
	string str;
	while(cin>>str && str!="#"){
		Node * pTree = tree;
		for(int i=0;i<str.length();i++){
			int pos = str[i]-'a';
			if(pTree->next[pos]==NULL){
				pTree->next[pos] = new Node();
			}
			pTree = pTree->next[pos];
		}
		pTree->flag = true;
	}
	while(cin>>str && str!="#"){
		handle(str,tree);
	}
	return 0;
}
