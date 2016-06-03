#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool static nodeCmp(ListNode *a, ListNode *b) {
        return a->val > b->val;
    }   

    ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode * head=NULL;
		ListNode * tail=NULL;
		vector<ListNode *> heap;
		for(int i=0;i<lists.size();i++)
            if(lists[i]!=NULL)
                heap.push_back(lists[i]);
		make_heap(heap.begin(),heap.end(),nodeCmp);
		while(!heap.empty()){
			ListNode * min = heap.front();
			pop_heap(heap.begin(),heap.end(),nodeCmp);
			heap.pop_back();
			if(!head) head=min;
			else tail->next=min;
			tail=min;
			if(tail->next){
				heap.push_back(tail->next);
				push_heap(heap.begin(),heap.end(),nodeCmp);
			}
		}
		return head;
    }
};

int main(){
	return 0;
}
