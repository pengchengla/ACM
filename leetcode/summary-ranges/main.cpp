/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-06-28
*   描    述：
================================================================*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int size = nums.size();
        string tmp = "";
        int start=0,end=0;
        for(int i=0;i<size;i++){
            tmp = "";
            start = nums[i];
            end = nums[i];
            while((i+1)<size && nums[i]+1==nums[i+1]){
                i++;
                end = nums[i];
            }
            if(start!=end)  tmp = to_string(start) + "->" + to_string(end);
            else tmp = to_string(start);
            ans.push_back(tmp);
        }
        return ans;
    }
};

int main(){
    return 0;
}
