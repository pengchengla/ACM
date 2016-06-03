/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-08-03
*   描    述：
================================================================*/
#include <iostream>
#include <string>
using namespace std;
#define NUM 103

int main(){
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif
    string str; cin>>str;
    int fib[NUM]={0};
    fib[0] = 1;
    fib[1] = 1;
    for(int i=2;i<NUM;i++) fib[i]=fib[i-1]+fib[i-2];

    int len = str.length();
    for(int i=0;i<len;i++){
        for(int l=1;l<NUM;l++){
            if((len-i)<=fib[l]){
                cout<<str.substr(i,fib[l])<<endl;
            }
        }
    }
    return 0;
}
