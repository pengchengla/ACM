/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-28
*   描    述：
================================================================*/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        int i = 0;
        int len = s.length();
        while(s[i]==' ' && i<len) i++;
        if(i==len) return false;
        while(s[len-1]==' ') len--;
        if(s[i]=='-' || s[i]=='+') i++;
        int etime = 0;
        int ptime = 0;
        bool nbegin = false;
        bool isplus = false;
        bool afterplus = false;
        while(i<len){
            if(s[i]=='e' && etime==0) {
                if(!nbegin || etime>=1) return false;
                etime++;
                i++;
                if(i<len && (s[i]=='+' || s[i]=='-')) { isplus = true; i++; continue;}
                if(!(i<len && s[i]>='0' && s[i]<='9')) return false;
                continue;
            }
            if(s[i]=='.'){
                if(etime==1) return false;
                if(ptime>=1) return false;
                ptime++;
                i++;
                continue;
            }
            if(s[i]<'0' || s[i]>'9') return false;
            nbegin = true;
            if(isplus) afterplus = true;
            i++;
        }
        if(ptime==1 && !nbegin) return false;
        if(isplus && !afterplus) return false;
        return true;
    }
};

int main(){
    Solution * solution = new Solution();
    bool flag = solution->isNumber("46.e3");
    string str = flag?"true":"false";
    cout<<str<<endl;
    return 0;
}
