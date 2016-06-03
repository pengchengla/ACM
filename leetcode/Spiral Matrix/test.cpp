/*===============================================================
*   Copyright (C) 2014 All rights reserved.
*   文件名称：test.cpp
*   创 建 者：pengcheng
*   创建日期：2014-11-27
*   描    述：
================================================================*/

#include<iostream>
#include<vector>
using namespace std;

struct node
{
    /**short m;
    short n;
    int a;**/
    vector<short> vec;
};
int main()
{
    cout<<sizeof(int)<<endl;
    cout<<sizeof(node)<<endl;
    vector< vector<int> > vec;
    cout<<vec.size()<<endl;
    cout<<vec[0].size()<<endl;
    
    return 0;
}
