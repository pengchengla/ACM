/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-29
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * ans = head;
        ListNode * newHead = head;
        ListNode * newTail = NULL;
        ListNode * nextSec = head;
        ListNode * preTail = NULL;
        while(nextSec){
            newTail = nextSec;
            ListNode * p = nextSec;
            int s = 0;
            for(s=0;s<k && nextSec; s++) nextSec = nextSec->next;
            if(s<k) break;
            ListNode * tmp = nextSec;
            ListNode * np = p->next;
            for(int i=0;i<k;i++){
                p->next = tmp;
                tmp = p;
                p = np;
                if(np) np = np->next;
            }
            newHead = tmp;
            newTail->next = nextSec;
            if(ans==head) ans = newHead;
            if(preTail) preTail->next = newHead;
            preTail = newTail;
        }
        return ans;
    }
};

int main(){
    ListNode * head = NULL;
    ListNode * tmp = NULL;
    for(int i=2;i>0;i--){
        tmp = new ListNode(i);
        if(head==NULL){
            head = tmp;
        }else{
            tmp->next = head;
            head = tmp;
        }
    }
    Solution * solution = new Solution();
    ListNode * ans = solution->reverseKGroup(head,1);
    cout<<"------------------"<<endl;
    while(ans){
        cout<<ans->val<<endl;
        ans = ans->next;
    }
    return 0;
}
