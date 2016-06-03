/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-06-22
*   描    述：
================================================================*/
#include <iostream>
#include <math.h>
using namespace std;

int main(){
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif
    double x1,y1,x2,y2;
    while(cin>>x1>>y1>>x2>>y2){
        double ans = 0;
        double x = x1-x2;
        double y = y1-y2;
        ans = sqrt(x*x + y*y);
        printf("%.2lf\n",ans);
    }
    return 0;
}
