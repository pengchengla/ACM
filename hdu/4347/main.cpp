#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define LL long long int
#define maxn 50080
#define K 5
int num,nownum,m;
LL ans;
struct kdNode
{
    LL x[K]; 
    int div;
    bool lef;
}Ans[12];

struct Node
{
    kdNode a;
    LL dis;//表示和目标点的距离
    bool operator < (const Node & a) const
    {
        return dis < a.dis;
    }
    Node(){}
    Node(kdNode & tmp,LL d)
    {
        a = tmp;
        dis = d;
    }
};

int cmpNo;
bool cmp(kdNode a,kdNode b)
{
    return a.x[cmpNo] < b.x[cmpNo];
}

inline LL max(LL a,LL b)
{
    return a>b?a:b;
}
kdNode p[maxn],q;

LL dis(kdNode a,kdNode b,int k)
{
    LL res = 0;
    for(int i = 0;i < k;i++)
        res += (a.x[i] - b.x[i])*(a.x[i] - b.x[i]);
    return res;
}

priority_queue <Node> qq;
void buildKD(int l,int r,kdNode * p,int d,int k)
{
    if(l > r)    return;
    int m = (l+r) >> 1;
    cmpNo = d;
    nth_element(p+l,p+m,p+r+1,cmp);
    p[m].div = d;
    if(l == r)    
    {
        p[m].lef = 1;
        return;
    }
    buildKD(l,m-1,p,(d+1)%k,k);
    buildKD(m+1,r,p,(d+1)%k,k);
}

void findKD(int l,int r,kdNode & tar,kdNode * p,int k)
{
    if(l>r)    return;
    int m = (l+r) >> 1;
    LL d = dis(p[m],tar,k);
    if(p[m].lef)//如果是叶子
    {
        if(nownum < num)    
        {
            nownum++;
            ans = max(ans,d);
            qq.push(Node(p[m],d));
        }
        else if(ans > d)
        {
            qq.pop();
            qq.push(Node(p[m],d));
            ans = qq.top().dis;
        }
        return;
    }
    LL t = tar.x[p[m].div] - p[m].x[p[m].div];
    if(t > 0)
    {
        findKD(m+1,r,tar,p,k);
        if(nownum < num)
        {
            qq.push(Node(p[m],d));
            nownum++;
            ans = qq.top().dis;
            findKD(l,m-1,tar,p,k);
        }
        else 
        {    
            if(ans > d)
            {
                qq.pop();
                qq.push(Node(p[m],d));
                ans = qq.top().dis;
            }
            if(ans > t*t)
                findKD(l,m-1,tar,p,k);
        }
    }
    else 
    {    
        findKD(l,m-1,tar,p,k);
        if(nownum < num)
        {
            qq.push(Node(p[m],d));
            nownum++;
            ans = qq.top().dis;
            findKD(m+1,r,tar,p,k);
        }
        else
        {
            if(ans > d)
            {
                qq.pop();
                qq.push(Node(p[m],d));
                ans = qq.top().dis;
            }
            if (ans > t*t)
                findKD(m+1,r,tar,p,k);
        }

    }
}

int main()
{
    //freopen("file.in","r",stdin);
    int n,k;
    while(scanf("%d%d",&n,&k)==2)
    {
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < k;j++)
            {
                scanf("%lld",&p[i].x[j]);
            }
            p[i].lef = 0;
        }
        int t;
        scanf("%d",&t);
        buildKD(0,n-1,p,k-1,k);
        for(int i = 1;i <= t;i++)
        {
            ans = -1;
            nownum = 0;
            for(int j = 0;j < k;j++)
                scanf("%lld",&q.x[j]);
            while(!qq.empty())        qq.pop();
            scanf("%d",&num);
            findKD(0,n-1,q,p,k);
            for(int j = 1;j <= num;j++)
            {
                Ans[j] = qq.top().a;
                qq.pop();
            }
            printf("the closest %d points are:\n",num);
            for(int j = num;j >= 1;j--)
            {
                for(int kk = 0;kk < k;kk++)
                {
                    if(kk == 0)
                        printf("%lld ",Ans[j].x[kk]);
                    else
                        printf("%lld ",Ans[j].x[kk]);
                }
                puts("");
            }
        }
    }
    return 0;
}
