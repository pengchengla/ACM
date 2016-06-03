/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-23
*   描    述：
================================================================*/
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
#define COUNT 10003

int father[COUNT];
int k=1;
map<string,int> hmap;

int getfather(int x){
    while(x!=father[x])
        x = father[x];
    return x;
}

void reunion(int a,int b){
    int x = getfather(a);
    int y = getfather(b);
    if(x!=y) father[x] = y;
}

int issame(int a,int b){
    return getfather(a) == getfather(b);
}

int slove(string str){
    if(hmap.find(str)==hmap.end())
        hmap[str] = k++;
    return hmap[str];
}


int main(){
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif
    for(int i=0;i<COUNT;i++) father[i]=i;
    int N; cin>>N;
    while(N--){
        int op; string name1; string name2;
        cin>>op>>name1>>name2;
        int num1 = slove(name1);
        int num2 = slove(name2);
        if(op==0){
            reunion(num1,num2);
        }else{
            if(issame(num1,num2)) cout<<"yes"<<endl;
            else cout<<"no"<<endl;
        }
    }
    return 0;
}
