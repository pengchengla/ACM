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
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int sums = (C-A)*(D-B) + (G-E)*(H-F);
        if(A>=G || E>=C || F>=D || B>=H) return sums;
        int top = min(D,H);
        int right = min(C,G);
        int bottom = max(B,F);
        int left = max(A,E);

        int coms = (top-bottom) * (right-left);
        return sums - coms;
    }
};

int main(){
    return 0;
}
