/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-06-30
*   描    述：
================================================================*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        init();
        vector<string> ans;
        if(digits.length()==0) return ans;
        string tmp = "";
        dfs(digits,0,ans,tmp);
        return ans;
    }
private:
    string hmap[10];
private:
    void dfs(string digits,int pos,vector<string> & ans,string tmp){
        if(pos>=digits.length()){
            ans.push_back(tmp);
            return;
        }
        int hpos = digits[pos]-'0';
        int sublen = hmap[hpos].length();
        for(int j=0;j<sublen;j++){
            tmp+=hmap[hpos].at(j);
            dfs(digits,pos+1,ans,tmp);
            tmp.pop_back();
        }
    }

    void init(){
        char ch = 'a';
        for(int i=2;i<10;i++){
            string tmp="";
            int count = 3;
            if(i==7 || i==9) count = 4;
            for(int k=0;k<count;k++){
                tmp+=ch;
                ch++;
            }
            hmap[i]=tmp;
        }
    }
};

int main(){
    Solution * solution = new Solution();
    solution->letterCombinations("23");
    return 0;
}
