/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：ac.cpp
*   创 建 者：pengcheng
*   创建日期：2015-06-18
*   描    述：
================================================================*/

#include <iostream>
#include <string>
using namespace std;

#define MAXN 100
int f[MAXN];
int A, B, n;
int st, en;

bool judge(int pos){
    for (int j = 1; j + 1 < pos; j++){
        if (f[j] == f[pos - 1] && f[j + 1] == f[pos]){
            st = j;
            en = pos - 2;
            return true;
        }
    }
    return false;
}

int main(){
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif
    while (cin>>A>>B>>n && A && B && n){
        f[1] = f[2] = 1;
        for (int i = 3; i < 98; i++){
            f[i] = (A * f[i - 1] + B * f[i - 2]) % 7;
            if (judge(i))
                break;
        }

        n = (n - (st - 1)) % (en - st + 1);
        if (n)
            cout<<f[n+st-1]<<endl;
        else
            cout<<f[en]<<endl;
    }
    return 0;
}
