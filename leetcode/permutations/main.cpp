/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-27
*   描    述：
================================================================*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        gen(nums,0,nums.size()-1);
        return ans;
    }
private:
    void gen(vector<int> & nums,int k,int m){
        if(k==m){
            ans.push_back(nums);
        }else{
            for(int i=k;i<=m;i++){
                swap(nums[i],nums[k]);
                gen(nums,k+1,m);
                swap(nums[i],nums[k]);
            }
        }
    }
private:
    vector<vector<int> > ans;
};

int main(){
    Solution * solution = new Solution();
    vector<int> nums;
    for(int i=1;i<4;i++) nums.push_back(i);
    vector<vector<int> > ans = solution->permute(nums);
    for(int i=0;i<ans.size();i++){
        vector<int> tmp = ans[i];
        for(int j=0;j<tmp.size();j++) cout<<tmp[j]<<" ";
        cout<<endl;
    }
    return 0;
}
