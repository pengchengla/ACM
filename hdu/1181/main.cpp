/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-08-07
*   描    述：
================================================================*/
#include <iostream>
#include <string>
using namespace std;

struct node{
    char ch;
    node * next;
    node(){}
    node(char c){ch = c;next = NULL;}
};
node total[26];

bool dfs(node * cur){
    node * list = cur;
    while(list!=NULL){
        if(list->ch=='m') return true;
        int ne = (list->ch)-'a';
        if(dfs(total[ne].next)) return true;
        list = list->next;
    }
    return false;
}

int main(){
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif
    for(int i=0;i<26;i++) total[i].ch='a'+i;
    string str;
    while(cin>>str && str!="0"){
        char head = str[0];
        char tail = str[str.length()-1];
        node * cur = new node(tail);
        cur->next = total[head-'a'].next;
        total[head-'a'].next = cur;
    }
    string ans = dfs(total[1].next)?"Yes.":"No.";
    cout<<ans<<endl;
    return 0;
}
