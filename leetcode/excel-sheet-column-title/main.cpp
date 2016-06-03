/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-09
*   描    述：
================================================================*/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string ans = "";
        while(n){
            int tmp = n%26 + 1;
            n/=26;
            ans += (tmp+64);
        }
        return ans;
    }
};

int main(){
    string tmp = "";
    tmp+=(1+64);
    cout<<tmp<<endl;
    int num = 26%26;
    cout<<num<<endl;
    cout<<26/26<<endl;
    return 0;
}
