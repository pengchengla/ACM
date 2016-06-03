/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-06-22
*   描    述：
================================================================*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif
    string str;
    while(cin>>str){
        sort(str.begin(),str.end());
        for(int i=0;i<str.length();i++){
            cout<<str[i];
            if(i!=str.length()-1)
                cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}
