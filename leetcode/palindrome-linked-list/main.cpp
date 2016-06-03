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
    int isPalindrome(ListNode* head) {
        ListNode * ans = head;
        ListNode * pre = head;
        ListNode * last = head;
        while(last && pre){
            ans = last;
            last = last->next;
            if(!pre->next) break;
            pre = pre->next->next;
        }
        return ans->val;
    }
};

int main(){
    Solution * solution = new Solution();
    ListNode * head = NULL, * tail = NULL;
    for(int i=1;i<=5;i++){
        ListNode * tmp = new ListNode(i);
        if(head==NULL) {
            head = tmp;
            tail = head;
        }
        else{
            tail->next = tmp;
            tail = tmp;
        }
    }
    cout<<solution->isPalindrome(head)<<endl;
    return 0;
}
