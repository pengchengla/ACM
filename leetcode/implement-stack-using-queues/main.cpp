/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-06-29
*   描    述：
================================================================*/
#include <iostream>
#include <queue>
using namespace std;

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        if(!qu2.empty()) qu2.push(x);
        else qu1.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        int size1 = qu1.size();
        for(int i=0;i<size1-1;i++){
            int f = qu1.front();
            qu1.pop();
            qu2.push(f);
        }
        if(size1>0){ qu1.pop(); return; }

        int size2 = qu2.size();
        for(int i=0;i<size2-1;i++){
            int f = qu2.front();
            qu2.pop();
            qu1.push(f);
        }
        qu2.pop();
    }

    // Get the top element.
    int top() {
        int ans = 0;
        int size1 = qu1.size();
        for(int i=0;i<size1;i++){
            int f = qu1.front();
            qu1.pop();
            qu2.push(f);
            ans = f;
        }
        if(size1>0) return ans;

        int size2 = qu2.size();
        for(int i=0;i<size2;i++){
            int f = qu2.front();
            qu2.pop();
            qu1.push(f);
            ans = f;
        }
        return ans;
    }

    // Return whether the stack is empty.
    bool empty() {
        return (qu1.empty() && qu2.empty());
    }
private:
    queue<int> qu1;
    queue<int> qu2;
};

int main(){
    return 0;
}
