/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：ans.cpp
*   创 建 者：pengcheng
*   创建日期：2015-06-26
*   描    述：
================================================================*/
#include <cstdio>  
#include <cstring>  
#include <string.h>  
char str[1000002 + 1200];  
  
int fast(char *p)  
{  
    int ans = 1;  
    for (int i = 1; p[i]; ++i)  
    {  
        int s = i, e = i, t;  
        while (p[e + 1] == p[i]) ++e;  
        i = e;  
        while (p[s - 1] == p[e + 1]) --s, ++e;  
        if ((t = e - s + 1) > ans) ans = t;  
    }  
    return ans;  
}  

int main()  
{  
    str[0]='$';  
    int n;  
    scanf("%d", &n);  
    while (n --) {  
        scanf("%s", str + 1);  
        printf("%d\n", fast(str));  
    }  
    return 0;  
}
