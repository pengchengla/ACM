/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-21
*   描    述：
================================================================*/
#include <iostream>
using namespace std;

int main(){
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt", "r", stdin);
#endif
    int total[1003];
    int count = 0;
    while(cin>>count && count!=0){
        int max = 0;
        memset(total,0,sizeof(total));

        int dp_seq[1003]={1};
        int dp_max[1003]={0};

        for(int i=0;i<count;i++){
            cin>>total[i];
            dp_max[i] = total[i];
            if(max<dp_max[i])  max = dp_max[i];
        }

        for(int i=0;i<count;i++){
            if(total[i]>max) max = total[i];
            for(int j=0;j<i;j++){
                if(total[i]>total[j] && dp_seq[i]<=dp_seq[j]){
                    dp_seq[i] = dp_seq[j]+1;
                    dp_max[i] = dp_max[j] + total[i];
                    if(dp_max[i]>max) max = dp_max[i];
                }
            }
        }
        cout<<max<<endl;
    }
    return 0;
}
