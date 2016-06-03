/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*   文件名称：main.cpp
*   创 建 者：pengcheng
*   创建日期：2015-07-12
*   描    述：
================================================================*/
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool cmp(const ListNode & * a, const ListNode & * b){
    if(a->val > b->val) return true;
    return false;
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode * head, *tail;
        bool flag = true;
        while(lists.size()!=0){
            int s = lists.size();
            sort(lists.begin(),lists.end(),cmp);
            if(head==NULL){
                head = lists[s-1];
                tail = head;
            }else{
                tail->next = lists[s-1];
                tail = tail->next;
            }
            ListNode * p = lists[s-1];
            if(p->next) lists[s-1] = p->next;
            else lists.pop_back();
        }
    }
};

int main(){
    return 0;
}
