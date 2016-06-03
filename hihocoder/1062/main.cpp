/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-23
*   描    述：
================================================================*/
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main(){
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif
    int N; cin>>N;
    map<string,string> hmap;
    while(N--){
        string parent,son;
        cin>>parent>>son;
        hmap[son] = parent;
    }
    
    int M; cin>>M;
    while(M--){
        vector<string> ans1;
        vector<string> ans2;
        string a; cin>>a;
        string b; cin>>b;
        ans1.push_back(a);
        ans2.push_back(b);
        while(hmap.find(a)!=hmap.end()){
            ans1.push_back(hmap[a]);
            a = hmap[a];
        }
        while(hmap.find(b)!=hmap.end()){
            ans2.push_back(hmap[b]);
            b = hmap[b];
        }

        int s1 = ans1.size()-1;
        int s2 = ans2.size()-1;
        string ans="";
        while(s1>=0 && s2>=0){
            if(ans1[s1]!=ans2[s2]) break;
            ans = ans1[s1];
            s1--;
            s2--;
        }
        if(ans=="") cout<<-1<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}
