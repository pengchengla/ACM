/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-07
*   描    述：
================================================================*/
#include <iostream>
#include <vector>
using namespace std;

int main(){
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif
    int count=0;
    while(cin>>count){
        vector<int> elems;
        int tmp;
        for(int i=0;i<count;i++) {
            cin>>tmp;
            elems.push_back(tmp);
        }
        sort(elems.begin(),elems.end());
        cout<<elems[count/2]<<endl;
    }
    
    return 0;
}
