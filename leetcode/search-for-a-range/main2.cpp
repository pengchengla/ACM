/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-30
*   描    述：
================================================================*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int i=0,j=nums.size()-1;
        int mid = (i+j)/2;
        while(i<j){
            if(nums[mid]<target) i=mid+1;
            else if(nums[mid]>target)j=mid-1;
            else if(nums[mid]==target) break;
            mid = (i+j)/2;
        }
        if(nums[mid]==target){
            int high = mid;
            while(high<=nums.size()-1 && nums[high]==target) high++;
            int low = mid;
            while(low>=0 && nums[low]==target) low--;
            ans.push_back(low+1);
            ans.push_back(high-1);
        }else{
            ans.push_back(-1);
            ans.push_back(-1);
        }
        return ans;
    }
};

int main(){
    return 0;
}
