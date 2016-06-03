/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：ans.cpp
*   创 建 者：pengcheng
*   创建日期：2015-08-06
*   描    述：
================================================================*/
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cctype>
#include <map>
using namespace std;

int main(){
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif
    char buf[12], s1[12], s2[12], ch;
    map<string, string> mp;
    int id = 0;
    gets(buf); //strip START
    while(scanf("%s%s", s1, s2), strcmp(s1, "END")){
        mp[s2] = s1;
    }
    getchar();
    while(scanf("%c", &ch)){
        if(isalpha(ch)) buf[id++] = ch;
        else{
            buf[id] = '\0'; id = 0;
            if(strcmp(buf, "END") == 0) break;
            if(mp.find(buf) != mp.end()){
                cout << mp[buf];
            }else printf("%s", buf);
            putchar(ch);
        }
    }
    return 0;
}
