/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-09
*   描    述：
================================================================*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<int> tmp;
        int pos = 1;
        dfs(k,n,pos,tmp);
        return ans;
    }
private:
    vector<vector<int> > ans;
private:
    bool dfs(int k,int n, int pos, vector<int> & tmp){
        if(n<0) return false;
        if(k==0 && n==0) return true;
        for(int i=pos;i<=9;i++){
            tmp.push_back(i);
            bool flag = dfs(k-1,n-i,i+1,tmp);
            if(flag) ans.push_back(tmp);
            tmp.pop_back();
        }
        return false;
    }
};

int main(){
    return 0;
}
