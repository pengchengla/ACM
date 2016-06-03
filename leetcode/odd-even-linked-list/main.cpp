#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
		if(!head || !head->next || !head->next->next) return head;
		ListNode * odd = head;
		ListNode * even = head->next;
		ListNode * tmp = even;
		while(odd || even)
		{
			odd->next = odd->next->next;
			even->next = even->next->next;

			odd = odd->next;
			even = even->next;

			if(!odd->next || !odd->next->next)break;
		}
		odd->next = tmp;
		return head;
    }
};

void scan(ListNode * head)
{
	ListNode * p = head;
	while(p)
	{
		cout<<p->val<<"  ";
		p = p->next;
	}
	cout<<endl;
}

int main(){
	ListNode * head = NULL;
	for(int i=4;i>0;--i)
	{
		ListNode * p = new ListNode(i);
		p->next = head;
		head = p;
	}
	scan(head);
	Solution * solution = new Solution();
	head = solution->oddEvenList(head);
	scan(head);
	return 0;
}
