/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-06-19
*   描    述：
================================================================*/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#define M 5000024

int total[50];
int f[M]={0};

int max(int a, int b){
    if(a>b) return a;
    return b;
}

int main(){
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif
    cout<<setiosflags(ios::fixed)<<setprecision(2);
    int k = 0;
    float vv; int line;
    int kind;
    while(cin>>vv>>line && line){
        k=0;
        memset(total,0,sizeof(total));
        memset(f,0,sizeof(f));
        int value = (vv)*100;
        //check and push
        for(int i=0;i<line;i++){
            cin>>kind;
            string str;
            int tmp=0;
            bool flag = true;
            int xa=0,xb=0,xc=0;
            for(int j=0;j<kind;j++){
                cin>>str;
                char ch = str[0];
                if(ch!='A'&&ch!='B'&&ch!='C') {flag = false;break;}
                string sub = str.substr(2,str.length());
                int t = atof(sub.c_str()) * 100;
                if(ch=='A') xa+=t;
                else if(ch=='B') xb+=t;
                else if(ch=='C') xc+=t;
                if(t>60000 || xa>60000 || xb>60000 || xc>60000) {flag = false;break;}
                tmp+=t;
            }
            if(tmp>100000) flag = false;
            if(flag) total[k++] = tmp;
        }
        for(int i=0;i<k;i++){
            for(int v=value;v>=total[i];v--){
                f[v] = max(f[v],f[v-total[i]]+total[i]);
            }
        }
        cout<<f[(int)value]/100.0<<endl;
    }
    return 0;
}
