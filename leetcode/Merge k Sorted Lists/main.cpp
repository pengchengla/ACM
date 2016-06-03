#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct NodeCmp
{
    bool operator()(ListNode * a,ListNode * b)
    {
        return a->val > b->val;
    }
};

class Solution 
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) 
    {
        ListNode * head=NULL;
        ListNode * curr=NULL;
        vector<ListNode*> vec;
        vec.clear();
        for(int i=0;i<lists.size();++i)
            if(lists[i]!=NULL)
                vec.push_back(lists[i]);
        make_heap(vec.begin(),vec.end(),NodeCmp());
        while(!vec.empty())
        {
            ListNode * min = vec.front();
            pop_heap(vec.begin(),vec.end(),NodeCmp());//交换和下沉
            vec.pop_back();

            if(head==NULL)  head=min;
            if(curr)  curr->next=min;
            curr=min;

            if(curr->next)
            {
                vec.push_back(curr->next);
                push_heap(vec.begin(),vec.end(),NodeCmp());
            }
        }
        return head;
    }
};

int main()
{
    return 0;
}
