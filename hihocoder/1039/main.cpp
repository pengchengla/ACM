/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-06-26
*   描    述：
================================================================*/

#include <iostream>
#include <cstring>
using namespace std;

int getscore(char * d){
    int score = 0;
    bool over = false;
    while(!over){
        int i=0;
        int j=0;
        over=true;
        while(d[j]){
            if(d[j]==d[j+1]){
                char ch = d[j];
                while(d[j]==ch){
                    j++;
                    score++;
                }
                over=false;
            }else{
                d[i++] = d[j++];
            }
        }
        d[i] = 0;
    }
    return score;
}

int main(){
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif
    int n;
    cin>>n;
    while(n--){
        char t[128]={0};
        char d[128]={0};
        
        cin>>t;
        int len = strlen(t);
        int score = 0;
        for(int i=0;i<=len;i++){
            for(int j=0;j<3;j++){
                memcpy(d,t,i);
                memcpy(d+i+1,t+i,len-i);
                char ch = 'A' + j;
                d[i]=ch;
                d[len+1]=0;
                score = max(score,getscore(d));
            }
        }
        cout<<score<<endl;
    }
    return 0;
}
