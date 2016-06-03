/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-06
*   描    述：
================================================================*/
#include <iostream>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0) return 0;
        else if(nums.size()==1) return nums[0];
        else if(nums.size()==2) return max(nums[0],nums[1]);
        int * dp = new int[nums.size()];
        memset(dp,0,sizeof(int)*nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++){
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        }   
        return dp[nums.size()-1];
    }   
};

int main(){
    return 0;
}
