/*===============================================================
*   Copyright (C) 2014 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2014-11-23
*   描    述：
================================================================*/

#include<iostream>
#include <stack>
using namespace std;

class MinStack
{
public:
    MinStack()
    {
        //data.clean();
        //mindata.clean();
    }
    void push(int x)
    {
        if(mindata.empty())
        {
            mindata.push(x);
        }
        else
        {
            if(x<=mindata.top())
                mindata.push(x);
        }
        data.push(x);
    }
    void pop()
    {
        if(mindata.top()==data.top())
        {
            mindata.pop();
        }
        data.pop();
    }
    int top()
    {
        return data.top();
    }
    int getMin()
    {
        return mindata.top();
    }
private:
    stack<int> data;
    stack<int> mindata;
};
int main()
{
    return 0;
}
