/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-02
*   描    述：
================================================================*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        int i=0,j=size-1;
        int index = 0;
        while(i+1<j){
            int mid = (i+j)/2;
            if(nums[mid]>nums[i]) i=mid;
            else j=mid;
        }
        if(nums[i]<nums[j]) index=i;
        else index=j;
        if(nums[0]<=target && target<=nums[index-1]) {
            return binsearch2(nums,0,index-1,target);
        }
        else if(nums[index]<=target && target<=nums[size-1]) {
            return binsearch2(nums,index,size-1,target);
        }
        return -1;
    }
    
    int binsearch2(vector<int> & nums, int i, int j, int target){
        while(i<=j){
            int mid = (i+j)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) j=mid-1;
            else i=mid+1;
        }
        return -1;
    }
};

int main(){
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(1);
    Solution * solution = new Solution();
    cout<<solution->search(nums,3)<<endl;
    return 0;
}
