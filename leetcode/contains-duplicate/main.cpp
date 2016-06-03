/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-01
*   描    述：
================================================================*/
#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> hset;
        int size = nums.size();
        for(int i=0;i<size;i++){
            if(hset.find(nums[i])!=hset.end()) return true;
            hset.insert(nums[i]);
        }
        return false;
    }
};

int main(){
    return 0;
}
