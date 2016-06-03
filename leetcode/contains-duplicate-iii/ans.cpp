/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：ans.cpp
*   创 建 者：pengcheng
*   创建日期：2015-08-04
*   描    述：
================================================================*/
bool cmpptr(int *a, int *b){
    return *a < *b; 
}
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
      const int N = nums.size();
      vector<int*> numptrs(N);
      for(int i = 0; i < N; ++i){
         numptrs[i] = &nums[i];
      }
      sort(numptrs.begin(), numptrs.end(), cmpptr);
      if(0 == k) return false;
      for(int i = 0; i < N; ++i){
          for(int j = i + 1; j < N; ++j){
               //nums[i] and nums[j] is at most t
              if((*numptrs[j]) > (*numptrs[i]) + t) 
                     break;
              //the difference between i and j is at most k
              if(abs(numptrs[j] - numptrs[i]) <= k) return true;
          }
      }
       return false;
    }

};
