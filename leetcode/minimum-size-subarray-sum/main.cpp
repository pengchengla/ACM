/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-01
*   描    述：
================================================================*/
#include <iostream>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int size = nums.size();
        if(size==0) return 0;
        
        int i=0,j=0;
        int minsize = INT_MAX;
        int cur = nums[i];
        bool flag = false;
        while(j<size){
            if(cur>=s && minsize>(j-i+1)) {minsize = j-i+1; flag = true;}
            if(cur>s){
                cur-=nums[i];
                i++;
                if(i>j) { j++; cur+=nums[j]; }
            }else if(cur<=s){
                j++;
                cur+=nums[j];
            }
        }
        if(!flag) return 0;
        return minsize;
    }
};

int main(){
    return 0;
}
