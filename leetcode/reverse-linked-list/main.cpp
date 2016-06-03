/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-06-26
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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return head;
        ListNode * ans = head;
        ListNode * pNode = head->next;
        ans->next = NULL;
        while(pNode){
            ListNode * tmp = pNode;
            pNode = pNode->next;
            tmp->next = ans;
            ans = tmp;
        }
        return ans;
    }
};

int main(){
    return 0;
}
