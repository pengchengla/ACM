/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-08-04
*   描    述：
================================================================*/
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        vector<vector<int> > result;
        int n = nums.size();
        if (n < 4) return result;
        sort(nums.begin(), nums.end());

        int i = 0;
        while (i < n){
            int j = i+1;
            while (j < n){
                int sum = target - nums[i] - nums[j];
                int left = j+1;
                int right = n-1;
                while (left < right){
                    int value = nums[left] + nums[right];
                    if (sum == value){
                        vector<int> temp;
                        temp.push_back(nums[i]); temp.push_back(nums[j]);
                        temp.push_back(nums[left]); temp.push_back(nums[right]);
                        result.push_back(temp);
                        left++;
                        while (left < right && nums[left] == nums[left-1]) left++;
                        right--;
                        while (left < right && nums[right] == nums[right+1]) right--;
                    }
                    else if (value > sum) right--;
                    else left++;
                }
                j++;
                while(j<n && nums[j]==nums[j-1]) j++;
            }
            i++;
            while(i<n && nums[i]==nums[i-1]) i++;
        }
        return result;
    }
};

int main(){
    return 0;
}
