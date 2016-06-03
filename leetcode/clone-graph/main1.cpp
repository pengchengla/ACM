#include <iostream>
#include <map>
using namespace std;

struct UndirectedGraphNode 
{
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution 
{
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) 
    {
        if(!node) return NULL;
        map<int,UndirectedGraphNode *> mmap;
        return clone(node,mmap);
    }
private:
    UndirectedGraphNode * clone(UndirectedGraphNode * node, map<int,UndirectedGraphNode *> &mmap)
    {
        if(mmap[node->label]) return mmap[node->label];
        UndirectedGraphNode * ans = new UndirectedGraphNode(node->label);
        mmap[node->label] = ans;
        for(int i=0;i<node->neighbors.size();i++)
        {
            (ans->neighbors).push_back(clone((node->neighbors)[i],mmap));
        }
        return ans;
    }
};

int main()
{
    return 0;
}
