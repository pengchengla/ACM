/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-02
*   描    述：
================================================================*/
#include <iostream>
#include <vector>
#include <alogrithm>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        int i=0,j=0;
        int size = nums.size();
        int len = size/3;
        while(j<size){
            while(j<size && nums[i]==nums[j]){
                j++;
            }
            if((j-i)>len){
                ans.push_back(nums[i]);
            }
            i=j;
        }
        return ans;
    }
};

int main(){
    return 0;
}
