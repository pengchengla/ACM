/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-08
*   描    述：
================================================================*/
#include <iostream>
#include <stack>
using namespace std;

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        st1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if(!st2.empty()) {
            st2.pop();
            return;
        }
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        st2.pop();
    }

    // Get the front element.
    int peek(void) {
        if(!st2.empty()) return st2.top();
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        return st2.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
       if(st1.empty() && st2.empty()) return true;
       return false;
    }
private:
    stack<int> st1;
    stack<int> st2;
};

int main(){
    return 0;
}
