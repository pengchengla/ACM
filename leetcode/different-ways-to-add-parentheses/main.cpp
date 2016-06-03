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
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> ans;
        int len = input.length();
        for(int i=0;i<len;i++){
            char cur = input[i];
            if(cur!='+' && cur!='-' && cur!='*') continue;
            vector<int> ans1 = diffWaysToCompute(input.substr(0,i));
            vector<int> ans2 = diffWaysToCompute(input.substr(i+1));
            for(int m=0;m<ans1.size();m++){
                for(int n=0;n<ans2.size();n++){
                    if(cur=='+') ans.push_back(ans1[m]+ans2[n]);
                    else if(cur=='-') ans.push_back(ans1[m]-ans2[n]);
                    else if(cur=='*') ans.push_back(ans1[m]*ans2[n]);
                }
            }
        }
        if(ans.empty()) ans.push_back(atoi(input.c_str()));
        return ans;
    }
};

int main(){
    return 0;
}
