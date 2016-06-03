/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-11
*   描    述：
================================================================*/

#include <iostream>
#include <vector>
using namespace std;

struct node{
    int num;
    int index;
};

bool cmp(const node & a, const node & b){
    if(a.num < b.num) return true;
    return false;
}

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ans;
        node tmp[500];
        for(int i=0;i<numbers.size();i++){
            tmp[i].num = numbers[i];
            tmp[i].index = i+1;
        }
        sort(tmp,tmp+numbers.size(),cmp);
        int i=0;
        int j=numbers.size()-1;
        while(i<j){
            int t = tmp[i].num+tmp[j].num;
            if(t == target){
                ans.push_back(min(tmp[i].index,tmp[j].index));
                ans.push_back(max(tmp[j].index,tmp[i].index));
                break;
            }else if(t < target){
                i++;
            }else{
                j--;
            }
        }
        return ans;
    }
};


int main(){
    Solution * solution = new Solution();
    vector<int> nums;
    for(int i=-1;i>=-5;i--){
        nums.push_back(i);
    }
    vector<int> ans = solution->twoSum(nums,-8);
    cout<<ans[0]<<"  "<<ans[1]<<endl;
    return 0;
}
