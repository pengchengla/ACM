/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-06-18
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
    int tc;
    cin>>tc;
    while(tc--){
        string str;
        cin>>str;
        string ans="";
        int count = 0;
        char ch = str[0];
        for(int i=0;i<str.length();i++){
            if(ch==str[i]){
                count++;
            }
            else{
                if(count==1){
                    ans+=ch;
                }
                else{
                    ans+=to_string(count);
                    ans+=ch;
                }
                ch=str[i];
                count=1;
            }
        }
        if(count!=1){
            ans+=to_string(count);
            ans+=ch;
        }
        else{
            ans+=ch;
        }
        cout<<ans<<endl;
    }
    return 0;
}
