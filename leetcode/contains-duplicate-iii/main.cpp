/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-01
*   描    述：
================================================================*/
#include <iostream>
using namespace std;

struct node{
    int num;
    int index;
    node(){}
}total[100003];

bool cmp(const node & fir, const node & sec){
    if(fir.num > sec.num || fir.index > sec.index) return true;
    return false;
}

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        for(int i=0;i<nums.size();i++){
            total[i].num = nums[i];
            total[i].index = i;
        }
        sort(total,total+nums.size(),cmp);
        int size = nums.size();
        int start = 0;
        int end = size()-1;
        int mid = (start+end)/2;
        for(int i=0;i<size;i++){
            int tmp = total[i].num + k;
            //找到第一个小于等于tmp的数值
            while(start<end){
                int mv = total[mid].num;
                if(mv > tmp) end = mid-1;
                else if(mv < tmp) start = mid+1;
                else break;
            }
            if(total[mid].index)
        }
        return false;
    }
};

int main(){
    return 0;
}
