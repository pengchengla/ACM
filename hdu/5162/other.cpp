#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <assert.h>
#include <time.h>
typedef long long LL;
const int INF = 500000001;
const double EPS = 1e-9;
const double PI = acos(-1.0);
using namespace std;
struct ak
{
    int val;
    int rk;
    int id;
}s[1000];
int cmp(const void *a, const void *b)
{
    struct ak c = *(struct ak *)a;
    struct ak d = *(struct ak *)b;
    return d.val - c.val;
}
int cmp1(const void *a, const void *b)
{
    struct ak c = *(struct ak *)a;
    struct ak d = *(struct ak *)b;
    return c.id - d.id;
}
int main()
{
    //#ifdef _1Test
        freopen("file", "r", stdin);
        //freopen("test0.out", "w", stdout);
        srand(time(NULL));
    //#endif
    int T;
    int n, a[1000];
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            s[i].val = 0;
            s[i].id = i;
            for(int j = 0; j < 3; j++)
            {
                int temp;
                scanf("%d", &temp);
                s[i].val = max(s[i].val, temp);
            }
        }
        qsort(s, n, sizeof(s[0]), cmp);
        for(int i = 0; i < n; i++)
        {
            s[i].rk = i+1;
        }
        qsort(s, n, sizeof(s[0]), cmp1);
        for(int i = 0; i < n; i++)
        {
            printf(i?" %d":"%d", s[i].rk);
        }
        puts("");
    }
    return 0;
}
