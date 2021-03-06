#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int K = 6;
const int N = 55555;
const int maxkind = 5;
int dm, cdm;
template<class T> T sqr(T x) { return x * x;}
int kinds[maxkind];

struct Node 
{
    int x[K];
    Node *c[2];
    int kind;
    bool operator < (Node a) const 
    {
        for (int i = 0; i < dm; i++) 
            if (x[(cdm + i) % dm] != a.x[(cdm + i) % dm]) 
                return x[(cdm + i) % dm] < a.x[(cdm + i) % dm];
        return true;
    }
} node[N];

int dist(Node *a, Node *b) 
{
    int ret = 0;
    for (int i = 0; i < dm; i++) 
        ret += sqr(a->x[i] - b->x[i]);
    return ret;
}

struct KDT 
{
    Node *knn[15];
    int top, dis[15], sz;
    Node *RT;

    void build(int l, int r, int dp, Node *&rt) 
    {
        cdm = dp % dm;
        if (l > r) { rt = NULL; return ;}
        int m = (l + r) >> 1;
        nth_element(node + l, node + m, node + r + 1);
        rt = node + m;
        build(l, m - 1, dp + 1, rt->c[0]);
        build(m + 1, r, dp + 1, rt->c[1]);
    }

    void build(int l, int r) 
    {
        sz = r - l + 1;
        build(l, r, 0, RT);
    }

    void search(int dp, Node *x, Node *rt, int k) 
    {
        if (!rt) return ;
        cdm = dp % dm;
        int d = dist(x, rt), p = top;
        while (p >= 0 && d < dis[p]) 
            dis[p + 1] = dis[p], knn[p + 1] = knn[p], p--;
        p++;
        dis[p] = d;
        knn[p] = rt;
        if (top + 1 < k) 
            top++;
        bool r = x->x[cdm] >= rt->x[cdm];
        search(dp + 1, x, rt->c[r], k);
        if (top + 1 < k || sqr(rt->x[cdm] - x->x[cdm]) < dis[top]) 
            search(dp + 1, x, rt->c[!r], k);
    }

    void search(Node *x, int k) 
    {
        top = -1;
        search(0, x, RT, k);
    }

} kdt;

int main() 
{
    freopen("file.in","r",stdin);
    for(int i=0;i<maxkind;i++)  kinds[i]=0;
    int n, m, k;
    Node tmp;
    while (~scanf("%d%d", &n, &dm)) 
    {
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < dm; j++) 
                scanf("%d", node[i].x + j);
            scanf("%d", &node[i].kind);
            node[i].c[0] = node[i].c[1] = NULL;
        }
        kdt.build(0, n - 1);
        scanf("%d", &m);
        while (m--) 
        {
            for (int i = 0; i < dm; i++) 
                scanf("%d", tmp.x + i);
            scanf("%d", &k);
            kdt.search(&tmp, k);
            printf("the closest %d points are:\n", k);
            for (int i = 0; i <= kdt.top; i++) 
            {
                kinds[kdt.knn[i]->kind]++;
                for (int j = 0; j < dm; j++) 
                {
                    if (j) 
                        putchar(' ');
                    printf("%d", kdt.knn[i]->x[j]);
                }
                puts("");
            }
            int ki=0;
            int mm=0;
            for(int i=0;i<maxkind;i++)
                if(kinds[i]>mm)
                {
                    mm=kinds[i];
                    ki=i;
                }
            printf("kind=%d",ki);
            puts("");
        }
    }
    return 0;
}
