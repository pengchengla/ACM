/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-28
*   描    述：
================================================================*/
#include <iostream>
#include <map>
#include <string>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> hmap1;
        map<char,char> hmap2;
        int size = s.length();
        for(int i=0;i<size;i++){
            if(hmap1.find(s[i])==hmap1.end()){
                hmap1.insert(pair<char,char>(s[i],t[i]));
            }else{
                if(hmap1[s[i]]!=t[i]) return false;
            }
            if(hmap2.find(t[i])==hmap2.end()){
                hmap2.insert(pair<char,char>(t[i],s[i]));
            }else{
                if(hmap2[t[i]]!=s[i]) return false;
            }
        }
        return true;
    }
};

int main(){
    Solution * solution = new Solution();
    cout<<solution->isIsomorphic("ab","aa")<<endl;
    return 0;
}
