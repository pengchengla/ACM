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

#define NUM 26

int total[NUM][NUM];
int visit[NUM][NUM];
int des = 'm'-'a';

bool dfs(int cur){
    if(cur==des) return true;
    for(int i=0;i<NUM;i++){
        if(total[cur][i]==1 && visit[cur][i]==0){
            visit[cur][i] = 1;
            if(dfs(i)) return true;
        }
    }
    return false;
}

int main(){
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif
    memset(total,0,sizeof(total));
    memset(visit,0,sizeof(visit));
    string str;
    while(cin>>str){
        if(str=="0"){
            string ans = dfs(1)?"Yes.":"No.";
            cout<<ans<<endl;
            memset(total,0,sizeof(total));
            memset(visit,0,sizeof(visit));
            continue;
        }
        char head = str[0];
        char tail = str[str.length()-1];
        total[head-'a'][tail-'a'] = 1;
    }
    return 0;
}
