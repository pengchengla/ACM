/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-06-21
*   描    述：
================================================================*/
#include <iostream>
using namespace std;

int main(){
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif
    const int up=6,down=4,stay=5;
    int base = 0, cur = 0;
    int count = 0;
    int diff = 0;
    while(cin>>count){
        if(count==0) break;
        base = 0;
        int ans = (count*stay);
        for(int i=0;i<count;i++){
            cin>>cur;
            diff = cur-base;
            if(diff>0){
                ans += (up*diff);
            }else{
                diff = 0 - diff;
                ans += (down*diff);
            }
            base = cur;
        }
        cout<<ans<<endl;
    }
    return 0;
}
