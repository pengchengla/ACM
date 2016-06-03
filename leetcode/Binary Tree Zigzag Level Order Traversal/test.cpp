/*===============================================================
*   Copyright (C) 2014 All rights reserved.
*   文件名称：test.cpp
*   创 建 者：pengcheng
*   创建日期：2014-11-29
*   描    述：
================================================================*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> ans;
    for(int i=0;i<10;++i)
        ans.push_back(i);
    for(vector<int>::iterator iter=ans.begin();iter!=ans.end();iter++)
        cout<<*iter<<endl;
    cout<<"==="<<endl;
    //reverse(ans.begin(),ans.end());
    ans.clear();
    for(vector<int>::iterator iter=ans.begin();iter!=ans.end();iter++)
        cout<<*iter<<endl;
    return 0;
}
