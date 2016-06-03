#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int node[3011111][2];
int tag,m,n,cas=0,T;
long long one[64],allone,tmp;
//0/1树的加数据操作，增加一个32的数
//其中如果当前位是0，则加左儿子，否则加右儿子，即这棵树中左儿子表示0，右儿子表示1
void add(long long temp) // l 0 r 1
{
    int rt=0,t;//rt为当前节点
    for(int i=31;i>=0; i--)
    {
        t=temp&one[i]?1:0;//取得当前位是0还是1
        if(node[rt][t]==-1)//如果没有对应的儿子，就增加给它分配一个数组的下标
            node[rt][t]=++tag;
        rt=node[rt][t];//迭代执行
    }
}

long long lookfor(long long temp)//查找答案
{
    int rt=0,t;
    long long ans=0;
    for(int i=31; i>=0; i--)
    {
        t=temp&one[i]?1:0;// temp&one[i] 1
        if(node[rt][t]==-1) t=t^1;//如果没有与当前符合的儿子，则选择相反的儿子，显然这个儿子一定存在
        rt=node[rt][t];//迭代当前节点
        ans=ans*2+t;//计算出查找的值
    }
    return ans;
}

int main()
{
    //freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
    one[0]=1;
    for(int i=1; i<60; i++)//得到2的幂次的数组
        one[i]=one[i-1]<<1;

    allone=one[32]-1;//0xffffffff 用来异或
    //printf("one  %I64d\n",allone);
    scanf("%d",&T);
    while(T--)
    {
        tag=0;//注意这个初始化，
        memset(node,-1,sizeof(node));
        scanf("%d%d",&m,&n);
        for(int i=0; i<m; i++)
        {
            scanf("%I64d",&tmp);
            add(tmp);
        }
        printf("Case #%d:\n",++cas);
        for(int i=0; i<n; i++)
        {
            scanf("%I64d",&tmp);//tmp为要查找的值
            tmp=tmp^allone;//tmp变成和原来的它异或值最大的数，而我们就是要查找，最接近它的一个数m，接近是，数值和二进制的形式接近
            printf("%I64d\n",lookfor(tmp));
        }
    }
    return 0;
}
