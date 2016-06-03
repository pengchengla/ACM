/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-06-18
*   描    述：
================================================================*/

#include <iostream>
using namespace std;

const int rows=54;
int total[rows]={0};

int main(){
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif
    total[1]=1;
    total[2]=1;
    int a,b,n;
    while(cin>>a>>b>>n && a!=0 && b!=0 && n!=0){
        if(n==1 || n==2) cout<<total[n]<<endl;
        int i;
        for(i=3;i<rows;i++){
            total[i]=(a*total[i-1]+b*total[i-2])%7;
            if(total[i-1]==1 && total[i]==1) break;
        }
        i-=2;
        total[0]=total[i];
        n=n%i;
        cout<<total[n]<<endl;
    }
    return 0;
}
