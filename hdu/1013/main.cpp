/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-06-22
*   描    述：
================================================================*/

#include <iostream>
#include <string>
using namespace std;

int main(){
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif
    string str;
    while(cin>>str && str[0]!='0'){
        int value = 0;
        for(int i=0;i<str.length();i++){
            value += str[i]-'0';
        }
        int ans = 0;
        while(true){
            while(value!=0){
                int sub = value%10;
                int high = value/10;
                value = high;
                ans+=sub;
            }
            if(ans/10==0)
                break;
            value = ans;
            ans = 0;
        }
        cout<<ans<<endl;
    }
    return 0;
}
