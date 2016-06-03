#include <iostream>
using namespace std;

struct node
{
    int left;
    int right;
};

void getans(struct node * nodes,int count)
{
    for(int i=0;i<count;i++)
    {
        int leftcount=0,rightcount=0;
        cin>>nodes[i].left>>nodes[i].right;
        while(nodes[i].left!=1 || nodes[i].right!=1)
        {
            if(nodes[i].left==1)
            {
                rightcount+=(nodes[i].right-1);
                break;
            }
            if(nodes[i].right==1)
            {
                leftcount+=(nodes[i].left-1);
                break;
            }
            if(nodes[i].left > nodes[i].right)
            {
                int mul = nodes[i].left / nodes[i].right;
                nodes[i].left-=(nodes[i].right*mul);
                leftcount+=mul;
            }
            else
            {
                int mul = nodes[i].right / nodes[i].left;
                nodes[i].right-=(nodes[i].left*mul);
                rightcount+=mul;
            }
        }
        cout<<"Scenario #"<<i+1<<":"<<endl;
        cout<<leftcount<<" "<<rightcount<<endl<<endl;
    }
}

int main()
{
    freopen("file","r",stdin);
    int count;
    cin>>count;
    struct node * nodes = new node[count];
    getans(nodes,count);
    return 0;
}
