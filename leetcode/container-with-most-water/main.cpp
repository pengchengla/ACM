/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-08-04
*   描    述：
================================================================*/
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int ans = 0;
        while(left<right){
            int tmp = min(height[left],height[right]) *(right-left);
            if(tmp>ans) ans = tmp;
            if(height[left]<height[right]) left++;
            else right--;
        }
        return ans;
    }
};

int main(){
    return 0;
}
