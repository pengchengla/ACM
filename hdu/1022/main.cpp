/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-06-19
*   描    述：
================================================================*/
#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

int main(){
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif
    queue<string> qu;
    stack<int> st;
    int count;
    string in,out;
    while(cin>>count>>in>>out){
        if(count==0 || in.length() != out.length()) continue;
        while(!st.empty()){
            st.pop();
        }
        while(!qu.empty()){
            qu.pop();
        }
        int i,j;
        for(i=0,j=0;i<in.length()&&j<out.length();){
            while(i<in.length() && in[i]!=out[j]){
                st.push(in[i]);
                i++;
                qu.push("in");
            }
            if(i<in.length()){
                st.push(in[i]);
                i++;
                qu.push("in");
            }
            while(j<out.length() && !st.empty() && st.top()==out[j]){
                st.pop();
                j++;
                qu.push("out");
            }
        }
        if(i==in.length() && j==out.length() && st.empty()){
            cout<<"Yes."<<endl;
            while(!qu.empty()){
                cout<<qu.front()<<endl;
                qu.pop();
            }
        }
        else
            cout<<"No."<<endl;
        cout<<"FINISH"<<endl;
    }
    return 0;
}
