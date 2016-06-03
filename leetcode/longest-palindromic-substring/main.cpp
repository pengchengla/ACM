/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-06-30
*   描    述：
================================================================*/
#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()==0) return s;
        string ans = s.substr(0,1);
        int max = 1;
        int len = s.length();
        for(int i=0;i<len;i++){
            //ji
            bool flag = false;
            int l=i-1; int r=i+1;
            while(l>=0 && r<len && s[l]==s[r]){
                l--;
                r++;
                flag = true;
            }
            if(flag && (r-l-1)>max) { ans = s.substr(l+1,r-l-1); max = r-l-1; }
            
            //ou
            flag = false;
            l=i;r=i+1;
            while(l>=0 && r<len && s[l]==s[r]){
                l--;
                r++;
                flag = true;
            }
            if(flag && (r-l-1)>max) { ans = s.substr(l+1,r-l-1); max = r-l-1; }
        }
        return ans;
    }
};

int main(){
    Solution * solution = new Solution();
    cout<<solution->longestPalindrome("bb")<<endl;
    return 0;
}
