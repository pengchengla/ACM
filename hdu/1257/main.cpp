/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-08-07
*   描    述：
================================================================*/
#include <iostream>
using namespace std;

#define NUM 1003;

int total[NUM];

int main(){
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif
    int n; cin>>n;
    for(int i=0;i<n;i++) cin>>total[i];
    return 0;
}
