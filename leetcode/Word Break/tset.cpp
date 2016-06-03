/*===============================================================
*   Copyright (C) 2014 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2014-11-30
*   描    述：
================================================================*/

#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

int main()
{
    string str[] = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    unordered_set<string> dict;
    for(int i=0;i<10;++i)
    {
        dict.insert(str[i]);
    }
    unordered_set<string>::iterator iter = dict.begin();
    for(;iter!=dict.end();iter++)
    {
        cout<<*iter<<endl;
    }
    return 0;
}
