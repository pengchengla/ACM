/*===============================================================
*   Copyright (C) 2014 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2014-11-27
*   描    述：
================================================================*/

#include <iostream>
using namespace std;

class Solution 
{
public:
    int removeElement(int A[], int n, int elem) 
    {
        int front = 0;
        int back = n-1;
        while(front<=back)
        {
            while(front<=back && A[front]!=elem) front++;
            while(front<=back && A[back]==elem)  back--;
            if(back==-1)    return 0;
            if(front<back)
            {
                A[front]=A[back];
                back--;
                front++;
            }
        }
        return back+1;
    }
};
int main()
{
    int A[1];
    A[0]=1;
    Solution * solution = new Solution();
    cout<<solution->removeElement(A,1,1)<<endl;
    return 0;
}
