/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：test.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-07
*   描    述：
================================================================*/
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> elems;
    for(int i=0;i<10;i++)
        elems.push_back(i);
    cout<<elems[elems.size()-1]<<endl;
    return 0;
}
