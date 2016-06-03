/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-07
*   描    述：
================================================================*/
#include <iostream>
#include <map>
using namespace std;

int main(){
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif
    int count=0;
    while(cin>>count){
        int maxcount = 0;
        int maxnum = 0;
        int tmp = 0;
        map<int,int> hmap;
        for(int i=0;i<count;i++){
            cin>>tmp;
            if(hmap.find(tmp)!=hmap.end()){
                hmap[tmp]++;
            }else{
                hmap.insert(pair<int,int>(tmp,1));
            }
            if(hmap[tmp]>maxcount){
                maxcount=hmap[tmp];
                maxnum=tmp;
            }
        }
        cout<<maxnum<<endl;
    }
    
    return 0;
}
