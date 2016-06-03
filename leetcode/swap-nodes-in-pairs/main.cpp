/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-11
*   描    述：
================================================================*/
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode * p = head;
        ListNode * pre = head;
        while(p && p->next){
            ListNode * q = p->next;
            p->next = q->next;
            q->next = p;
            if(pre==head)   head = q;
            else pre->next = q;
            pre = p;
            p = p->next;
        }   
        return head;
    }   
};

int main(){
    return 0;
}
