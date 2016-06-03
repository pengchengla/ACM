/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-06-25
*   描    述：
================================================================*/

#include <iostream>
#include <algorithm>
using namespace std;

struct item{
    int p,q,v;
    bool operator < (const item i)const{
        return q-p<i.q-i.p;
    }
}it[503];

int main(){
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif
    int kind,money;
    int f[5003];
    while(cin>>kind>>money){
        memset(it,0,sizeof(it));
        memset(f,0,sizeof(f));

        for(int i=0;i<kind;++i) cin>>it[i].p>>it[i].q>>it[i].v;

        sort(it,it+kind);

        for(int i=0;i<kind;i++){
            for(int sv=money;sv>=it[i].p&&sv>=it[i].q;sv--){
                int tmp = f[sv-it[i].p]+it[i].v;
                f[sv] = tmp>f[sv] ? tmp : f[sv];
            }
        }
        cout<<f[money]<<endl;
    }
    return 0;
}
