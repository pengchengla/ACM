/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-03
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
    ListNode* removeElements(ListNode* head, int val) {
        while(head && head->val==val) head=head->next;
        if(!head) return head;
        ListNode * pNode = head;
        ListNode * qNode = head->next;
        while(qNode){
            if(qNode->val == val){
                pNode->next = qNode->next;
                qNode = qNode->next;
                continue;
            }
            pNode = pNode->next;
            qNode = qNode->next;
        }
        return head;
    }
};


int main(){
    Solution * solution = new Solution();
    ListNode * head = new ListNode(1);
    ListNode * ans = solution->removeElements(head,1);
    while(ans){
        cout<<ans->val<<endl;
        ans=ans->next;
    }
    return 0;
}
