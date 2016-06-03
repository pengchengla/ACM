/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-01
*   描    述：
================================================================*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int i=0,j=0;
        map<int,vector<int> > hmap;
        map<int,vector<int> >::iterator it;
        for(int i=0;i<nums.size();i++){
            if(hmap.find(nums[i])!=hmap.end()){
                vector<int> & tmp = hmap[nums[i]];
                tmp.push_back(i);
            }else{
                vector<int> tmp;
                tmp.push_back(i);
                hmap[nums[i]] = tmp;
            }
        }
        for(it=hmap.begin();it!=hmap.end();it++){
            vector<int> & tmp = it->second;
            if(tmp.size()<=1) continue;
            for(int i=0;i<tmp.size()-1;i++){
                if((tmp[i+1]-tmp[i])<=k) return true;
            }
        }
        return false;
    }
};

int main(){
    return 0;
}
