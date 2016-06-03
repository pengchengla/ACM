/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-02
*   描    述：
================================================================*/
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int b = 0;
        int e = 0;
        int len = s.length();
        while(s[len-1]==' '){
            len--;
        }
        while(e<len){
            if(s[e]==' ') b=e+1;
            e++;
        }
        return e-b;
    }
};

int main(){
    return 0;
}
