#include <iostream>
using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) 
    {
        ListNode * front=head;
        ListNode * back=head;
        int cn=n;
        while(cn--)
        {
            if(front!=NULL) front=front->next;
            else return head;
        }
        if(front==NULL) return back->next;
        while(front->next!=NULL)
        {
            front=front->next;
            back=back->next;
        }
        ListNode * temp = back->next;
        back->next=temp->next;
        //temp
        return head;
    }
};

int main()
{
    ListNode * head=NULL;
    ListNode * tail=NULL;
    for(int i=0;i<10;++i)
    {
        if(head==NULL)
        {
            head=new ListNode(i);
            tail=head;
        }
        else
        {
            tail->next=new ListNode(i);
            tail=tail->next;
        }
    }
    Solution * solution = new Solution();
    ListNode * ans=solution->removeNthFromEnd(head,19);
    for(;ans!=NULL;ans=ans->next)
    {
        cout<<ans->val<<"  ";
    }
    cout<<endl;
    return 0;
}
