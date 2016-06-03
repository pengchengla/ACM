/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-13
*   描    述：
================================================================*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > ans;
        sort(nums.begin(),nums.end());
        int size = nums.size();
        if(size<3) return ans;
        for(int p = 0; p<size-3; p++){
            int p1 = p+1;
            int p2 = size-1;
            int target = -nums[0];
            while(p1<p2){
                int sum = nums[p1] + nums[p2];
                if(sum==target){
                    vector<int> _ans;
                    _ans.push_back(nums[p]); _ans.push_back(nums[p1]); _ans.push_back(nums[p2]);
                    ans.push_back(_ans);
                    break;
                }else if(sum<target){
                    p1++;
                }else if(sum>target){
                    p2--;
                }
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(3);
    Solution * solution = new Solution();
    solution->threeSum(nums);
    return 0;
}
