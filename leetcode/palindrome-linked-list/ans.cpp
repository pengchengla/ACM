/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-22
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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode * slow = head;
        ListNode * fast = head->next;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        ListNode * p = slow->next;
        slow->next = NULL;
        ListNode * pHead = reverse(p);

        bool flag = true;
        while(head && pHead){
            if(head->val!=pHead->val){
                flag = false;
                break;
            }
            head = head->next;
            pHead = pHead->next;
        }
        return flag;
    }
private:
    ListNode * reverse(ListNode * p){
        ListNode * head = NULL, * tail = NULL;
        while(p){
            ListNode * q = p;
            p = p->next;
            q->next = NULL;

            if(head==NULL){
                head = q;
            }else{
                q->next = head;
                head = q;
            }
        }
        return head;
    }
};

int main(){
    Solution * solution = new Solution();
    ListNode * head = NULL, * tail = NULL;
    /**for(int i=1;i<=11;i++){
        ListNode * tmp = new ListNode(i);
        if(head==NULL) {
            head = tmp;
            tail = head;
        }
        else{
            tail->next = tmp;
            tail = tmp;
        }
    }**/
    head = new ListNode(1);
    head->next = new ListNode(1);
    cout<<solution->isPalindrome(head)<<endl;
    return 0;
}
