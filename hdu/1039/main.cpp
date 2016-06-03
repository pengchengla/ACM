/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-06-25
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
    string str="";
    while(cin>>str && str!="end"){
        int count_v = 0;
        int count_c = 0;
        bool flag1 = false;
        bool flag2 = true;
        bool flag3 = true;
        for(int i=0;i<str.length();i++){
            char cur = str[i];
            if(cur=='a'||cur=='e'||cur=='i'||cur=='o'||cur=='u') {
                flag1=true;
                count_v++;
                count_c = 0;
            }else{
                count_v = 0;
                count_c++;
            }
            if(count_v>=3 || count_c>=3){
                flag2 = false;
                break;
            }
            if(i==0) continue;
            char pre = str[i-1];
            if(pre==cur && (cur!='o' && cur!='e')){
                flag3 = false;
                break;
            }
        }
        if(flag1 && flag2 && flag3) cout<<"<"<<str<<"> is acceptable."<<endl;
        else cout<<"<"<<str<<"> is not acceptable."<<endl;
    }
    return 0;
}
