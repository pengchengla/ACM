/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：ans.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-24
*   描    述：
================================================================*/
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <cstring>
using namespace std;

#define SIZE 100010

vector<int> tree[SIZE];
int color[SIZE];
int ancestor[SIZE];
vector<pair<int, int> > query[SIZE];

int ans[SIZE];

int order = 1;
map<string, int> a2i;
string i2a[SIZE];

int getid(string str){
    if(a2i.find(str)==a2i.end()){
        a2i[str] = order;
        i2a[order] = str;
        order++;
    }
    return a2i[str];
}

int find_gray(int node) {
    if (color[node] == 1)
        return node;
    int gray = find_gray(ancestor[node]);
    ancestor[node] = gray;
    return gray;
}

void traverse(int root) {
    color[root] = 1;
    for(vector<pair<int,int> >::iterator q=query[root].begin();  q!=query[root].end();  q++){
        if (ans[q->second] != 0)
            continue;
        if (color[q->first] == 1)
            ans[q->second] = q->first;
        if (color[q->first] == 2)
            ans[q->second] = find_gray(q->first);
    }
    for(vector<int>::iterator c=tree[root].begin();  c!=tree[root].end();  c++)
        traverse(*c);
    color[root] = 2;
}

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif
    memset(color, 0, SIZE * sizeof(int));
    memset(ancestor, 0, SIZE * sizeof(int));
    memset(ans, 0, SIZE * sizeof(int));
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string father, son;
        int fatheri, soni;
        cin >> father >> son;

        fatheri = getid(father);
        soni = getid(son);

        tree[fatheri].push_back(soni);

        ancestor[soni] = fatheri;
        cout<<"ancestor["<<soni<<"]="<<fatheri<<endl;
        color[fatheri] = color[soni] = 0;
    }
    cout<<"=="<<endl;
    for(int i=1;i<order;i++) cout<<"ancestor["<<i<<"]="<<ancestor[i]<<endl;
    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        string name1, name2;
        int num1, num2;
        cin >> name1 >> name2;
        num1 = getid(name1);
        num2 = getid(name2);
        query[num1].push_back(pair<int, int>(num2, i));
        query[num2].push_back(pair<int, int>(num1, i));
    }
    traverse(1);
    for (int i = 0; i < M; i++)
        cout << i2a[ans[i]] << endl;
    return 0;
}
