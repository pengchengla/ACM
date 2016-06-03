/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：ans.cpp
*   创 建 者：pengcheng
*   创建日期：2015-08-04
*   描    述：
================================================================*/
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    vector<vector<int> > threeSum(vector<int>& nums){
        if(nums.size() < 3) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int k = 0;
        // not necessary to check positive integers
        while (k < nums.size() && nums[k] <= 0){
            int i = k + 1;
            int j = nums.size() - 1;
            while (i < j){
                int sum = nums[i] + nums[j];
                if (sum < -nums[k]){
                    i++;
                }
                else if (sum > -nums[k]){
                    j--;
                }
                else{
                    vector<int> ans;
                    ans.push_back(nums[k]); ans.push_back(nums[i]); ans.push_back(nums[j]);
                    result.push_back(ans);
                    i++;
                    while (i < j && nums[i] == nums[i-1]) i++;
                    j--;
                    while (i < j && nums[j] == nums[j+1]) j--;
                }
            }
            k++;
            while (k < nums.size() && nums[k] == nums[k-1]) k++;
        }
        return result;
    }
};

int main(){
    return 0;
}
