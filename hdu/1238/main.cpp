/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-08-07
*   描    述：
================================================================*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define LEN 103

int main(){
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif
    char str[LEN][LEN],s1[LEN],s2[LEN];
    int tc; scanf("%d",&tc);
    while(tc--){
        int n; scanf("%d",&n);
        int minlen=1000,minindex = 0;
        for(int i=0;i<n;i++){
            scanf("%s",str[i]);
            int len = strlen(str[i]);
            if(minlen>len){
                minlen = len;
                minindex = i;
            }
        }
        int flag = 1;
        int ans = 0,tmp = -1;
        for(int i=0;i<minlen;i++){
            for(int j=i;j<minlen;j++){
                for(int k=i;k<=j;k++){
                    s1[k-i] = str[minindex][k];
                    s2[j-k] = str[minindex][k];
                }
                s1[j-i+1] = '\0';
                s2[j-i+1] = '\0';
                for(int s=0;s<n;s++){
                    if(!strstr(str[s],s1) && !strstr(str[s],s2)){
                        flag = 0;
                        break;
                    }
                }
                int tans = strlen(s1);
                if(tans>ans && flag) ans = tans;
                flag = 1;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
