#include <iostream>
#include <string>
using namespace std;

const int charcount=26;
struct node
{
    int count;//word end count
    struct node * next[charcount];
    node()
    {
        count=0;
        for(int i=0;i<charcount;i++)
            next[i] = NULL;
    }
};

void create(struct node * &root,string & str,int pos)
{
    if(pos==str.size())
    {
        root->count+=1;
        cout<<"count="<<root->count<<endl;
        return;
    }
    if(root->next[str[pos]-'a']==NULL)
        root->next[str[pos]-'a'] = new struct node;
    create(root->next[str[pos]-'a'],str,pos+1);
}

void calans(struct node * &root,int pos,int &ans)
{
    if(root==NULL) return;
    ans+=root->count;
    for(int i=pos;i<charcount;i++)
    {
        if(root->next[i]!=NULL)
        {
            calans(root->next[i],i,ans);
        }
    }
}

void getans(struct node * &root,string & str,int pos,int &ans)
{
    if(root==NULL)
    {
        ans = 0;
        return;
    }
    if(pos==str.size())
    {
        ans+=root->count;
        calans(root,0,ans);
        return;
    }
    getans(root->next[str[pos]-'a'],str,pos+1,ans);
}

int main()
{
    freopen("file","r",stdin);
    int input;
    cin>>input;
    struct node * root = new struct node;
    while(input--)
    {
        string str;
        cin>>str;
        cout<<str<<endl;
        create(root,str,0);
        cout<<endl;
    }
    cin>>input;
    while(input--)
    {
        string str;
        cin>>str;
        int ans=0;
        getans(root,str,0,ans);
        cout<<"ans="<<ans<<endl;
    }
    return 0;
}
