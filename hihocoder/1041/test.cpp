/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：test.cpp
*   创 建 者：pengcheng
*   创建日期：2015-08-04
*   描    述：
================================================================*/
#include <iostream>
#include <bitset>
using namespace std;

#define MAX 5

bitset<MAX> total[MAX];

int main(){
    for(int i=0;i<MAX;i++) total[i].reset();
    total[0][3] = 1;
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            cout<<total[i][j]<<" ";
        }
        cout<<endl;
    }
    total[1] |= total[0];
    cout<<"------------------------"<<endl;
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            cout<<total[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
