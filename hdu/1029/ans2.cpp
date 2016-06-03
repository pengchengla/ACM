/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：ans2.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-07
*   描    述：
================================================================*/
#include <iostream>
using namespace std;

int main(){
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif
    int n = 0;
    while(cin>>n){
        int count=0,max=0,tmp=0;
        for(int i=0;i<n;i++){
            cin>>tmp;
            if(count==0){
                count=1;
                max=tmp;
            }else{
                if(tmp!=max) count--;
                else count++;
            }
        }
        cout<<max<<endl;
    }
}
