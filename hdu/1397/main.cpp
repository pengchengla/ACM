/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-06-24
*   描    述：
================================================================*/

/*这道题是用筛去合数求素数效率要高点
  把输入放到后面是因为可能OJ计算时间的时候是从输入到输出
  这样等于提前把素数表都做好了，就只是输出了
*/
#include <iostream>
#include <math.h>
#include <string>
#define MAXN 2000000 + 10
using namespace std;

bool a[MAXN];
int main(){
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif
    int i;
    int k = 0;
    k = floor(sqrt(MAXN) + 0.5);
    //把从2到N的数组元素初始化;
    a[2] = true;
    for(i = 3; i <= MAXN; i++){
        if(i%2==0) a[i] = false;
        else a[i] = true;
    }
    //将合数筛去
    for(i = 3; i <= k; i+=2){
        if(a[i]){
            for(int j = 2*i;j <= MAXN; j+=i)
                a[j] = false;
        }
    }
    int N;
    while(cin>>N && N){
        //将素数输出
        cout<<"2 ";
        for(int l = 3; l <= N; l+=2){
            if( a[l] ) cout<<l<<" ";
        }
        cout<<endl;
    }
    return 0;
}
