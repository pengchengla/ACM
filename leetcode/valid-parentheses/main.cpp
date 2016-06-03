/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-11
*   描    述：
================================================================*/
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if(s.length() == 0) return true;
        if(s.length()&1 == 1) return false;
        stack<char> st;
        bool flag = true;
        for(int i=0;i<s.length() && flag;i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                st.push(s[i]);
            }else if(st.empty()){
                flag = false;
            }else{
                if(s[i]==')'){
                    if(st.top()=='(') st.pop();
                    else flag = false;
                }else if(s[i]==']'){
                    if(st.top()=='[') st.pop();
                    else flag = false;
                }else if(s[i]=='}'){
                    if(st.top()=='{') st.pop();
                    else flag = false;
                }else{
                    flag = false;
                }
            }
        }
        if(!st.empty()) flag = false;
        return flag;
    }
};

int main(){
    return 0;
}
