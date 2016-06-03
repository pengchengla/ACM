/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main1.cpp
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
        for(int i=0;i<str.length();){
            char ch = str[i];
            int count=0;
            while(ch==str[i] && i<str.length()){
                i++;
                count++;
            }
            if(count==1){
                ans+=ch;
            }
            else{
                ans+=to_string(count);
                ans+=ch;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
