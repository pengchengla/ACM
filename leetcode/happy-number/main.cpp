/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-03
*   描    述：
================================================================*/
#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        set<int> hset;
        while(1){
            n = cal(n);
            if(n==1) return true;
            if(hset.find(n)!=hset.end()) return false;
            hset.insert(n);
        }
    }
private:
    int cal(int n){
        int x = 0;
        while(n){
            x += (n%10)*(n%10);
            n/=10;
        }
        return x;
    }
};

int main(){
    return 0;
}
