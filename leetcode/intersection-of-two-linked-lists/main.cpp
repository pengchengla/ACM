#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
private:
    int getlen(ListNode * head)
    {
        int len = 0;
        while(head!=NULL)
        {
            len++;
            head = head->next;
        }
        return len;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        int lenA = getlen(headA);
        int lenB = getlen(headB);
        if(lenA>lenB)
        {
            int diff = lenA-lenB;
            while(diff--)   headA = headA->next;
        }
        else
        {
            int diff = lenB-lenA;
            while(diff--)   headB = headB->next;
        }
        while(headA!=headB)
        {
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
};

int main()
{
    return 0;
}
