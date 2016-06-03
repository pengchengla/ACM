/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：ans.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-24
*   描    述：
================================================================*/
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

#define SIZE 100003
vector<int> graph[SIZE];
vector<pair<int,int> > query[SIZE];
int ancestor[SIZE];
int gray[SIZE];
int ans[SIZE];

int order = 1;
map<string,int> hmap;
string toname[SIZE];

int getId(string name){
    if(hmap.find(name)==hmap.end()){
        hmap[name] = order;
        toname[order] = name;
        order++;
    }
    return hmap[name];
}

int getancestor(int id){
    if(gray[id]==1) return id;
    int tmp = getancestor(ancestor[id]);
    ancestor[id] = tmp;
    return tmp;
}

void travel(int root){
    gray[root] = 1;
    for(int i=0;i<query[root].size();i++){
        pair<int,int> pp = query[root][i];
        if(ans[pp.second]!=0) continue;
        if(gray[pp.first]==1) ans[pp.second] = pp.first;
        else if(gray[pp.first]==2) ans[pp.second] = getancestor(pp.first);
    }
    for(int i=0;i<graph[root].size();i++){
        travel(graph[root][i]);
    }
    gray[root] = 2;
}

int main(){
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif
    memset(ancestor,0,sizeof(ancestor));
    memset(gray,0,sizeof(gray));
    memset(ans,0,sizeof(ans));

    int N; cin>>N;
    for(int i=0;i<N;i++){
        string father,son;
        cin>>father>>son;
        int fid = getId(father);
        int sid = getId(son);

        graph[fid].push_back(sid);
        ancestor[sid] = fid;
    }

    cin>>N;
    for(int i=0;i<N;i++){
        string name1,name2;
        cin>>name1>>name2;
        int id1 = getId(name1);
        int id2 = getId(name2);
        query[id1].push_back(pair<int,int>(id2,i));
        query[id2].push_back(pair<int,int>(id1,i));
    }
    int root = 1;
    for(int i=1;i<order;i++){
        if(ancestor[i]==0){
            root=i;
            break;
        }
    }
    travel(root);
    for(int i=0;i<N;i++)
        cout<<toname[ans[i]]<<endl;
    return 0;
}
