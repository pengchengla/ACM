/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-06-25
*   描    述：
================================================================*/
#include <iostream>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t v = n;
        v =((v >>1)&0x55555555)|((v &0x55555555)<<1);
        v =((v >>2)&0x33333333)|((v &0x33333333)<<2);
        v =((v >>4)&0x0F0F0F0F)|((v &0x0F0F0F0F)<<4);
        v =((v >>8)&0x00FF00FF)|((v &0x00FF00FF)<<8);
        v =( v >>16)|( v <<16);
        return v;
    }
};

int main(){
    Solution * solution = new Solution();
    cout<<solution->reverseBits(1)<<endl;
    return 0;
}
