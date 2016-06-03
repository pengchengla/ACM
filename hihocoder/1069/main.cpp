/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-30
*   描    述：
================================================================*/
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

#define SIZE 100003
vector<int> tree[SIZE];
int root = 1;

int order = 1;
map<string,int> hmap;
string toname[SIZE];
int getid(string name){
    if(hmap.find(name)==hmap.end()){
        hmap[name] = order;
        toname[order++] = name;
    }
    return hmap[name];
}

bool getpath(int curr,int nid,vector<int>& path){
    path.push_back(curr);
    if(curr==nid) return true;
    for(int i=0;i<tree[curr].size();i++){
        if(getpath(tree[curr][i],nid,path)) return true;
    }
    path.pop_back();
    return false;
}

int getans(int nid1, int nid2){
    vector<int> path1; getpath(root,nid1,path1);
    vector<int> path2; getpath(root,nid2,path2);

    int len = min(path1.size(),path2.size());
    int ans = 0;
    for(int i=0;i<len;i++){
        if(path1[i]==path2[i]) ans = path1[i];
        else break;
    }
    return ans;
}

int main(){
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif
    int N; cin>>N;
    while(N--){
        string father,son;
        cin>>father>>son;
        tree[getid(father)].push_back(getid(son));
    }
    cin>>N;
    while(N--){
        string name1,name2;
        cin>>name1>>name2;
        cout<<toname[getans(getid(name1),getid(name2))]<<endl;
    }
    return 0;
}
